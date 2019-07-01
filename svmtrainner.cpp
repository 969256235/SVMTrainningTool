#include "svmtrainner.h"
#include "ui_svmtrainner.h"

#include <iostream>

SVMTrainner::SVMTrainner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SVMTrainner)
{
    ui->setupUi(this);
    this->computerThread = nullptr;
    this->charComputerThread = nullptr;
    this->charTestThread = nullptr;
    this->plateTestThread = nullptr;

    this->ui->plateSampleImfo->hide();
    this->ui->plateTestResult->hide();
    this->ui->plateTestImfo->hide();
    this->ui->charSampleImfo->hide();
    this->ui->charTestResult->hide();
    this->ui->charTestImfo->hide();
}

SVMTrainner::~SVMTrainner()
{
    delete ui;
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

//控制台输出
void SVMTrainner::consoleOutput(QString consoleLine)
{
    consoleLine = "\n" + QTime::currentTime().toString() +  ":\n" + consoleLine + "\n";
    this->ui->plateConsole->insertPlainText(consoleLine);
    this->ui->plateConsole->moveCursor(QTextCursor::End);
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
        tempGroup->setWhatsThis(0, "0");
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
            tempGroup->setWhatsThis(0, "0");
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
        tempGroup->setWhatsThis(0, "0");
        for(i = 0; i < plateSingleOrErrorImgFileNames[k].size(); i++)
        {
            tempSample = new QTreeWidgetItem(tempGroup);
            tempSample->setText(0, plateSingleOrErrorImgFileNames[k].at(i));
            tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i) + "." + QString::number(errorPlateTag[index]));
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

    QString output = "生成了" + QString::number(testSum) + "张标准测试样本，其中\n";
    for(k = 0; k < plateTestDirs.size(); k++)
    {
        output += PlateCategoryString[k] + QString::number(plateTestImgFileNames[k].size()) + "张\n";
    }
    output += "已保存至 " + Property::plateTestPath;

    consoleOutput(output);
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

    int i;

    if(!PlateCategory_SVM::PreparePlateTrainningDirectory(Property::plateTrainPath))
    {
        QMessageBox::about(NULL, "Warning!", "训练库装载失败!");
        return;
    }

    plateTrainDirs.clear();
    plateTrainImgFileNames.clear();
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp";
    for(i = 0; i < PlateCategoryString.size(); i++)
    {
        plateTrainDirs.insert(i, new QDir(Property::plateTrainPath + "\\plates\\" + PlateCategoryString[i]));
        plateTrainImgFileNames.insert(i, plateTrainDirs[i]->entryList(nameFilters));
    }

    if(Property::generateTestSetByTrainSet)
    {
        generateTestSetByTrainSet();
    }

    if(Property::similarityCheck)
    {
        trainSetLoaded = false;
        computerThread = new class computeSimilarity(plateTrainDirs, plateTrainImgFileNames, true);
        //比较相似度
        connect(computerThread,&computeSimilarity::deleteItem,this,&SVMTrainner::sampleFilter);
        connect(computerThread,&computeSimilarity::consoleWrite,this,&SVMTrainner::consoleOutput);
        connect(computerThread,&computeSimilarity::finished,this,&SVMTrainner::finishedComputing);
        computerThread->start();
    }else
    {
        consoleOutput(Property::plateTrainPath +  " 载入完成");
        trainSetLoaded = true;
    }

    refreshPlateSampleTree();
}

void SVMTrainner::sampleFilter(int k, int j)
{
    consoleOutput(plateTrainDirs[k]->path() + "/" + plateTrainImgFileNames[k].at(j) + " 将被移除");
    plateTrainImgFileNames[k].removeAt(j);
    refreshPlateSampleTree();
}

void SVMTrainner::finishedComputing()
{
    trainSetLoaded = true;
    computerThread->exit();
    computerThread->destroyed();
    free(computerThread);
    computerThread = nullptr;
    consoleOutput("载入完成");
}

//点击查看车牌样本
void SVMTrainner::on_plateSampleTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateTestImfo->hide();

    if(item->whatsThis(0).split(".").size() == 1)
    {
        this->ui->plateSampleImfo->hide();
        return;
    }

    currentPlateFrom = 1;
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
    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    afterTest = false;

    if(plateTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练集！", QMessageBox::Ok);
        return;
    }

    if(!trainSetLoaded)
    {
        QMessageBox::information(this, "Warnning!", "请等待训练库装入！", QMessageBox::Ok);
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
    QString output = "训练完成，共有" + QString::number(sampleSum) + "张样本， 其中\n";
    for(k = 0; k < PlateCategoryString.size(); k++)
    {
        output += PlateCategoryString[k] + QString::number(plateTrainImgFileNames[k].size()) + "张";
        if(k != PlateCategoryString.size() - 1) output += "\n";
    }
    consoleOutput(output);

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
    consoleOutput("更改完成");

    this->ui->plateSampleTree->expandItem(this->ui->plateSampleTree->topLevelItem(formerLabel));
}

//删除车牌训练集样本
void SVMTrainner::on_plateSampleDeleteButton_clicked()
{
    bool deleteLocal = false;

    QMessageBox:: StandardButton result = QMessageBox::information(NULL, "Make Sure", "确认删除?",QMessageBox::Yes|QMessageBox::No);
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
    consoleOutput("样本已删除");

    this->ui->plateSampleTree->expandItem(this->ui->plateSampleTree->topLevelItem(label));
}

//加载车牌测试库
void SVMTrainner::on_loadPlateTestSetButton_clicked()
{
    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

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
        plateTestImgFileNames.insert(0, plateTestDirs[0]->entryList(nameFilters));
    }

    refreshPlateTestSampleTree();
    consoleOutput("载入完成");
}

//点击查看车牌测试样本
void SVMTrainner::on_plateTestTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateSampleImfo->hide();
    this->ui->rightPlateTag->show();

    if(!afterTest) this->ui->plateTestResult->hide();

    if(item->whatsThis(0).split(".").size() == 1)
    {
        this->ui->plateTestImfo->hide();
        return;
    }

    currentPlateFrom = 2;
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

    consoleOutput("已保存为" + Property::plateResultPath + "/" + Property::plateResultName + ".xml");
}

//更改测试集样本的标签
void SVMTrainner::on_testPlateChangeTagButton_clicked()
{
    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    int newLabel;
    if(currentPlateFrom == 3) return;

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

        consoleOutput("已成功建立了标准测试库:" + Property::plateTestPath);
        }
    else {
        if((this->ui->plateTestRighTagCombo->currentIndex() - 1 == this->ui->plateTestTree->currentItem()->whatsThis(0).section(".",0 ,0).toInt()) ||
                this->ui->plateTestRighTagCombo->currentIndex() == 0) return;

        QTreeWidgetItem *temp = this->ui->plateTestTree->currentItem();
        int formerLabel = temp->whatsThis(0).section(".",0 ,0).toInt();
        newLabel = this->ui->plateTestRighTagCombo->currentIndex() - 1;
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
    this->ui->plateTestTree->expandItem(this->ui->plateTestTree->topLevelItem(newLabel));
    consoleOutput("更改完成");
}

//车牌训练系统刷新
void SVMTrainner::on_plateRefreshButton_clicked()
{
    refreshPlateSampleTree();
    refreshPlateTestSampleTree();
    refreshSingleOrErrorTree();
}

