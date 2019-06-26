﻿#include "svmtrainner.h"
#include "ui_svmtrainner.h"

#include <iostream>

SVMTrainner::SVMTrainner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SVMTrainner)
{
    ui->setupUi(this);
    this->ui->plateSampleImfo->hide();
}

SVMTrainner::~SVMTrainner()
{
    delete ui;
}

//计算相似度
float SVMTrainner::computeSimilarity(QString matPath1, QString matPath2)
{
    cv::Mat mat1 = cv::imread(matPath1.toLocal8Bit().toStdString());
    cv::Mat mat2 = cv::imread(matPath2.toLocal8Bit().toStdString());

    if(mat1.empty() || mat2.empty())
        return 0.0;

    cv::cvtColor(mat1, mat1, cv::COLOR_BGR2GRAY);
    cv::resize(mat1, mat1, HOGWinSize);
    std::vector<float> vector1;
    hog->compute(mat1, vector1, HOGBlockStride, cv::Size(0,0));

    cv::cvtColor(mat2, mat2, cv::COLOR_BGR2GRAY);
    cv::resize(mat2, mat2, HOGWinSize);
    std::vector<float> vector2;
    hog->compute(mat2, vector2, HOGBlockStride, cv::Size(0,0));

    int i = 0;
    int n = vector1.size();
    float sum = 0.0f;
    for (i = 0; i<n; ++i)
        sum += vector1[i] * vector1[i];
    float vecM1 = sqrt(sum);

    n = vector2.size();
    sum = 0.0f;
    for (i = 0; i<n; ++i)
        sum += vector2[i] * vector2[i];
    float vecM2 = sqrt(sum);

    sum = 0.0f;
    for (i = 0; i<n; ++i)
        sum += vector1[i] * vector2[i];
    float dis = sum / (vecM1*vecM2);

    return dis;
}

