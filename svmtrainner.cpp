#include "svmtrainner.h"
#include "ui_svmtrainner.h"

#include <iostream>

SVMTrainner::SVMTrainner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SVMTrainner)
{
    ui->setupUi(this);
    this->ui->plateSampleImfo->hide();
    this->ui->plateTestResult->hide();
    this->ui->plateTestImfo->hide();
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

//Mat转QImage
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

//刷新车牌训练库
void SVMTrainner::refreshPlateSampleTree()
{
    this->ui->plateSampleTree->clear();
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateSampleImfo->hide();

    this->sampleSum = 0;

    int k, i;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0; k < plateTrainDirs.size(); k++)
    {
        sampleSum += plateTrainImgFileNames[k].size();
        tempGroup = new QTreeWidgetItem(this->ui->plateSampleTree);
        tempGroup->setText(0, PlateCategoryString[k] + "(" + QString::number(plateTrainImgFileNames[k].size()) + ")");
        for(i = 0; i < plateTrainImgFileNames[k].size(); i++)
        {
            tempSample = new QTreeWidgetItem(tempGroup);
            tempSample->setText(0, plateTrainImgFileNames[k].at(i));
            tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i));
        }
    }
}

//刷新车牌测试集库
void SVMTrainner::refreshPlateTestSampleTree()
{
    this->ui->plateTestTree->clear();
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateSampleImfo->hide();
    this->ui->plateTestImfo->hide();

    this->testSum = 0;

    int k, i, index;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0, index = 0; k < plateTestDirs.size(); k++)
    {
        testSum += plateTestImgFileNames[k].size();      
        if(k >= PlateCategoryString.size())
        {
            tempGroup = new QTreeWidgetItem(this->ui->plateTestTree);
            tempGroup->setText(0, QString::fromUtf8("未知") + "(" + QString::number(plateTestImgFileNames[k].size()) + ")");
            for(i = 0; i < plateTestImgFileNames[k].size(); i++)
            {
                tempSample = new QTreeWidgetItem(tempGroup);
                tempSample->setText(0, plateTestImgFileNames[k].at(i));
                tempSample->setWhatsThis(0,QString::number(-1) + "." + QString::number(i));
            }
            break;
        }
        if(standardPlateTestSet)
        {
            tempGroup = new QTreeWidgetItem(this->ui->plateTestTree);
            tempGroup->setText(0, PlateCategoryString[k] + "(" + QString::number(plateTestImgFileNames[k].size()) + ")");
            for(i = 0; i < plateTestImgFileNames[k].size(); i++)
            {
                tempSample = new QTreeWidgetItem(tempGroup);
                tempSample->setText(0, plateTestImgFileNames[k].at(i));
                if(!afterTest)
                    tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i));
                else {
                    tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i) + "." + QString::number(plateTestResults[index]));
                }
                index++;
            }
        }
        else {
            for(i = 0; i < plateTestImgFileNames[k].size(); i++)
            {
                tempSample = new QTreeWidgetItem(this->ui->plateTestTree);
                tempSample->setText(0, plateTestImgFileNames[k].at(i));
                if(!afterTest)
                    tempSample->setWhatsThis(0,QString::number(-1) + "." + QString::number(i));
                else {
                    tempSample->setWhatsThis(0,QString::number(-1) + "." + QString::number(i) + "." + QString::number(plateTestResults[i]));
                }
            }
        }
    }

    if(!afterTest)
    {
        this->ui->plateTestResult->hide();
        this->ui->singleOrErrorPlateTree->clear();
    }else if(standardPlateTestSet){
        this->ui->plateTestResult->show();
        refreshSingleOrErrorTree();
    }
}