//生成测试集
void SVMTrainner::on_generatePlateTestSetButton_clicked()
{
    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }
    generateTestSetByTrainSet();
}

//均衡训练集
void SVMTrainner::on_equalizePlateTrainButton_clicked()
{
    if(plateTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练集！", QMessageBox::Ok);
        return;
    }

    int leastIndex = 0;

    int i, k;
    for(k = 0; k < plateTrainImgFileNames.size() - 1; k++)
    {
        if(plateTrainImgFileNames[k + 1].size() < plateTrainImgFileNames[k].size() || plateTrainImgFileNames[k].size() < Property::minPlateSampleNum)
        {
            leastIndex = k + 1;
        }
    }

    if(plateTrainImgFileNames[k].size() < Property::minPlateSampleNum)
    {
        consoleOutput("已无法再削减");
        return;
    }

    int formerSize;
    QString output = "";
    for(k = 0; k < plateTrainImgFileNames.size(); k++)
    {
        if(k == leastIndex) continue;

        formerSize = plateTrainImgFileNames[k].size();
        float p = ((float)formerSize - (float)plateTrainImgFileNames[leastIndex].size() * Property::maxMultiple) / (float)plateTrainImgFileNames[k].size();
        if(p <= 0.0f)
        {
            output += PlateCategoryString[k] + "已无法再削减\n";
            continue;
        }

        for(i = 0; i < plateTrainImgFileNames[k].size(); i++)
        {
            if(((float)random(1000)) / 1000.0 < p)
            {
                plateTrainImgFileNames[k].removeAt(i);
                i--;
            }
        }
        output += PlateCategoryString[k] + "减少了" + QString::number(formerSize - plateTrainImgFileNames[k].size()) + "个样本";
        if(k != plateTrainImgFileNames.size() - 1) output += "\n";
    }
    consoleOutput(output);

    refreshPlateSampleTree();
}

//加载训练成果
void SVMTrainner::on_loadPlateTrainResultButton_clicked()
{
    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

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

    consoleOutput("成功加载" + Property::plateResultPath + "/" + Property::plateResultName + ".xml");
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

    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    QString singleImagePath = QFileDialog::getOpenFileName(this,tr("Select Image to Test"),"", "image file(*.jpg)");
    if(singleImagePath.isEmpty()) return;

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

    consoleOutput("测试完成");
}

//纠正及加入训练集
void SVMTrainner::on_correctPlateButton_clicked()
{
    int label = this->ui->plateTestResultCombo->currentIndex();
    if(!plateTrainDirs.empty())
    {
        QTreeWidgetItem *temp;
        switch (currentPlateFrom) {
            case 2:
            temp = this->ui->plateTestTree->currentItem();break;
        case 3:
            temp = this->ui->singleOrErrorPlateTree->currentItem();break;
        }

        plateTrainImgFileNames[label]<<temp->text(0);

        if(!standardPlateTestSet)
        {
            QFile::copy(plateTestDirs[0]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
        }
        else {
            int formerLabel = temp->whatsThis(0).section(".",0,0).toInt();
            switch (currentPlateFrom) {
                case 2:
                    QFile::copy(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
                    break;
                case 3:
                    QFile::copy(plateSingleOrErrorDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
                    break;
            }
        }

        if(currentPlateFrom == 3)
        {
            QTreeWidgetItem *temp = this->ui->singleOrErrorPlateTree->currentItem();
            plateSingleOrErrorImgFileNames[temp->whatsThis(0).section(".",0,0).toInt()].removeAt(temp->whatsThis(0).section(".",1,1).toInt());
            errorPlateTag.removeAt(temp->whatsThis(0).section(".",1,1).toInt());
            refreshSingleOrErrorTree();          
            this->ui->singleOrErrorPlateTree->expandItem(this->ui->singleOrErrorPlateTree->topLevelItem(temp->whatsThis(0).section(".",0,0).toInt()));
        }
        refreshPlateSampleTree();
        this->ui->plateSampleTree->expandItem(this->ui->plateSampleTree->topLevelItem(label));
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
        int formerLabel;
        switch (currentPlateFrom) {
            case 2:
                formerLabel = this->ui->plateTestTree->currentItem()->whatsThis(0).section(".",0,0).toInt();
                QFile::copy(plateTestDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
                break;
            case 3:
                formerLabel = this->ui->singleOrErrorPlateTree->currentItem()->whatsThis(0).section(".",0,0).toInt();
                QFile::copy(plateSingleOrErrorDirs[formerLabel]->path() + "\\" + temp->text(0), plateTrainDirs[label]->path() + "\\" + plateTrainImgFileNames[label].at(plateTrainImgFileNames[label].size() - 1));
                break;
        }
    }

    if(currentPlateFrom == 3)
    {
        QTreeWidgetItem *temp = this->ui->singleOrErrorPlateTree->currentItem();
        plateSingleOrErrorImgFileNames[temp->whatsThis(0).section(".",0,0).toInt()].removeAt(temp->whatsThis(0).section(".",1,1).toInt());
        errorPlateTag.removeAt(temp->whatsThis(0).section(".",1,1).toInt());
        refreshSingleOrErrorTree();
    }

    consoleOutput("操作完成");
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

    if(plateTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "请等待当前测试完成！", QMessageBox::Ok);
        return;
    }

    plateTestResults.clear();
    plateSingleOrErrorDirs.clear();
    plateSingleOrErrorImgFileNames.clear();

    if(standardPlateTestSet)
    {
        for(int k = 0; k < PlateCategoryString.size(); k++)
        {
            plateSingleOrErrorDirs.insert(k, plateTestDirs[k]);
            plateSingleOrErrorImgFileNames.insert(k, QStringList());
        }
    }

    plateTestThread = new PlateTestThread(standardPlateTestSet, plateTestDirs, plateTestImgFileNames, true);
    connect(plateTestThread,&PlateTestThread::testResult,this,&SVMTrainner::testedOne);
    connect(plateTestThread,&PlateTestThread::standardTestResult,this,&SVMTrainner::standardTestedOne);
    connect(plateTestThread,&PlateTestThread::finished,this,&SVMTrainner::finishTesting);

    plateTestThread->start();
}

void SVMTrainner::testedOne(int i, int tag)
{
    plateTestResults.insert(i, tag);
    consoleOutput(plateTestDirs[0]->path() + "/" + plateTestImgFileNames[0].at(i) + "测试完成，预测结果:" + PlateCategoryString[tag]);
}

void SVMTrainner::standardTestedOne(int k, int i, int index, int tag)
{
    plateTestResults.insert(index, tag);
    if(tag != k)
    {
        errorPlateTag.insert(errorPlateTag.size() - 1, tag);
        plateSingleOrErrorImgFileNames[k].insert(plateSingleOrErrorImgFileNames[k].size() - 1, plateTestImgFileNames[k].at(i));
    }
    consoleOutput(plateTestDirs[k]->path() + "/" + plateTestImgFileNames[k].at(i) + "测试完成，预测结果:" + PlateCategoryString[tag]);
}

void SVMTrainner::finishTesting()
{
    if(!standardPlateTestSet)
    {
        consoleOutput(QString::number(testSum) + "个非标准样本的测试已结束");
    }
    else {
        QString output = "";
        output += QString::number(testSum) + "个标准样本的测试结束，共有" + QString::number(errorPlateTag.size()) + "个错误,正确率 " + QString::number((float)(1.0f - ((float)errorPlateTag.size()) / ((float)testSum))*100, 'f', 3) + "%，其中\n";
        for(int k = 0; k < plateTestDirs.size(); k++)
        {
            output += PlateCategoryString[k] + QString::number(plateTestImgFileNames[k].size()) + "个，错误" + QString::number(plateSingleOrErrorImgFileNames[k].size()) + "个，正确率 " + QString::number((float)(1.0f - ((float)plateSingleOrErrorImgFileNames[k].size()) / ((float)plateTestImgFileNames[k].size()))*100, 'f', 3) + "%";
            if(k != plateSingleOrErrorDirs.size() - 1) output += "\n";
        }
        consoleOutput(output);
    }
    plateTestThread->terminate();
    plateTestThread->exit();
    plateTestThread->destroyed();
    free(plateTestThread);
    plateTestThread = nullptr;
    afterTest = true;
    refreshPlateTestSampleTree();
}

//查看错误图
void SVMTrainner::on_singleOrErrorPlateTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->plateOriginalLabel->clear();
    this->ui->plateHogLabel->clear();
    this->ui->plateSampleImfo->hide();
    this->ui->rightPlateTag->show();

    if(item->whatsThis(0).split(".").size() == 1)
    {
        this->ui->plateTestImfo->hide();
        return;
    }

    currentPlateFrom = 3;
    this->ui->plateTestImfo->show();
    this->ui->testPlateSampleName->setText(item->text(0));

    int index = item->whatsThis(0).section(".",0,0).toInt();

    cv::Mat originalMat = cv::imread(plateSingleOrErrorDirs[index]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);
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
    this->ui->plateTestResultCombo->setCurrentIndex(item->whatsThis(0).section(".",2,2).toInt());
    this->ui->plateTestResult->show();
    this->ui->rightPlateTag->show();
}

//字符训练部分
//刷新字符训练样本树
void SVMTrainner::refreshCharSampleTree()
{
    this->ui->charSampleTree->clear();
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();
    this->ui->charSampleImfo->hide();

    this->charSampleSum = 0;

    int k, i;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0; k < charTrainDirs.size(); k++)
    {
        charSampleSum += charTrainImgFileNames[k].size();
        tempGroup = new QTreeWidgetItem(this->ui->charSampleTree);
        tempGroup->setText(0, PlateCharString[k] + "(" + QString::number(charTrainImgFileNames[k].size()) + ")");
        tempGroup->setWhatsThis(0, "0");
        for(i = 0; i < charTrainImgFileNames[k].size(); i++)
        {
            tempSample = new QTreeWidgetItem(tempGroup);
            tempSample->setText(0, charTrainImgFileNames[k].at(i));
            tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i));
        }
    }
}

