#ifndef PLATETESTTHREAD_H
#define PLATETESTTHREAD_H

#include <QObject>
#include <QThread>
#include <QDir>
#include <QTime>
#include <opencv2/opencv.hpp>

#include "property.h"
#include "platecategory_svm.h"
#include "platechar_svm.h"

class PlateTestThread : public QThread
{
    Q_OBJECT
public:
    PlateTestThread(bool standard_, QList<QDir*> dirs_, QList<QStringList> imgFileNames_, bool mode_);


signals:
    void testResult(int i, int tag);
    void standardTestResult(int k, int i, int index, int tag);
    void finishedWork();

public slots:

protected:
    virtual void run();

private:
    bool standard;
    bool mode; //true-plate false-char

    QList<QDir*> dirs;
    QList<QStringList> imgFileNames;
};

#endif // PLATETESTTHREAD_H