//刷新车牌的错误或单张图库
void SVMTrainner::refreshSingleOrErrorTree()
{
    this->ui->singleOrErrorPlateTree->clear();
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateTestImfo->hide();

    int k, i, index;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0, index = 0; k < plateSingleOrErrorDirs.size(); k++)
    {
        tempGroup = new QTreeWidgetItem(this->ui->singleOrErrorPlateTree);
        tempGroup->setText(0, PlateCategoryString[k] + "(" + QString::number(plateSingleOrErrorImgFileNames[k].size()) + ")");
        for(i = 0; i < plateSingleOrErrorImgFileNames[k].size(); i++)
        {
            tempSample = new QTreeWidgetItem(tempGroup);
            tempSample->setText(0, plateSingleOrErrorImgFileNames[k].at(i));
            tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i) + "." + QString::number(plateTestResults[index]));
            index++;
        }
    }
}

//利用训练集生成测试集
void SVMTrainner::generateTestSetByTrainSet()
{
    if(plateTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练样本集!", QMessageBox::Ok);
        return;
    }

    //建造测试库

    if(!Property::plateTestLoadDefault)
    {
        Property::plateTestPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTestPath);
        if(Property::plateTestPath.isEmpty()) return;
    }
    if(!PlateCategory_SVM::PreparePlateTrainningDirectory(Property::plateTestPath))
    {
        QMessageBox::about(NULL, "Warning!", "测试库建立失败!");
        return;
    }

    int i, k;
    float p;
    QList<int> sums;
    for(k = 0; k < plateTrainDirs.size(); k++)
    {
        sums.insert(k, (int)(Property::testSetPercent * plateTrainImgFileNames[k].size() / 100));
        p = ((float)sums[k]) / ((float)plateTrainImgFileNames[k].size());
        for(i = 0; i < plateTrainImgFileNames[k].size(); i++)
        {
            if(((float)random(1000)) / 1000.0 < p)
            {
                QFile::copy(plateTrainDirs[k]->path() + "\\" + plateTrainImgFileNames[k].at(i), Property::plateTestPath + "\\plates\\" + PlateCategoryString[k] + "\\" + plateTrainImgFileNames[k].at(i));
                plateTrainImgFileNames[k].removeAt(i);
                i--;
            }
        }
    }

    bool formerSetting = Property::plateTestLoadDefault;
    Property::plateTestLoadDefault = true;
    on_loadPlateTestSetButton_clicked();
    Property::plateTestLoadDefault = formerSetting;

    refreshPlateSampleTree();
}

//打开车牌训练设置窗口
void SVMTrainner::on_platePropertyButton_clicked()
{
    PlateProperty *pp = new PlateProperty;

    pp->show();
}

//加载车牌训练库
void SVMTrainner::on_loadPlateSetButton_clicked()
{
    if(!Property::plateTrainPathDefault)
    {
        Property::plateTrainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTrainPath);
        if(Property::plateTrainPath.isEmpty()) return;
    }

    if(!QDir(Property::plateTrainPath).exists())
    {
        QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
        return;
    }

    this->ui->plateSampleTree->clear();
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();

    this->ui->plateSampleImfo->hide();
    this->ui->plateTestImfo->hide();

    int i, j, k;

    if(!PlateCategory_SVM::PreparePlateTrainningDirectory(Property::plateTrainPath))
    {
        QMessageBox::about(NULL, "Warning!", "训练库装载失败!");
        return;
    }

    plateTrainDirs.clear();
    plateTrainImgFileNames.clear();
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp";
    for(i = 0; i < PlateCategoryString.size(); i++) //只做非车牌与普通车牌的识别
    {
        plateTrainDirs.insert(i, new QDir(Property::plateTrainPath + "\\plates\\" + PlateCategoryString[i]));
        plateTrainImgFileNames.insert(i, plateTrainDirs[i]->entryList(nameFilters));
    }

    if(Property::generateTestSetByTrainSet)
    {
        generateTestSetByTrainSet();
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

//点击查看车牌样本
void SVMTrainner::on_plateSampleTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateTestImfo->hide();

    if(item->childCount() != 0)
    {
        this->ui->plateSampleImfo->hide();
        return;
    }

    this->ui->plateSampleImfo->show();
    this->ui->plateSampleName->setText(item->text(0));

    cv::Mat originalMat = cv::imread(plateTrainDirs[item->whatsThis(0).section(".",0,0).toInt()]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);

    if(originalMat.empty())
    {
        QMessageBox::information(NULL, "Warnning", "该图片路径有误！请刷新系统",QMessageBox::Ok);
        return;
    }

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
    afterTest = false;

    if(plateTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练集！", QMessageBox::Ok);
        return;
    }

    int i, k;

    QList<int> labels;

    cv::Mat mat;
    std::vector<float> descriptor;

    cv::Mat descriptorMat = cv::Mat::zeros(sampleSum, PlateCategory_SVM::HOGSize, CV_32FC1);

    i = 0;
    for(k = 0; k < plateTrainImgFileNames.size(); k++)
    {
        for (QString imgFileName : plateTrainImgFileNames[k])
        {
            QString filePath = plateTrainDirs[k]->path() + "\\" + imgFileName;
            std::string str = filePath.toLocal8Bit().toStdString();
            mat = cv::imread(str, cv::ImreadModes::IMREAD_GRAYSCALE);

            descriptor = PlateCategory_SVM::ComputeHogDescriptors(mat);

            for(int j = 0; j < PlateCategory_SVM::HOGSize; j++)
            {
                descriptorMat.at<float>(i, j) = descriptor.at(j);
            }
            labels.insert(labels.size(), k);
            i++;
        }
    }

    cv::Mat labelMat = cv::Mat(sampleSum, 1, CV_32SC1);

    for(i = 0; i < sampleSum; i++)
    {
        labelMat.at<int>(i, 0) = labels[i];
    }

    plateTrainned = PlateCategory_SVM::Train(descriptorMat, labelMat);

    refreshPlateTestSampleTree();
}