//刷新字符测试样本树
void SVMTrainner::refreshCharTestSampleTree()
{
    this->ui->charTestTree->clear();
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();
    this->ui->charSampleImfo->hide();
    this->ui->charTestImfo->hide();

    this->charTestSum = 0;

    int k, i, index;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0, index = 0; k < charTestDirs.size(); k++)
    {
        charTestSum += charTestImgFileNames[k].size();
        if(k >= PlateCharString.size())
        {
            tempGroup = new QTreeWidgetItem(this->ui->charTestTree);
            tempGroup->setText(0, QString::fromUtf8("未知") + "(" + QString::number(charTestImgFileNames[k].size()) + ")");
            tempGroup->setWhatsThis(0, "0");
            for(i = 0; i < charTestImgFileNames[k].size(); i++)
            {
                tempSample = new QTreeWidgetItem(tempGroup);
                tempSample->setText(0, charTestImgFileNames[k].at(i));
                tempSample->setWhatsThis(0,QString::number(-1) + "." + QString::number(i));
            }
            break;
        }
        if(standardCharTestSet)
        {
            tempGroup = new QTreeWidgetItem(this->ui->charTestTree);
            tempGroup->setText(0, PlateCharString[k] + "(" + QString::number(charTestImgFileNames[k].size()) + ")");
            for(i = 0; i < charTestImgFileNames[k].size(); i++)
            {
                tempSample = new QTreeWidgetItem(tempGroup);
                tempSample->setText(0, charTestImgFileNames[k].at(i));
                if(!afterCharTest)
                    tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i));
                else {
                    tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i) + "." + QString::number(charTestResults[index]));
                }
                index++;
            }
        }
        else {
            for(i = 0; i < charTestImgFileNames[k].size(); i++)
            {
                tempSample = new QTreeWidgetItem(this->ui->charTestTree);
                tempSample->setText(0, charTestImgFileNames[k].at(i));
                if(!afterTest)
                    tempSample->setWhatsThis(0,QString::number(-1) + "." + QString::number(i));
                else {
                    tempSample->setWhatsThis(0,QString::number(-1) + "." + QString::number(i) + "." + QString::number(charTestResults[i]));
                }
            }
        }
    }

    if(!afterCharTest)
    {
        this->ui->charTestResult->hide();
        this->ui->singleOrErrorCharTree->clear();
    }else if(standardCharTestSet){
        this->ui->charTestResult->show();
        refreshCharSingleOrErrorTree();
    }else {
        this->ui->charTestResult->show();
    }
}

//刷新错误字符树
void SVMTrainner::refreshCharSingleOrErrorTree()
{
    this->ui->singleOrErrorCharTree->clear();
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();
    this->ui->charTestImfo->hide();

    int k, i, index;
    QTreeWidgetItem *tempGroup;
    QTreeWidgetItem *tempSample;
    for(k = 0, index = 0; k < charSingleOrErrorDirs.size(); k++)
    {
        tempGroup = new QTreeWidgetItem(this->ui->singleOrErrorCharTree);
        tempGroup->setText(0, PlateCharString[k] + "(" + QString::number(charSingleOrErrorImgFileNames[k].size()) + ")");
        tempGroup->setWhatsThis(0, "0");
        for(i = 0; i < charSingleOrErrorImgFileNames[k].size(); i++)
        {
            tempSample = new QTreeWidgetItem(tempGroup);
            tempSample->setText(0, charSingleOrErrorImgFileNames[k].at(i));
            tempSample->setWhatsThis(0,QString::number(k) + "." + QString::number(i) + "." + QString::number(errorCharTag[index]));
            index++;
        }
    }
}

