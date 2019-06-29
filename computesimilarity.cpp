#include "computesimilarity.h"

computeSimilarity::computeSimilarity(QList<QDir *> dirs_, QList<QStringList> imgFileNames_)
{
    this->dirs = dirs_;
    this->imgFileNames = imgFileNames_;
}

float computeSimilarity::computeSimilarityOfMats(QString matPath1, QString matPath2)
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

void computeSimilarity::run()
{
    int i, j, k;

    float dis;
    for(k = 0; k < dirs.size(); k++)
    {
        for(i = 0; i < imgFileNames[k].size() - 1; i++)
            for(j = i + 1; j < imgFileNames[k].size(); j++)
            {
                QString consoleLine = "\n" + QTime::currentTime().toString() +  ":\nComputing the similarity of " + QString::number(i) + "th and " + QString::number(j) + "th images from the " + QString::number(k) + "th dircetory\n";
                consoleLine = QString::fromLocal8Bit(consoleLine.toUtf8());
                emit consoleWrite(consoleLine);
                dis = computeSimilarityOfMats(dirs[k]->path() + "\\" + imgFileNames[k].at(i), dirs[k]->path() + "\\" + imgFileNames[k].at(j));
                if(dis > Property::thresholdForSimilarity[k])
                {
                    imgFileNames[k].removeAt(j);
                    emit deleteItem(k, j);
                    j--;
                }
            }
    }
    emit finished();
}