//更改车牌训练集样本标签
void SVMTrainner::on_plateSampleChangeButton_clicked()
{
    if((this->ui->plateSampleLabelCombo->currentIndex()== this->ui->plateSampleTree->currentItem()->whatsThis(0).section(".",0 ,0).toInt())) return;

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
        temp->setText(0, temp->text(0).left(temp->text(0).lastIndexOf(".")) + "(1)" + ".jpg");
        if(!file.rename(plateTrainDirs[formerLabel]->path() + "\\" + temp->text(0))) return;
    }
    QFile::copy(plateTrainDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[newLabel]->path() + "\\" + temp->text(0));
    QFile::remove(plateTrainDirs[formerLabel]->path() + "\\" + temp->text(0));

    plateTrainImgFileNames[formerLabel].removeAt(formerIndex);
    plateTrainImgFileNames[newLabel].insert(plateTrainImgFileNames[newLabel].size(), temp->text(0));

    refreshPlateSampleTree();
}

//删除车牌训练集样本
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

//加载车牌测试库
void SVMTrainner::on_loadPlateTestSetButton_clicked()
{
    afterTest = false;
    singleTest = false;
    this->ui->plateTestImfo->hide();

    if(!Property::plateTestLoadDefault)
    {
        Property::plateTestPath = QFileDialog::getExistingDirectory(this,tr("Select Test Set Path"),Property::plateTestPath);
        if(Property::plateTestPath.isEmpty()) return;
    }

    if(!QDir(Property::plateTestPath).exists())
    {
        QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
        return;
    }

    this->ui->plateTestTree->clear();
    this->ui->singleOrErrorPlateTree->clear();

    plateTestDirs.clear();
    plateTestImgFileNames.clear();
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp";

    this->standardPlateTestSet = PlateCategory_SVM::checkTestDirectory(Property::plateTestPath);

    int i;
    if(standardPlateTestSet)
    {
        for(i = 0; i < PlateCategoryString.size(); i++)
        {
            plateTestDirs.insert(i, new QDir(Property::plateTestPath + "\\plates\\" + PlateCategoryString[i]));
            plateTestImgFileNames.insert(i, plateTestDirs[i]->entryList(nameFilters));
        }
    }
    else {
        plateTestDirs.insert(0, new QDir(Property::plateTestPath));
        plateTestImgFileNames.insert(0, plateTestDirs[i]->entryList(nameFilters));
    }

    refreshPlateTestSampleTree();
}

