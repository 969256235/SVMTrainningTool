#ifndef TRAINTHREAD_H
#define TRAINTHREAD_H

#include <QThread>
#include <QDir>
#include <opencv2/opencv.hpp>

#include "platecategory_svm.h"
#include "platechar_svm.h"

class TrainThread : public QThread
{
    Q_OBJECT

signals:
    void finishedWork();

public:
    TrainThread(QList<QDir*> trainDirs_, QList<QStringList> imgFileNames_, int sum_, bool mode_);

protected:
    virtual void run();

private:
    bool mode; //true - plate / false - char
    int sum;

    QList<QDir*> trainDirs;
    QList<QStringList> imgFileNames;
};

#endif // TRAINTHREAD_H