//HOG可视化
cv::Mat SVMTrainner::getHogdescriptorVisualImage(cv::Mat &origImg, std::vector<float> &descriptorValues, cv::Size winSize, cv::Size cellSize, int scaleFactor, double viz_factor)
{
    cv::Mat visual_image;
    cv::resize(origImg, visual_image, cv::Size(origImg.cols*scaleFactor, origImg.rows*scaleFactor));

    int gradientBinSize = 9;
    // dividing 180° into 9 bins, how large (in rad) is one bin?
    float radRangeForOneBin = 3.14/(float)gradientBinSize;

    // prepare data structure: 9 orientation / gradient strenghts for each cell
    int cells_in_x_dir = winSize.width / cellSize.width;
    int cells_in_y_dir = winSize.height / cellSize.height;
    int totalnrofcells = cells_in_x_dir * cells_in_y_dir;
    float*** gradientStrengths = new float**[cells_in_y_dir];
    int** cellUpdateCounter   = new int*[cells_in_y_dir];
    for (int y=0; y<cells_in_y_dir; y++)
    {
        gradientStrengths[y] = new float*[cells_in_x_dir];
        cellUpdateCounter[y] = new int[cells_in_x_dir];
        for (int x=0; x<cells_in_x_dir; x++)
        {
            gradientStrengths[y][x] = new float[gradientBinSize];
            cellUpdateCounter[y][x] = 0;

            for (int bin=0; bin<gradientBinSize; bin++)
                gradientStrengths[y][x][bin] = 0.0;
        }
    }

    // nr of blocks = nr of cells - 1
    // since there is a new block on each cell (overlapping blocks!) but the last one
    int blocks_in_x_dir = cells_in_x_dir - 1;
    int blocks_in_y_dir = cells_in_y_dir - 1;

    // compute gradient strengths per cell
    int descriptorDataIdx = 0;
    int cellx = 0;
    int celly = 0;

    for (int blockx=0; blockx<blocks_in_x_dir; blockx++)
    {
        for (int blocky=0; blocky<blocks_in_y_dir; blocky++)
        {
            // 4 cells per block ...
            for (int cellNr=0; cellNr<4; cellNr++)
            {
                // compute corresponding cell nr
                int cellx = blockx;
                int celly = blocky;
                if (cellNr==1) celly++;
                if (cellNr==2) cellx++;
                if (cellNr==3)
                {
                    cellx++;
                    celly++;
                }
                for (int bin=0; bin<gradientBinSize; bin++)
                {
                    float gradientStrength = descriptorValues[ descriptorDataIdx ];
                    descriptorDataIdx++;
                    gradientStrengths[celly][cellx][bin] += gradientStrength;
                } // for (all bins)
                // note: overlapping blocks lead to multiple updates of this sum!
                // we therefore keep track how often a cell was updated,
                // to compute average gradient strengths
                cellUpdateCounter[celly][cellx]++;
            } // for (all cells)
        } // for (all block x pos)
    } // for (all block y pos)


    // compute average gradient strengths
    for (int celly=0; celly<cells_in_y_dir; celly++)
    {
        for (int cellx=0; cellx<cells_in_x_dir; cellx++)
        {

            float NrUpdatesForThisCell = (float)cellUpdateCounter[celly][cellx];

            // compute average gradient strenghts for each gradient bin direction
            for (int bin=0; bin<gradientBinSize; bin++)
            {
                gradientStrengths[celly][cellx][bin] /= NrUpdatesForThisCell;
            }
        }
    }
    // draw cells
    for (int celly=0; celly<cells_in_y_dir; celly++)
    {
        for (int cellx=0; cellx<cells_in_x_dir; cellx++)
        {
            int drawX = cellx * cellSize.width;
            int drawY = celly * cellSize.height;

            int mx = drawX + cellSize.width/2;
            int my = drawY + cellSize.height/2;

            rectangle(visual_image,
                cv::Point(drawX*scaleFactor,drawY*scaleFactor),
                cv::Point((drawX+cellSize.width)*scaleFactor,
                (drawY+cellSize.height)*scaleFactor),
                CV_RGB(100,100,100),
                1);

            // draw in each cell all 9 gradient strengths
            for (int bin=0; bin<gradientBinSize; bin++)
            {
                float currentGradStrength = gradientStrengths[celly][cellx][bin];

                // no line to draw?
                if (currentGradStrength==0)
                    continue;

                float currRad = bin * radRangeForOneBin + radRangeForOneBin/2;

                float dirVecX = cos( currRad );
                float dirVecY = sin( currRad );
                float maxVecLen = cellSize.width/2;
                float scale = viz_factor; // just a visual_imagealization scale,
                // to see the lines better

                // compute line coordinates
                float x1 = mx - dirVecX * currentGradStrength * maxVecLen * scale;
                float y1 = my - dirVecY * currentGradStrength * maxVecLen * scale;
                float x2 = mx + dirVecX * currentGradStrength * maxVecLen * scale;
                float y2 = my + dirVecY * currentGradStrength * maxVecLen * scale;

                // draw gradient visual_imagealization
                line(visual_image,
                    cv::Point(x1*scaleFactor,y1*scaleFactor),
                    cv::Point(x2*scaleFactor,y2*scaleFactor),
                    CV_RGB(0,0,255),
                    1);

            } // for (all bins)

        } // for (cellx)
    } // for (celly)


    // don't forget to free memory allocated by helper data structures!
    for (int y=0; y<cells_in_y_dir; y++)
    {
        for (int x=0; x<cells_in_x_dir; x++)
        {
            delete[] gradientStrengths[y][x];
        }
        delete[] gradientStrengths[y];
        delete[] cellUpdateCounter[y];
    }
    delete[] gradientStrengths;
    delete[] cellUpdateCounter;

    return visual_image;
}