//点击查看车牌测试样本
void SVMTrainner::on_plateTestTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateSampleImfo->hide();
    this->ui->rightPlateTag->show();

    if(!afterTest) this->ui->plateTestResult->hide();

    if(standardPlateTestSet && item->childCount() != 0)
    {
        this->ui->plateTestImfo->hide();
        return;
    }

    this->ui->plateTestImfo->show();
    this->ui->testPlateSampleName->setText(item->text(0));

    int index = item->whatsThis(0).section(".",0,0).toInt();
    if(!standardPlateTestSet) index = 0;
    if(index < 0) index = plateTestDirs.size() - 1;

    cv::Mat originalMat = cv::imread(plateTestDirs[index]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);
    if(originalMat.empty())
    {
        QMessageBox::information(NULL, "Warnning", "该图片路径有误！请刷新系统",QMessageBox::Ok);
        return;
    }

    this->ui->testPlateSampleSize->setText(QString::number(originalMat.cols) + " x " + QString::number(originalMat.rows));

    cv::Mat resizedMat;
    cv::resize(originalMat, resizedMat, cv::Size(this->ui->plateOriginalLabel->size().width(), this->ui->plateOriginalLabel->size().height()));

    QImage image = Mat2QImage(resizedMat,QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(image);
    this->ui->plateOriginalLabel->setPixmap(pixmap);

    cv::resize(originalMat, resizedMat, PlateCategory_SVM::HOGWinSize);
    std::vector<float> descriptor = PlateCategory_SVM::ComputeHogDescriptors(resizedMat);
    this->ui->testPlateHogSize->setText(QString::number(descriptor.size()));

    cv::Mat hogMat = getHogdescriptorVisualImage(resizedMat, descriptor, PlateCategory_SVM::HOGWinSize, PlateCategory_SVM::HOGCellSize, 1, 2.0);

    cv::resize(hogMat, hogMat, cv::Size(this->ui->plateHogLabel->size().width(), this->ui->plateHogLabel->size().height()));
    image = Mat2QImage(hogMat,QImage::Format_Grayscale8);
    pixmap = QPixmap::fromImage(image);
    this->ui->plateHogLabel->setPixmap(pixmap);

    this->ui->plateTestRighTagCombo->setCurrentIndex(item->whatsThis(0).section(".",0,0).toInt() + 1);

    if(afterTest && (item->whatsThis(0).section(".",0,0).toInt() >= 0 || plateTestDirs.size() == 1))
    {
        this->ui->plateTestResultCombo->setCurrentIndex(item->whatsThis(0).section(".",2,2).toInt());
        this->ui->plateTestResult->show();
    }
    else this->ui->plateTestResult->hide();

    if(singleTest) this->ui->rightPlateTag->hide();
    else this->ui->rightPlateTag->show();
}

//保存车牌训练成果
void SVMTrainner::on_savePlateTrainButton_clicked()
{
    if(!plateTrainned)
    {
        QMessageBox::information(this, "Warnning!", "还未进行训练!", QMessageBox::Ok);
        return;
    }

    if(!Property::plateResultPathDefault)
    {
        Property::plateResultPath = QFileDialog::getSaveFileName(this,tr("Select Where to Put the Result"),Property::plateResultPath, "xml(*.xml)");
        if(Property::plateResultPath.isEmpty()) return;
        PlateCategory_SVM::Save(Property::plateResultPath);
        QStringList temp = Property::plateResultPath.split("/");
        Property::plateResultName = temp.at(temp.size() - 1);
        Property::plateResultName = Property::plateResultName.left(Property::plateResultName.lastIndexOf("."));
        Property::plateResultPath = Property::plateResultPath.left(Property::plateResultPath.lastIndexOf("/"));
    }
    else {
        PlateCategory_SVM::Save(Property::plateResultPath + "\\" + Property::plateResultName + ".xml");
    }
}