//用字符训练集生成字符测试集
void SVMTrainner::generateCharTestSetByTrainSet()
{
    if(charTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练样本集!", QMessageBox::Ok);
        return;
    }

    //建造测试库
    if(!Property::charTestLoadDefault)
    {
        Property::charTestPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::charTestPath);
        if(Property::charTestPath.isEmpty()) return;
    }
    if(!PlateChar_SVM::PrepareCharTrainningDirectory(Property::charTestPath))
    {
        QMessageBox::about(NULL, "Warning!", "测试库建立失败!");
        return;
    }

    int i, k;
    float p;
    QList<int> sums;
    for(k = 0; k < charTrainDirs.size(); k++)
    {
        sums.insert(k, (int)(Property::charTestSetPercent * charTrainImgFileNames[k].size() / 100));
        p = ((float)sums[k]) / ((float)charTrainImgFileNames[k].size());
        for(i = 0; i < charTrainImgFileNames[k].size(); i++)
        {
            if(((float)random(1000)) / 1000.0 < p)
            {
                QFile::copy(charTrainDirs[k]->path() + "\\" + charTrainImgFileNames[k].at(i), Property::charTestPath + "\\chars\\" + PlateCharString[k] + "\\" + charTrainImgFileNames[k].at(i));
                charTrainImgFileNames[k].removeAt(i);
                i--;
            }
        }
    }

    bool formerSetting = Property::charTestLoadDefault;
    Property::charTestLoadDefault = true;
    //on_loadCharTestSetButton_clicked();
    Property::charTestLoadDefault = formerSetting;

    refreshCharSampleTree();

    QString output = "生成了" + QString::number(charTestSum) + "张标准测试样本，其中\n";
    for(k = 0; k < charTestDirs.size(); k++)
    {
        output += PlateCharString[k] + QString::number(charTestImgFileNames[k].size()) + "张\n";
    }
    output += "已保存至 " + Property::charTestPath;

    charConsoleOutput(output);
}

//字符控制台输出
void SVMTrainner::charConsoleOutput(QString consoleLine)
{
    consoleLine = "\n" + QTime::currentTime().toString() +  ":\n" + consoleLine + "\n";
    this->ui->charConsole->insertPlainText(consoleLine);
    this->ui->charConsole->moveCursor(QTextCursor::End);
}

//打开字符配置窗口
void SVMTrainner::on_charPropertyButton_clicked()
{
    CharProperty *cp = new CharProperty;

    cp->show();
}

//加载字符训练库
void SVMTrainner::on_loadCharSetButton_clicked()
{
    if(!Property::charTrainPathDefault)
    {
        Property::charTrainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::charTrainPath);
        if(Property::charTrainPath.isEmpty()) return;
    }

    if(!QDir(Property::charTrainPath).exists())
    {
        QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
        return;
    }

    this->ui->charSampleTree->clear();
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();

    this->ui->charSampleImfo->hide();
    this->ui->charTestImfo->hide();

    int i;

    if(!PlateChar_SVM::PrepareCharTrainningDirectory(Property::charTrainPath))
    {
        QMessageBox::about(NULL, "Warning!", "训练库装载失败!");
        return;
    }

    charTrainDirs.clear();
    charTrainImgFileNames.clear();
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp";
    for(i = 0; i < PlateCharString.size(); i++)
    {
        charTrainDirs.insert(i, new QDir(Property::charTrainPath + "\\chars\\" + PlateCharString[i]));
        charTrainImgFileNames.insert(i, charTrainDirs[i]->entryList(nameFilters));
    }

    if(Property::charGenerateTestSetByTrainSet)
    {
        generateCharTestSetByTrainSet();
    }

    if(Property::charSimilarityCheck)
    {
        charTrainSetLoaded = false;
        charComputerThread = new class computeSimilarity(charTrainDirs, charTrainImgFileNames, false);
        //比较相似度
        connect(charComputerThread,&computeSimilarity::deleteItem,this,&SVMTrainner::charSampleFilter);
        connect(charComputerThread,&computeSimilarity::consoleWrite,this,&SVMTrainner::charConsoleOutput);
        connect(charComputerThread,&computeSimilarity::finished,this,&SVMTrainner::finishedCharComputing);
        charComputerThread->start();
    }else
    {
        charConsoleOutput(Property::charTrainPath +  " 载入完成");
        charTrainSetLoaded = true;
    }

    refreshCharSampleTree();
}

void SVMTrainner::charSampleFilter(int k, int j)
{
    charConsoleOutput(charTrainDirs[k]->path() + "/" + charTrainImgFileNames[k].at(j) + " 将被移除");
    charTrainImgFileNames[k].removeAt(j);
    refreshCharSampleTree();
}

void SVMTrainner::finishedCharComputing()
{
    charTrainSetLoaded = true;
    charComputerThread->exit();
    charComputerThread->destroyed();
    free(charComputerThread);
    charComputerThread = nullptr;
    charConsoleOutput("载入完成");
}

//查看字符训练集样本
void SVMTrainner::on_charSampleTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();
    this->ui->charTestImfo->hide();

    if(item->whatsThis(0).split(".").size() == 1)
    {
        this->ui->charSampleImfo->hide();
        return;
    }

    currentCharFrom = 1;
    this->ui->charSampleImfo->show();
    this->ui->charSampleName->setText(item->text(0));

    cv::Mat originalMat = cv::imread(charTrainDirs[item->whatsThis(0).section(".",0,0).toInt()]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);

    if(originalMat.empty())
    {
        QMessageBox::information(NULL, "Warnning", "该图片路径有误！请刷新系统",QMessageBox::Ok);
        return;
    }

    this->ui->charSampleSize->setText(QString::number(originalMat.cols) + " x " + QString::number(originalMat.rows));

    cv::Mat resizedMat;
    cv::resize(originalMat, resizedMat, cv::Size(this->ui->charOriginalLabel->size().width(), this->ui->charOriginalLabel->size().height()));

    QImage image = Mat2QImage(resizedMat,QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(image);
    this->ui->charOriginalLabel->setPixmap(pixmap);

    cv::resize(originalMat, resizedMat, PlateChar_SVM::HOGWinSize);
    std::vector<float> descriptor = PlateChar_SVM::ComputeHogDescriptors(resizedMat);
    this->ui->charHogSize->setText(QString::number(descriptor.size()));

    cv::Mat hogMat = getHogdescriptorVisualImage(resizedMat, descriptor, PlateChar_SVM::HOGWinSize, PlateChar_SVM::HOGCellSize, 1, 2.0);

    cv::resize(hogMat, hogMat, cv::Size(this->ui->charHogLabel->size().width(), this->ui->charHogLabel->size().height()));
    image = Mat2QImage(hogMat,QImage::Format_Grayscale8);
    pixmap = QPixmap::fromImage(image);
    this->ui->charHogLabel->setPixmap(pixmap);

    this->ui->charSampleLabelCombo->setCurrentIndex(item->whatsThis(0).section(".", 0, 0).toInt());
}

//训练字符
void SVMTrainner::on_charTrainButton_clicked()
{
    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    afterCharTest = false;

    if(charTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练集！", QMessageBox::Ok);
        return;
    }

    if(!charTrainSetLoaded)
    {
        QMessageBox::information(this, "Warnning!", "请等待训练库装入！", QMessageBox::Ok);
        return;
    }

    int i, k;

    QList<int> labels;

    cv::Mat mat;
    std::vector<float> descriptor;

    cv::Mat descriptorMat = cv::Mat::zeros(charSampleSum, PlateChar_SVM::HOGSize, CV_32FC1);

    i = 0;
    for(k = 0; k < charTrainImgFileNames.size(); k++)
    {
        for (QString imgFileName : charTrainImgFileNames[k])
        {
            QString filePath = charTrainDirs[k]->path() + "\\" + imgFileName;
            std::string str = filePath.toLocal8Bit().toStdString();
            mat = cv::imread(str, cv::ImreadModes::IMREAD_GRAYSCALE);

            descriptor = PlateChar_SVM::ComputeHogDescriptors(mat);

            for(int j = 0; j < PlateChar_SVM::HOGSize; j++)
            {
                descriptorMat.at<float>(i, j) = descriptor.at(j);
            }
            labels.insert(labels.size(), k);
            i++;
        }
    }

    cv::Mat labelMat = cv::Mat(charSampleSum, 1, CV_32SC1);

    for(i = 0; i < charSampleSum; i++)
    {
        labelMat.at<int>(i, 0) = labels[i];
    }

    charTrainned = PlateChar_SVM::Train(descriptorMat, labelMat);
    QString output = "训练完成，共有" + QString::number(charSampleSum) + "张样本， 其中\n";
    for(k = 0; k < PlateCharString.size(); k++)
    {
        output += PlateCharString[k] + QString::number(charTrainImgFileNames[k].size()) + "张";
        if(k != PlateCharString.size() - 1) output += "\n";
    }
    charConsoleOutput(output);

    refreshCharTestSampleTree();
}