QImage SVMTrainner::Mat2QImage(cv::Mat mat, QImage::Format format)
{
    cv::Mat temp = mat.clone();
    if(temp.channels() == 3) cv::cvtColor(temp,temp,cv::COLOR_BGR2RGB);
    QImage image = QImage((const unsigned char*)(temp.data),
                                  temp.cols,
                                  temp.rows,
                                  temp.cols * temp.channels(),
                                  format).copy();
    temp.release();
    return image;
}

//刷新训练库
void SVMTrainner::refreshPlateSampleTree()
{
    this->ui->plateSampleTree->clear();
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateSampleImfo->hide();

    this->sum = 0;

    int k, i;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0; k < PlateCategoryString.size(); k++)
    {
        sum += plateTrainImgFileNames[k].size();
        tempGroup = new QTreeWidgetItem(this->ui->plateSampleTree);
        tempGroup->setText(0, PlateCategoryString[k] + "(" + QString::number(plateTrainImgFileNames[k].size()) + ")");
        for(i = 0; i < plateTrainImgFileNames[k].size(); i++)
        {
            tempSample = new QTreeWidgetItem(tempGroup);
            tempSample->setText(0, plateTrainImgFileNames[k].at(i));
            tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i));
        }
    }

    std::cout<<sum<<std::endl;
}

void SVMTrainner::on_platePropertyButton_clicked()
{
    PlateProperty *pp = new PlateProperty;

    pp->show();
}

//加载训练库
void SVMTrainner::on_loadPlateSetButton_clicked()
{
    this->ui->plateSampleTree->clear();
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();

    int i, j, k;

    if(!Property::plateTrainPathDefault)
    {
        Property::plateTrainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTrainPath);
        if(Property::plateTrainPath.isEmpty()) return;
    }
    if(!PlateCategory_SVM::PreparePlateTrainningDirectory(Property::plateTrainPath))
    {
        QMessageBox::about(NULL, "Warning!", "训练库装载失败!");
        return;
    }

    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp";
    for(i = 0; i < PlateCategoryString.size(); i++) //只做非车牌与普通车牌的识别
    {
        plateTrainDirs.insert(i, new QDir(Property::plateTrainPath + "\\plates\\" + PlateCategoryString[i]));
        plateTrainImgFileNames.insert(i, plateTrainDirs[i]->entryList(nameFilters));
    }

    //比较相似度
    float dis;
    if(Property::similarityCheck)
    {
        for(k = 0; k < PlateCategoryString.size(); k++)
        {
            for(i = 0; i < plateTrainImgFileNames[k].size() - 1; i++)
                for(j = i + 1; j < plateTrainImgFileNames[k].size(); j++)
                {
                    dis = computeSimilarity(plateTrainDirs[k]->path() + "\\" + plateTrainImgFileNames[k].at(i), plateTrainDirs[k]->path() + "\\" + plateTrainImgFileNames[k].at(j));
                    std::cout<<"computing"<<k<<"  "<<i<<"  "<<j<<" distance:"<<dis<<std::endl;
                    if(dis > Property::thresholdForSimilarity[k])
                    {
                        plateTrainImgFileNames[k].removeAt(j);
                        j--;
                    }
                }
        }
    }

    refreshPlateSampleTree();
}