//更改测试集样本的标签
void SVMTrainner::on_testPlateChangeTagButton_clicked()
{
    //对于未知数据进行标准测试库构建
    if(!standardPlateTestSet && this->ui->plateTestRighTagCombo->currentIndex() != 0)
    {
        QMessageBox:: StandardButton generateSet = QMessageBox::information(NULL, "Make Sure", "对非标准测试集内的数据更改标签，将建立标准数据集，且未被分配标签的测试数据将不再有效，是否确认操作？",QMessageBox::Yes|QMessageBox::No);
        switch (generateSet)
        {
           case QMessageBox::Yes:
           break;
           case QMessageBox::No:
           return;
           default:
            break;
        }
        QString originalPath = Property::plateTestPath;
        if(!Property::plateTestLoadDefault)
        {
             Property::plateTestPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTestPath);
            if(Property::plateTestPath.isEmpty()) return;
        }
        if(!PlateCategory_SVM::PreparePlateTrainningDirectory(Property::plateTestPath))
        {
            QMessageBox::about(NULL, "Warning!", "测试库建立失败!");
            return;
        }

        QStringList nameFilters;
        nameFilters << "*.jpg" << "*.png" << "*.bmp";

        this->standardPlateTestSet = true;

        int i;
        for(i = 0; i < PlateCategoryString.size(); i++)
        {
             plateTestDirs.insert(i, new QDir(Property::plateTestPath + "\\plates\\" + PlateCategoryString[i]));
            plateTestImgFileNames.insert(i, plateTestDirs[i]->entryList(nameFilters));
        }
        plateTestDirs.insert(i, new QDir(originalPath));
        plateTestImgFileNames.insert(i, plateTestDirs[i]->entryList(nameFilters));

        QTreeWidgetItem *temp = this->ui->plateTestTree->currentItem();
        int formerLabel = i;
        int newLabel = this->ui->plateTestRighTagCombo->currentIndex() - 1;
        int formerIndex = temp->whatsThis(0).section(".",1 ,1).toInt();

        if(QFile::exists(plateTestDirs[newLabel]->path() +  temp->text(0)))
        {
             QFile file(plateTestDirs[formerLabel]->path() + temp->text(0));
            temp->setText(0, temp->text(0) + "(1)");
            if(!file.rename(temp->text(0))) return;
         }
        QFile::copy(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0), plateTestDirs[newLabel]->path() + "\\" + temp->text(0));
        QFile::remove(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0));

        plateTestImgFileNames[formerLabel].removeAt(formerIndex);
        plateTestImgFileNames[newLabel].insert(plateTestImgFileNames[newLabel].size(), temp->text(0));
        }
    else {
        if((this->ui->plateTestRighTagCombo->currentIndex() - 1 == this->ui->plateTestTree->currentItem()->whatsThis(0).section(".",0 ,0).toInt()) ||
                this->ui->plateTestRighTagCombo->currentIndex() == 0) return;

        QTreeWidgetItem *temp = this->ui->plateTestTree->currentItem();
        int formerLabel = temp->whatsThis(0).section(".",0 ,0).toInt();
        int newLabel = this->ui->plateTestRighTagCombo->currentIndex() - 1;
        int formerIndex = temp->whatsThis(0).section(".",1 ,1).toInt();

        if(formerLabel < 0) formerLabel = plateTestDirs.size() - 1;
        if(newLabel < 0) newLabel = plateTestDirs.size() - 1;

        if(QFile::exists(plateTestDirs[newLabel]->path() +  temp->text(0)))
        {
            QFile file(plateTrainDirs[formerLabel]->path() + temp->text(0));
            temp->setText(0, temp->text(0) + "(1)");
            if(!file.rename(temp->text(0))) return;
        }
        QFile::copy(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0), plateTestDirs[newLabel]->path() + "\\" + temp->text(0));
        QFile::remove(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0));

        plateTestImgFileNames[formerLabel].removeAt(formerIndex);
        plateTestImgFileNames[newLabel].insert(plateTestImgFileNames[newLabel].size(), temp->text(0));
    }

    afterTest = false;
    refreshPlateTestSampleTree();
}