//更改字符训练样本的标签
void SVMTrainner::on_charSampleChangeButton_clicked()
{
    if((this->ui->charSampleLabelCombo->currentIndex()== this->ui->charSampleTree->currentItem()->whatsThis(0).section(".",0 ,0).toInt())) return;

    QMessageBox:: StandardButton result = QMessageBox::information(NULL, "Make Sure", "确认要更改标签吗?",QMessageBox::Yes|QMessageBox::No);
    switch (result)
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        return;
    default:
        break;
    }

    QTreeWidgetItem *temp = this->ui->charSampleTree->currentItem();
    int formerLabel = temp->whatsThis(0).section(".",0 ,0).toInt();
    int newLabel = this->ui->plateSampleLabelCombo->currentIndex();
    int formerIndex = temp->whatsThis(0).section(".",1 ,1).toInt();

    if(QFile::exists(charTrainDirs[newLabel]->path() +  temp->text(0)))
    {
        QFile file(charTrainDirs[formerLabel]->path() + temp->text(0));
        temp->setText(0, temp->text(0).left(temp->text(0).lastIndexOf(".")) + "(1)" + ".jpg");
        if(!file.rename(charTrainDirs[formerLabel]->path() + "\\" + temp->text(0))) return;
    }
    QFile::copy(charTrainDirs[formerLabel]->path() + "\\" + temp->text(0), charTrainDirs[newLabel]->path() + "\\" + temp->text(0));
    QFile::remove(charTrainDirs[formerLabel]->path() + "\\" + temp->text(0));

    charTrainImgFileNames[formerLabel].removeAt(formerIndex);
    charTrainImgFileNames[newLabel].insert(charTrainImgFileNames[newLabel].size(), temp->text(0));

    refreshCharSampleTree();
    charConsoleOutput("更改完成");

    this->ui->charSampleTree->expandItem(this->ui->charSampleTree->topLevelItem(formerLabel));
}

//删除车牌训练集样本
void SVMTrainner::on_charSampleDeleteButton_clicked()
{
    bool deleteLocal = false;

    QMessageBox:: StandardButton result = QMessageBox::information(NULL, "Make Sure", "确认删除?",QMessageBox::Yes|QMessageBox::No);
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

    QTreeWidgetItem *temp = this->ui->charSampleTree->currentItem();
    int label = temp->whatsThis(0).section(".", 0, 0).toInt();
    int index = temp->whatsThis(0).section(".", 1, 1).toInt();

    charTrainImgFileNames[label].removeAt(index);

    if(deleteLocal)
    {
        QFile::remove(charTrainDirs[label]->path() + "\\" + temp->text(0));
    }

    refreshCharSampleTree();
    charConsoleOutput("样本已删除");

    this->ui->charSampleTree->expandItem(this->ui->charSampleTree->topLevelItem(label));
}

//加载字符测试库
void SVMTrainner::on_loadCharTestSetButton_clicked()
{
    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    afterCharTest = false;
    singleCharTest = false;
    this->ui->charTestImfo->hide();

    if(!Property::charTestLoadDefault)
    {
        Property::charTestPath = QFileDialog::getExistingDirectory(this,tr("Select Test Set Path"),Property::charTestPath);
        if(Property::charTestPath.isEmpty()) return;
    }

    if(!QDir(Property::charTestPath).exists())
    {
        QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
        return;
    }

    this->ui->charTestTree->clear();
    this->ui->singleOrErrorCharTree->clear();

    charTestDirs.clear();
    charTestImgFileNames.clear();
    QStringList nameFilters;
    nameFilters << "*.jpg" << "*.png" << "*.bmp";

    this->standardCharTestSet = PlateChar_SVM::checkTestDirectory(Property::charTestPath);

    int i;
    if(standardCharTestSet)
    {
        for(i = 0; i < PlateCharString.size(); i++)
        {
            charTestDirs.insert(i, new QDir(Property::charTestPath + "\\chars\\" + PlateCharString[i]));
            charTestImgFileNames.insert(i, charTestDirs[i]->entryList(nameFilters));
        }
    }
    else {
        charTestDirs.insert(0, new QDir(Property::charTestPath));
        charTestImgFileNames.insert(0, charTestDirs[0]->entryList(nameFilters));
    }

    refreshCharTestSampleTree();
    charConsoleOutput("载入完成");
}

//查看字符测试样本
void SVMTrainner::on_charTestTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();
    this->ui->charSampleImfo->hide();
    this->ui->rightCharTag->show();

    if(!afterCharTest) this->ui->charTestResult->hide();

    if(item->whatsThis(0).split(".").size() == 1)
    {
        this->ui->charTestImfo->hide();
        return;
    }

    currentCharFrom = 2;
    this->ui->charTestImfo->show();
    this->ui->testCharSampleName->setText(item->text(0));

    int index = item->whatsThis(0).section(".",0,0).toInt();
    if(!standardCharTestSet) index = 0;
    if(index < 0) index = charTestDirs.size() - 1;

    cv::Mat originalMat = cv::imread(charTestDirs[index]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);
    if(originalMat.empty())
    {
        QMessageBox::information(NULL, "Warnning", "该图片路径有误！请刷新系统",QMessageBox::Ok);
        return;
    }

    this->ui->testCharSampleSize->setText(QString::number(originalMat.cols) + " x " + QString::number(originalMat.rows));

    cv::Mat resizedMat;
    cv::resize(originalMat, resizedMat, cv::Size(this->ui->charOriginalLabel->size().width(), this->ui->charOriginalLabel->size().height()));

    QImage image = Mat2QImage(resizedMat,QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(image);
    this->ui->charOriginalLabel->setPixmap(pixmap);

    cv::resize(originalMat, resizedMat, PlateChar_SVM::HOGWinSize);
    std::vector<float> descriptor = PlateChar_SVM::ComputeHogDescriptors(resizedMat);
    this->ui->testCharHogSize->setText(QString::number(descriptor.size()));

    cv::Mat hogMat = getHogdescriptorVisualImage(resizedMat, descriptor, PlateChar_SVM::HOGWinSize, PlateChar_SVM::HOGCellSize, 1, 2.0);

    cv::resize(hogMat, hogMat, cv::Size(this->ui->charHogLabel->size().width(), this->ui->charHogLabel->size().height()));
    image = Mat2QImage(hogMat,QImage::Format_Grayscale8);
    pixmap = QPixmap::fromImage(image);
    this->ui->charHogLabel->setPixmap(pixmap);

    this->ui->charTestRighTagCombo->setCurrentIndex(item->whatsThis(0).section(".",0,0).toInt() + 1);

    if(afterCharTest && (item->whatsThis(0).section(".",0,0).toInt() >= 0 || charTestDirs.size() == 1))
    {
        this->ui->charTestResultCombo->setCurrentIndex(item->whatsThis(0).section(".",2,2).toInt());
        this->ui->charTestResult->show();
    }
    else this->ui->charTestResult->hide();

    if(singleCharTest) this->ui->rightCharTag->hide();
    else this->ui->rightCharTag->show();
}

