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

    float computeSimilarityOfMats(QString matPath1, QString matPath2);

signals:
    void deleteItem(int k, int j);
    void consoleWrite(QString consoleLine);
    void finished();

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

    QList<QDir*> dirs;
    QList<QStringList> imgFileNames;
};

#endif // COMPUTESIMILARITY_H