//车牌训练系统刷新
void SVMTrainner::on_plateRefreshButton_clicked()
{
    refreshPlateSampleTree();
    refreshPlateTestSampleTree();
}

//生成测试集
void SVMTrainner::on_generatePlateTestSetButton_clicked()
{
    generateTestSetByTrainSet();
}

//均衡测试集
void SVMTrainner::on_equalizePlateTrainButton_clicked()
{
    if(plateTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练集！", QMessageBox::Ok);
        return;
    }

    int leastIndex = 0;

    int i, k;
    for(k = 1; k < plateTrainImgFileNames.size(); k++)
    {
        if(plateTrainImgFileNames[k].size() < plateTrainImgFileNames[k - 1].size() && plateTrainImgFileNames[k].size() > 0)
        {
            leastIndex = k;
        }
    }

    for(k = 0; k < plateTrainImgFileNames.size(); k++)
    {
        if(k == leastIndex) continue;

        float p = ((float)plateTrainImgFileNames[k].size() - (float)plateTrainImgFileNames[leastIndex].size() * Property::maxMultiple) / (float)plateTrainImgFileNames[k].size();
        if(p < 0.0f) continue;

        for(i = 0; i < plateTrainImgFileNames[k].size(); i++)
        {
            if(((float)random(1000)) / 1000.0 < p)
            {
                plateTrainImgFileNames[k].removeAt(i);
                i--;
            }
        }
    }

    refreshPlateSampleTree();
}

//加载训练成果
void SVMTrainner::on_loadPlateTrainResultButton_clicked()
{
    if(!Property::plateResultLoadDefault)
    {
        Property::plateResultPath = QFileDialog::getOpenFileName(this,tr("Select the Result"),Property::plateResultPath, "xml(*.xml)");
        if(Property::plateResultPath.isEmpty()) return;

        PlateCategory_SVM::Load(Property::plateResultPath);

        QStringList temp = Property::plateResultPath.split("/");
        Property::plateResultName = temp.at(temp.size() - 1);
        Property::plateResultName = Property::plateResultName.left(Property::plateResultName.lastIndexOf("."));
        Property::plateResultPath = Property::plateResultPath.left(Property::plateResultPath.lastIndexOf("/"));
    }
    else {
        QString path = Property::plateResultPath + "\\" + Property::plateResultName + ".xml";
        if(!QFile(path).exists())
        {
            QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
            return;
        }
        PlateCategory_SVM::Load(path);
    }

    if(!PlateCategory_SVM::isReady)
    {
        QMessageBox::information(this, "Error!", "加载失败！", QMessageBox::Ok);
        return;
    }
}

//单图测试
void SVMTrainner::on_singlePlateTestButton_clicked()
{
    plateTestResults.clear();
    standardPlateTestSet = false;

    this->ui->plateTestTree->clear();
    plateTestDirs.clear();
    plateTestImgFileNames.clear();

    if(!PlateCategory_SVM::isReady)
    {
        QMessageBox::information(this, "Warnning!", "请先进行训练或载入训练成果", QMessageBox::Ok);
        return;
    }

    QString singleImagePath = QFileDialog::getOpenFileName(this,tr("Select Image to Test"),"", "image file(*.jpg)");
    QStringList temp = singleImagePath.split("/");

    int result = (int)PlateCategory_SVM::Test(singleImagePath);
    this->ui->plateTestResultCombo->setCurrentIndex(result);

    plateTestDirs.insert(0, new QDir(singleImagePath.left(singleImagePath.lastIndexOf("/"))));
    QStringList path;
    path.insert(0, temp.at(temp.size() - 1));
    plateTestImgFileNames.insert(0, path);

    singleTest = true;
    afterTest = true;
    plateTestResults.insert(0, result);

    refreshPlateTestSampleTree();

    this->on_plateTestTree_itemClicked(this->ui->plateTestTree->itemAt(0, 0), 0);
    this->ui->plateTestTree->setCurrentItem(this->ui->plateTestTree->itemAt(0, 0), 0);
}