//保存字符训练结果
void SVMTrainner::on_saveCharTrainButton_clicked()
{
    if(!charTrainned)
    {
        QMessageBox::information(this, "Warnning!", "还未进行训练!", QMessageBox::Ok);
        return;
    }

    if(!Property::charResultPathDefault)
    {
        Property::charResultPath = QFileDialog::getSaveFileName(this,tr("Select Where to Put the Result"),Property::charResultPath, "xml(*.xml)");
        if(Property::charResultPath.isEmpty()) return;
        PlateChar_SVM::Save(Property::charResultPath);
        QStringList temp = Property::charResultPath.split("/");
        Property::charResultName = temp.at(temp.size() - 1);
        Property::charResultName = Property::charResultName.left(Property::charResultName.lastIndexOf("."));
        Property::charResultPath = Property::charResultPath.left(Property::charResultPath.lastIndexOf("/"));
    }
    else {
        PlateChar_SVM::Save(Property::charResultPath + "\\" + Property::charResultName + ".xml");
    }

    charConsoleOutput("已保存为" + Property::charResultPath + "/" + Property::charResultName + ".xml");
}

//更改字符测试集样本的标签
void SVMTrainner::on_testCharChangeTagButton_clicked()
{
    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    int newLabel;
    if(currentCharFrom == 3) return;

    //对于未知数据进行标准测试库构建
    if(!standardCharTestSet && this->ui->charTestRighTagCombo->currentIndex() != 0)
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
        QString originalPath = Property::charTestPath;
        if(!Property::charTestLoadDefault)
        {
             Property::charTestPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::charTestPath);
            if(Property::charTestPath.isEmpty()) return;
        }
        if(!PlateChar_SVM::PrepareCharTrainningDirectory(Property::charTestPath))
        {
            QMessageBox::about(NULL, "Warning!", "测试库建立失败!");
            return;
        }

        QStringList nameFilters;
        nameFilters << "*.jpg" << "*.png" << "*.bmp";

        this->standardCharTestSet = true;

        int i;
        for(i = 0; i < PlateCharString.size(); i++)
        {
            charTestDirs.insert(i, new QDir(Property::charTestPath + "\\chars\\" + PlateCharString[i]));
            charTestImgFileNames.insert(i, charTestDirs[i]->entryList(nameFilters));
        }
        charTestDirs.insert(i, new QDir(originalPath));
        charTestImgFileNames.insert(i, charTestDirs[i]->entryList(nameFilters));

        QTreeWidgetItem *temp = this->ui->charTestTree->currentItem();
        int formerLabel = i;
        int newLabel = this->ui->charTestRighTagCombo->currentIndex() - 1;
        int formerIndex = temp->whatsThis(0).section(".",1 ,1).toInt();

        if(QFile::exists(charTestDirs[newLabel]->path() +  temp->text(0)))
        {
             QFile file(charTestDirs[formerLabel]->path() + temp->text(0));
            temp->setText(0, temp->text(0) + "(1)");
            if(!file.rename(temp->text(0))) return;
         }
        QFile::copy(charTestDirs[formerLabel]->path() + "\\" + temp->text(0), charTestDirs[newLabel]->path() + "\\" + temp->text(0));
        QFile::remove(charTestDirs[formerLabel]->path() + "\\" + temp->text(0));

        charTestImgFileNames[formerLabel].removeAt(formerIndex);
        charTestImgFileNames[newLabel].insert(charTestImgFileNames[newLabel].size(), temp->text(0));

        charConsoleOutput("已成功建立了标准测试库:" + Property::plateTestPath);
        }
    else {
        if((this->ui->charTestRighTagCombo->currentIndex() - 1 == this->ui->charTestTree->currentItem()->whatsThis(0).section(".",0 ,0).toInt()) ||
                this->ui->charTestRighTagCombo->currentIndex() == 0) return;

        QTreeWidgetItem *temp = this->ui->charTestTree->currentItem();
        int formerLabel = temp->whatsThis(0).section(".",0 ,0).toInt();
        newLabel = this->ui->charTestRighTagCombo->currentIndex() - 1;
        int formerIndex = temp->whatsThis(0).section(".",1 ,1).toInt();

        if(formerLabel < 0) formerLabel = charTestDirs.size() - 1;
        if(newLabel < 0) newLabel = charTestDirs.size() - 1;

        if(QFile::exists(charTestDirs[newLabel]->path() +  temp->text(0)))
        {
            QFile file(charTrainDirs[formerLabel]->path() + temp->text(0));
            temp->setText(0, temp->text(0) + "(1)");
            if(!file.rename(temp->text(0))) return;
        }
        QFile::copy(charTestDirs[formerLabel]->path() + "\\" + temp->text(0), charTestDirs[newLabel]->path() + "\\" + temp->text(0));
        QFile::remove(charTestDirs[formerLabel]->path() + "\\" + temp->text(0));

        charTestImgFileNames[formerLabel].removeAt(formerIndex);
        charTestImgFileNames[newLabel].insert(charTestImgFileNames[newLabel].size(), temp->text(0));
    }

    afterCharTest = false;
    refreshCharTestSampleTree();
    this->ui->charTestTree->expandItem(this->ui->charTestTree->topLevelItem(newLabel));
    charConsoleOutput("更改完成");
}

//刷新字符训练系统
void SVMTrainner::on_charRefreshButton_clicked()
{
    refreshCharSampleTree();
    refreshCharTestSampleTree();
    refreshCharSingleOrErrorTree();
}

//生成测试集
void SVMTrainner::on_generateCharTestSetButton_clicked()
{
    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }
    generateCharTestSetByTrainSet();
}