//点击查看样本
void SVMTrainner::on_plateSampleTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();

    if(item->childCount() != 0)
    {
        this->ui->plateSampleImfo->hide();
        return;
    }

    this->ui->plateSampleImfo->show();
    this->ui->plateSampleName->setText(item->text(0));

    cv::Mat originalMat = cv::imread(plateTrainDirs[item->whatsThis(0).section(".",0,0).toInt()]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);
    this->ui->plateSampleSize->setText(QString::number(originalMat.cols) + " x " + QString::number(originalMat.rows));

    cv::Mat resizedMat;
    cv::resize(originalMat, resizedMat, cv::Size(this->ui->plateOriginalLabel->size().width(), this->ui->plateOriginalLabel->size().height()));

    QImage image = Mat2QImage(resizedMat,QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(image);
    this->ui->plateOriginalLabel->setPixmap(pixmap);

    cv::resize(originalMat, resizedMat, PlateCategory_SVM::HOGWinSize);
    std::vector<float> descriptor = PlateCategory_SVM::ComputeHogDescriptors(resizedMat);
    this->ui->plateHogSize->setText(QString::number(descriptor.size()));

    cv::Mat hogMat = getHogdescriptorVisualImage(resizedMat, descriptor, PlateCategory_SVM::HOGWinSize, PlateCategory_SVM::HOGCellSize, 1, 2.0);

    cv::resize(hogMat, hogMat, cv::Size(this->ui->plateHogLabel->size().width(), this->ui->plateHogLabel->size().height()));
    image = Mat2QImage(hogMat,QImage::Format_Grayscale8);
    pixmap = QPixmap::fromImage(image);
    this->ui->plateHogLabel->setPixmap(pixmap);

    this->ui->plateSampleLabelCombo->setCurrentIndex(item->whatsThis(0).section(".", 0, 0).toInt());
}

//开始车牌训练
void SVMTrainner::on_plateTrainButton_clicked()
{

}

//更改训练集样本标签
void SVMTrainner::on_plateSampleChangeButton_clicked()
{
    if(this->ui->plateSampleLabelCombo->currentIndex() == this->ui->plateSampleTree->currentItem()->whatsThis(0).section(".",0 ,0).toInt()) return;

    QMessageBox:: StandardButton result= QMessageBox::information(NULL, "Make Sure", "确认要更改标签吗?",QMessageBox::Yes|QMessageBox::No);
    switch (result)
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        return;
    default:
        break;
    }

    QTreeWidgetItem *temp = this->ui->plateSampleTree->currentItem();
    int formerLabel = temp->whatsThis(0).section(".",0 ,0).toInt();
    int newLabel = this->ui->plateSampleLabelCombo->currentIndex();
    int formerIndex = temp->whatsThis(0).section(".",1 ,1).toInt();

    if(QFile::exists(plateTrainDirs[newLabel]->path() +  temp->text(0)))
    {
        QFile file(plateTrainDirs[formerLabel]->path() + temp->text(0));
        temp->setText(0, temp->text(0) + "(1)");
        if(!file.rename(temp->text(0))) return;
    }
    QFile::copy(plateTrainDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[newLabel]->path() + "\\" + temp->text(0));
    QFile::remove(plateTrainDirs[formerLabel]->path() + "\\" + temp->text(0));

    plateTrainImgFileNames[formerLabel].removeAt(formerIndex);
    plateTrainImgFileNames[newLabel].insert(plateTrainImgFileNames[newLabel].size(), temp->text(0));

    refreshPlateSampleTree();
}

//删除训练集样本
void SVMTrainner::on_plateSampleDeleteButton_clicked()
{
    bool deleteLocal = false;

    QMessageBox:: StandardButton result= QMessageBox::information(NULL, "Make Sure", "确认删除?",QMessageBox::Yes|QMessageBox::No);
    switch (result)
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        return;
    default:
        break;
    }

    result= QMessageBox::information(NULL, "Make Sure", "是否删除本地文件?",QMessageBox::Yes|QMessageBox::No);
    switch (result)
    {
    case QMessageBox::Yes:
        deleteLocal = true;
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }

    QTreeWidgetItem *temp = this->ui->plateSampleTree->currentItem();
    int label = temp->whatsThis(0).section(".", 0, 0).toInt();
    int index = temp->whatsThis(0).section(".", 1, 1).toInt();

    plateTrainImgFileNames[label].removeAt(index);

    if(deleteLocal)
    {
        QFile::remove(plateTrainDirs[label]->path() + "\\" + temp->text(0));
    }

    refreshPlateSampleTree();
}

void SVMTrainner::on_loadPlateTestSetButton_clicked()
{

}