//纠正及加入训练集
void SVMTrainner::on_correctPlateButton_clicked()
{
    int label = this->ui->plateTestResultCombo->currentIndex();
    if(!plateTrainDirs.empty())
    {
        QTreeWidgetItem *temp = this->ui->plateTestTree->currentItem();

        plateTrainImgFileNames[label]<<temp->text(0);

        if(QFile::exists(plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1)))
        {
            QFile file(plateTestDirs[0]->path() + "\\" + temp->text(0));
            temp->setText(0, temp->text(0).left(temp->text(0).lastIndexOf(".")) + "(1)" + ".jpg");
            if(!file.rename(plateTestDirs[0]->path() + "\\" + temp->text(0))) return;
        }

        if(!standardPlateTestSet)
        {
            QFile::copy(plateTestDirs[0]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
        }
        else {
            int formerLabel = this->ui->plateTestTree->currentItem()->whatsThis(0).section(".",0,0).toInt();
            QFile::copy(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
        }
        refreshPlateSampleTree();
        return;
    }

    if(!Property::plateTrainPathDefault)
    {
        Property::plateTrainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTrainPath);
        if(Property::plateTrainPath.isEmpty()) return;
    }

    if(!QDir(Property::plateTrainPath).exists())
    {
        QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
        return;
    }

    if(!PlateCategory_SVM::PreparePlateTrainningDirectory(Property::plateTrainPath))
    {
        QMessageBox::about(NULL, "Warning!", "训练库装载失败!");
        return;
    }

    QTreeWidgetItem *temp = this->ui->plateTestTree->currentItem();
    if(temp == nullptr)
    {
        QMessageBox::information(this, "Error!", "装入失败！");
        return;
    }

    if(!standardPlateTestSet)
    {
        QFile::copy(plateTestDirs[0]->path() + "\\" + temp->text(0), Property::plateTrainPath + "\\plates\\" + PlateCategoryString[this->ui->plateTestResultCombo->currentIndex()] + "\\" + temp->text(0));
    }else {
        int formerLabel = this->ui->plateTestTree->currentItem()->whatsThis(0).section(".",0,0).toInt();
        QFile::copy(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
    }
}

//批量测试车牌
void SVMTrainner::on_startPlateTestButton_clicked()
{
    if(plateTestDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "无效的测试集!", QMessageBox::Ok);
        return;
    }

    if(!PlateCategory_SVM::isReady)
    {
        QMessageBox::information(this, "Warnning!", "请先进行训练或载入训练成果", QMessageBox::Ok);
        return;
    }

    plateTestResults.clear();
    plateSingleOrErrorDirs.clear();
    plateSingleOrErrorImgFileNames.clear();

    int i, k, index;
    int tag;
    if(!standardPlateTestSet)
    {
        for(i = 0; i < plateTestImgFileNames[0].size(); i++)
        {
            plateTestResults.insert(i, PlateCategory_SVM::Test(plateTestDirs[0]->path() + "\\" + plateTestImgFileNames[0].at(i)));
        }
    }
    else {
        for(k = 0, index = 0; k < PlateCategoryString.size(); k++)
        {
            plateSingleOrErrorDirs.insert(k, plateTestDirs[k]);
            plateSingleOrErrorImgFileNames.insert(k, QStringList());
            for(i = 0; i < plateTestImgFileNames[k].size(); i++)
            {
                tag = PlateCategory_SVM::Test(plateTestDirs[k]->path() + "\\" + plateTestImgFileNames[k].at(i));
                plateTestResults.insert(index, tag);
                index++;

                if(tag != k)
                {
                    plateSingleOrErrorImgFileNames[k].insert(plateSingleOrErrorImgFileNames[k].size() - 1, plateTestImgFileNames[k].at(i));
                }
            }
        }
    }

    afterTest = true;
    refreshPlateTestSampleTree();
}

//查看错误图
void SVMTrainner::on_singleOrErrorPlateTree_itemClicked(QTreeWidgetItem *item, int column)
{

}