//均衡化字符训练样本集
void SVMTrainner::on_equalizeCharTrainButton_clicked()
{
    if(charTrainDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "未装载训练集！", QMessageBox::Ok);
        return;
    }

    int leastIndex = 0;

    int i, k;
    for(k = 0; k < charTrainImgFileNames.size() - 1; k++)
    {
        if(charTrainImgFileNames[k + 1].size() < Property::minCharSampleNum) continue;

        if(charTrainImgFileNames[k + 1].size() < charTrainImgFileNames[leastIndex].size())
        {
            leastIndex = k + 1;
        }
    }

    if(charTrainImgFileNames[leastIndex].size() < Property::minCharSampleNum)
    {
        std::cout<<Property::minCharSampleNum<<" "<<charTrainImgFileNames[k].size()<<std::endl;
        charConsoleOutput("已无法再削减");
        return;
    }

    int formerSize;
    QString output = "";
    for(k = 0; k < charTrainImgFileNames.size(); k++)
    {
        if(k == leastIndex) continue;

        formerSize = charTrainImgFileNames[k].size();
        float p = ((float)formerSize - (float)charTrainImgFileNames[leastIndex].size() * Property::maxMultiple) / (float)charTrainImgFileNames[k].size();
        if(p <= 0.0f)
        {
            output += PlateCharString[k] + "已无法再削减\n";
            continue;
        }

        for(i = 0; i < charTrainImgFileNames[k].size(); i++)
        {
            if(((float)random(1000)) / 1000.0 < p)
            {
                charTrainImgFileNames[k].removeAt(i);
                i--;
            }
        }
        output += PlateCharString[k] + "减少了" + QString::number(formerSize - charTrainImgFileNames[k].size()) + "个样本";
        if(k != charTrainImgFileNames.size() - 1) output += "\n";
    }
    charConsoleOutput(output);

    refreshCharSampleTree();
}

//加载字符训练成果
void SVMTrainner::on_loadCharTrainResultButton_clicked()
{
    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    if(!Property::charResultLoadDefault)
    {
        Property::charResultPath = QFileDialog::getOpenFileName(this,tr("Select the Result"),Property::charResultPath, "xml(*.xml)");
        if(Property::charResultPath.isEmpty()) return;

        PlateChar_SVM::Load(Property::charResultPath);

        QStringList temp = Property::charResultPath.split("/");
        Property::charResultName = temp.at(temp.size() - 1);
        Property::charResultName = Property::charResultName.left(Property::charResultName.lastIndexOf("."));
        Property::charResultPath = Property::charResultPath.left(Property::charResultPath.lastIndexOf("/"));
    }
    else {
        QString path = Property::charResultPath + "\\" + Property::charResultName + ".xml";
        if(!QFile(path).exists())
        {
            QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
            return;
        }
        PlateChar_SVM::Load(path);
    }

    if(!PlateChar_SVM::isReady)
    {
        QMessageBox::information(this, "Error!", "加载失败！", QMessageBox::Ok);
        return;
    }

    charConsoleOutput("成功加载" + Property::charResultPath + "/" + Property::charResultName + ".xml");
}

//字符单图测试
void SVMTrainner::on_singleCharTestButton_clicked()
{
    charTestResults.clear();
    standardCharTestSet = false;

    this->ui->charTestTree->clear();
    charTestDirs.clear();
    charTestImgFileNames.clear();

    if(!PlateChar_SVM::isReady)
    {
        QMessageBox::information(this, "Warnning!", "请先进行训练或载入训练成果", QMessageBox::Ok);
        return;
    }

    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "当前仍有测试在进行", QMessageBox::Ok);
        return;
    }

    QString singleImagePath = QFileDialog::getOpenFileName(this,tr("Select Image to Test"),"", "image file(*.jpg)");
    if(singleImagePath.isEmpty()) return;

    QStringList temp = singleImagePath.split("/");

    int result = (int)PlateChar_SVM::Test(singleImagePath);
    this->ui->charTestResultCombo->setCurrentIndex(result);

    charTestDirs.insert(0, new QDir(singleImagePath.left(singleImagePath.lastIndexOf("/"))));
    QStringList path;
    path.insert(0, temp.at(temp.size() - 1));
    charTestImgFileNames.insert(0, path);

    singleCharTest = true;
    afterCharTest = true;
    charTestResults.insert(0, result);

    refreshCharTestSampleTree();

    this->on_charTestTree_itemClicked(this->ui->charTestTree->itemAt(0, 0), 0);
    this->ui->charTestTree->setCurrentItem(this->ui->charTestTree->itemAt(0, 0), 0);

    charConsoleOutput("测试完成");
}

//纠正及加入训练库
void SVMTrainner::on_correctCharButton_clicked()
{
    int label = this->ui->charTestResultCombo->currentIndex();
    if(!charTrainDirs.empty())
    {
        QTreeWidgetItem *temp;
        switch (currentCharFrom) {
            case 2:
            temp = this->ui->charTestTree->currentItem();break;
        case 3:
            temp = this->ui->singleOrErrorCharTree->currentItem();break;
        }

        charTrainImgFileNames[label]<<temp->text(0);

        if(!standardCharTestSet)
        {
            QFile::copy(charTestDirs[0]->path() + "\\" + temp->text(0), charTrainDirs[label]->path() + "\\" + charTrainImgFileNames[label].at(charTrainImgFileNames[label].size() - 1));
        }
        else {
            int formerLabel = temp->whatsThis(0).section(".",0,0).toInt();
            switch (currentPlateFrom) {
                case 2:
                    QFile::copy(charTestDirs[formerLabel]->path() + "\\" + temp->text(0), charTrainDirs[label]->path() + "\\" + charTrainImgFileNames[label].at(charTrainImgFileNames[label].size() - 1));
                    break;
                case 3:
                    QFile::copy(charSingleOrErrorDirs[formerLabel]->path() + "\\" + temp->text(0), charTrainDirs[label]->path() + "\\" + charTrainImgFileNames[label].at(charTrainImgFileNames[label].size() - 1));
                    break;
            }
        }

        if(currentCharFrom == 3)
        {
            QTreeWidgetItem *temp = this->ui->singleOrErrorCharTree->currentItem();
            charSingleOrErrorImgFileNames[temp->whatsThis(0).section(".",0,0).toInt()].removeAt(temp->whatsThis(0).section(".",1,1).toInt());
            errorCharTag.removeAt(temp->whatsThis(0).section(".",1,1).toInt());
            refreshCharSingleOrErrorTree();
            this->ui->singleOrErrorCharTree->expandItem(this->ui->singleOrErrorCharTree->topLevelItem(temp->whatsThis(0).section(".",0,0).toInt()));
        }
        refreshCharSampleTree();
        this->ui->charSampleTree->expandItem(this->ui->charSampleTree->topLevelItem(label));
        return;
    }

    if(!Property::charTrainPathDefault)
    {
        Property::charTrainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::charTrainPath);
        if(Property::charTrainPath.isEmpty()) return;
    }

    if(!QDir(Property::charTrainPath).exists())
    {
        QMessageBox::information(this, "Error!", "路径有误！", QMessageBox::Ok);
        return;
    }

    if(!PlateChar_SVM::PrepareCharTrainningDirectory(Property::charTrainPath))
    {
        QMessageBox::about(NULL, "Warning!", "训练库装载失败!");
        return;
    }

    QTreeWidgetItem *temp = this->ui->charTestTree->currentItem();
    if(temp == nullptr)
    {
        QMessageBox::information(this, "Error!", "装入失败！");
        return;
    }

    if(!standardCharTestSet)
    {
        QFile::copy(charTestDirs[0]->path() + "\\" + temp->text(0), Property::charTrainPath + "\\plates\\" + PlateCharString[this->ui->charTestResultCombo->currentIndex()] + "\\" + temp->text(0));
    }else {
        int formerLabel;
        switch (currentCharFrom) {
            case 2:
                formerLabel = this->ui->charTestTree->currentItem()->whatsThis(0).section(".",0,0).toInt();
                QFile::copy(charTestDirs[formerLabel]->path() + "\\" + temp->text(0), charTrainDirs[label]->path() + "\\" + charTrainImgFileNames[label].at(charTrainImgFileNames[label].size() - 1));
                break;
            case 3:
                formerLabel = this->ui->singleOrErrorCharTree->currentItem()->whatsThis(0).section(".",0,0).toInt();
                QFile::copy(charSingleOrErrorDirs[formerLabel]->path() + "\\" + temp->text(0), charTrainDirs[label]->path() + "\\" + charTrainImgFileNames[label].at(charTrainImgFileNames[label].size() - 1));
                break;
        }
    }

    if(currentCharFrom == 3)
    {
        QTreeWidgetItem *temp = this->ui->singleOrErrorCharTree->currentItem();
        charSingleOrErrorImgFileNames[temp->whatsThis(0).section(".",0,0).toInt()].removeAt(temp->whatsThis(0).section(".",1,1).toInt());
        errorCharTag.removeAt(temp->whatsThis(0).section(".",1,1).toInt());
        refreshCharSingleOrErrorTree();
    }

    charConsoleOutput("操作完成");
}

