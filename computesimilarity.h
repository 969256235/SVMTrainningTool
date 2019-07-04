#ifndef COMPUTESIMILARITY_H
#define COMPUTESIMILARITY_H

#include <QObject>
#include <QThread>
#include <QDir>
#include <QTime>
#include <opencv2/opencv.hpp>

#include "property.h"

class computeSimilarity : public QThread
{
    Q_OBJECT
public:
    computeSimilarity(QList<QDir*> dirs_, QList<QStringList> imgFileNames_, bool mode_);

    float computeSimilarityOfMats(cv::Mat mat1, QString matPath2);

    bool doing; //判断是否继续运算

    void stopComputing();

signals:
    void deleteItem(int k, int j);
    void consoleWrite(QString consoleLine);
    void finishedWork();

public slots:

protected:
    virtual void run();

private:
    cv::Size HOGWinSize = cv::Size(16, 16);
    cv::Size HOGBlockSize = cv::Size(16, 16);
    cv::Size HOGBlockStride = cv::Size(8,8);
    cv::Size HOGCellSize = cv::Size(8, 8);
    int HOGNBits = 9;
    cv::HOGDescriptor *hog = new cv::HOGDescriptor(HOGWinSize, HOGBlockSize, HOGBlockStride, HOGCellSize, HOGNBits);

    bool mode; //true:Plate false:Char

    QList<QDir*> dirs; //文件夹路径
    QList<QStringList> imgFileNames; //文件名
};

#endif // COMPUTESIMILARITY_H
