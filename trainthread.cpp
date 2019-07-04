#include "trainthread.h"

TrainThread::TrainThread(QList<QDir*> trainDirs_, QList<QStringList> imgFileNames_, int sum_, bool mode_)
{
    this->trainDirs = trainDirs_;
    this->imgFileNames = imgFileNames_;
    this->sum = sum_;
    this->mode = mode_;
}

void TrainThread::run()
{
    int i, k;

    QList<int> labels; //标签队列

    cv::Mat mat;
    std::vector<float> descriptor; //描述符

    if(sum == 0)
    {
        emit finishedWork();    //无样本，直接退出
        return;
    }

    cv::Mat descriptorMat = cv::Mat::zeros(sum, mode ? (PlateCategory_SVM::HOGSize):(PlateChar_SVM::HOGSize), CV_32FC1); //建立描述符矩阵，sum行，HOG维度列

    i = 0;
    for(k = 0; k < imgFileNames.size(); k++)
    {
        for (QString imgFileName : imgFileNames[k])
        {
            QString filePath = trainDirs[k]->path() + "\\" + imgFileName;
            std::string str = filePath.toLocal8Bit().toStdString();
            mat = cv::imread(str, cv::ImreadModes::IMREAD_GRAYSCALE);

            if(mode)
                descriptor = PlateCategory_SVM::ComputeHogDescriptors(mat);
            else
                descriptor = PlateChar_SVM::ComputeHogDescriptors(mat);

            for(int j = 0; j < (mode ? (PlateCategory_SVM::HOGSize):(PlateChar_SVM::HOGSize)); j++)
            {
                descriptorMat.at<float>(i, j) = descriptor.at(j);
            }
            labels.insert(labels.size(), k);
            i++;
        }
    }

    cv::Mat labelMat = cv::Mat(sum, 1, CV_32SC1);

    for(i = 0; i < sum; i++)
    {
        labelMat.at<int>(i, 0) = labels[i];
    }

    if(mode)
        PlateCategory_SVM::Train(descriptorMat, labelMat);
    else
        PlateChar_SVM::Train(descriptorMat, labelMat);

    emit finishedWork();
}