//批量测试字符
void SVMTrainner::on_startCharTestButton_clicked()
{
    if(charTestDirs.empty())
    {
        QMessageBox::information(this, "Warnning!", "无效的测试集!", QMessageBox::Ok);
        return;
    }

    if(!PlateChar_SVM::isReady)
    {
        QMessageBox::information(this, "Warnning!", "请先进行训练或载入训练成果", QMessageBox::Ok);
        return;
    }

    if(charTestThread != nullptr)
    {
        QMessageBox::information(this, "Warnning!", "请等待当前测试完成！", QMessageBox::Ok);
        return;
    }

    charTestResults.clear();
    charSingleOrErrorDirs.clear();
    charSingleOrErrorImgFileNames.clear();

    if(standardCharTestSet)
    {
        for(int k = 0; k < PlateCharString.size(); k++)
        {
            charSingleOrErrorDirs.insert(k, charTestDirs[k]);
            charSingleOrErrorImgFileNames.insert(k, QStringList());
        }
    }

    charTestThread = new PlateTestThread(standardCharTestSet, charTestDirs, charTestImgFileNames, false);
    connect(charTestThread,&PlateTestThread::testResult,this,&SVMTrainner::testedOneChar);
    connect(charTestThread,&PlateTestThread::standardTestResult,this,&SVMTrainner::standardTestedOneChar);
    connect(charTestThread,&PlateTestThread::finished,this,&SVMTrainner::finishTestingChar);

    charTestThread->start();
}

void SVMTrainner::testedOneChar(int i, int tag)
{
    charTestResults.insert(i, tag);
    charConsoleOutput(charTestDirs[0]->path() + "/" + charTestImgFileNames[0].at(i) + "测试完成，预测结果:" + PlateCharString[tag]);
}

void SVMTrainner::standardTestedOneChar(int k, int i, int index, int tag)
{
    charTestResults.insert(index, tag);
    if(tag != k)
    {
        errorCharTag.insert(errorCharTag.size() - 1, tag);
        charSingleOrErrorImgFileNames[k].insert(charSingleOrErrorImgFileNames[k].size() - 1, charTestImgFileNames[k].at(i));
    }
    charConsoleOutput(charTestDirs[k]->path() + "/" + charTestImgFileNames[k].at(i) + "测试完成，预测结果:" + PlateCharString[tag]);
}

void SVMTrainner::finishTestingChar()
{
    if(!standardCharTestSet)
    {
        charConsoleOutput(QString::number(charTestSum) + "个非标准样本的测试已结束");
    }
    else {
        QString output = "";
        output += QString::number(charTestSum) + "个标准样本的测试结束，共有" + QString::number(errorCharTag.size()) + "个错误,正确率 " + QString::number((float)(1.0f - ((float)errorCharTag.size()) / ((float)charTestSum))*100, 'f', 3) + "%，其中\n";
        for(int k = 0; k < charTestDirs.size(); k++)
        {
            output += PlateCharString[k] + " " + QString::number(charTestImgFileNames[k].size()) + "个，错误" + QString::number(charSingleOrErrorImgFileNames[k].size()) + "个，正确率 " + QString::number((float)(1.0f - ((float)charSingleOrErrorImgFileNames[k].size()) / ((float)charTestImgFileNames[k].size()))*100, 'f', 3) + "%";
            if(k != charSingleOrErrorDirs.size() - 1) output += "\n";
        }
        charConsoleOutput(output);
    }
    charTestThread->terminate();
    charTestThread->exit();
    charTestThread->destroyed();
    free(charTestThread);
    charTestThread = nullptr;
    afterCharTest = true;
    refreshCharTestSampleTree();
}

//查看错误字符
void SVMTrainner::on_singleOrErrorCharTree_itemClicked(QTreeWidgetItem *item, int column)
{
    this->ui->charOriginalLabel->clear();
    this->ui->charHogLabel->clear();
    this->ui->charSampleImfo->hide();
    this->ui->rightCharTag->show();

    if(item->whatsThis(0).split(".").size() == 1)
    {
        this->ui->charTestImfo->hide();
        return;
    }

    currentCharFrom = 3;
    this->ui->charTestImfo->show();
    this->ui->testCharSampleName->setText(item->text(0));

    int index = item->whatsThis(0).section(".",0,0).toInt();

    cv::Mat originalMat = cv::imread(charSingleOrErrorDirs[index]->path().toLocal8Bit().toStdString() + "\\" + item->text(0).toLocal8Bit().toStdString(),cv::ImreadModes::IMREAD_GRAYSCALE);
    if(originalMat.empty())
    {
        QMessageBox::information(NULL, "Warnning", "该图片路径有误！请刷新系统",QMessageBox::Ok);
        return;
    }

    this->ui->testCharSampleSize->setText(QString::number(originalMat.cols) + " x " + QString::number(originalMat.rows));

    cv::Mat resizedMat;
    cv::resize(originalMat, resizedMat, cv::Size(this->ui->charOriginalLabel->size().width(), this->ui->charOriginalLabel->size().height()));

    QImage image = Mat2QImage(resizedMat,QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(image);
    this->ui->charOriginalLabel->setPixmap(pixmap);

    cv::resize(originalMat, resizedMat, PlateChar_SVM::HOGWinSize);
    std::vector<float> descriptor = PlateChar_SVM::ComputeHogDescriptors(resizedMat);
    this->ui->testCharHogSize->setText(QString::number(descriptor.size()));

    cv::Mat hogMat = getHogdescriptorVisualImage(resizedMat, descriptor, PlateChar_SVM::HOGWinSize, PlateChar_SVM::HOGCellSize, 1, 2.0);

    cv::resize(hogMat, hogMat, cv::Size(this->ui->charHogLabel->size().width(), this->ui->charHogLabel->size().height()));
    image = Mat2QImage(hogMat,QImage::Format_Grayscale8);
    pixmap = QPixmap::fromImage(image);
    this->ui->charHogLabel->setPixmap(pixmap);

    this->ui->charTestRighTagCombo->setCurrentIndex(item->whatsThis(0).section(".",0,0).toInt() + 1);
    this->ui->charTestResultCombo->setCurrentIndex(item->whatsThis(0).section(".",2,2).toInt());
    this->ui->charTestResult->show();
    this->ui->rightCharTag->show();
}
