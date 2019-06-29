﻿#ifndef SVMTRAINNER_H
#define SVMTRAINNER_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QThread>

#include "plateproperty.h"
#include "platecategory_svm.h"
#include "platechar_svm.h"
#include "computesimilarity.h"
#include "platetestthread.h"
#include "charproperty.h"

namespace Ui {
class SVMTrainner;
}

class SVMTrainner : public QMainWindow
{
    Q_OBJECT

public:
    explicit SVMTrainner(QWidget *parent = nullptr);
    ~SVMTrainner();

    bool trainSetLoaded = false;

    bool charTrainSetLoaded = false;

private slots:
    void on_platePropertyButton_clicked();

    void on_plateTrainButton_clicked();

    void on_loadPlateSetButton_clicked();

    void on_plateSampleTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_plateSampleChangeButton_clicked();

    void on_plateSampleDeleteButton_clicked();

    void on_loadPlateTestSetButton_clicked();

    void on_plateTestTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_testPlateChangeTagButton_clicked();

    void on_savePlateTrainButton_clicked();

    void on_plateRefreshButton_clicked();

    void on_generatePlateTestSetButton_clicked();

    void on_equalizePlateTrainButton_clicked();

    void on_loadPlateTrainResultButton_clicked();

    void on_singlePlateTestButton_clicked();

    void on_correctPlateButton_clicked();

    void on_singleOrErrorPlateTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_startPlateTestButton_clicked();

    void on_charPropertyButton_clicked();

    void on_loadCharSetButton_clicked();

    void on_charSampleTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_charTrainButton_clicked();

    void on_saveCharTrainButton_clicked();

private:
    class computeSimilarity *computerThread;
    class PlateTestThread *plateTestThread;

    class computeSimilarity *charComputerThread;
    class PlateTestThread *charTestThread;

    int sampleSum;
    int testSum;
    int currentPlateFrom = 0;

    int charSampleSum;
    int charTestSum;
    int currentCharFrom = 0;

    QList<int> plateTestResults;
    QList<int> errorPlateTag;
    bool standardPlateTestSet = false;

    QList<int> charTestResults;
    QList<int> errorCharTag;
    bool standardCharTestSet = false;

    bool plateTrainned = false;

    bool afterTest = false;

    bool singleTest = false;

    bool charTrainned = false;

    bool afterCharTest = false;

    bool singleCharTest = false;

    QList<QDir*> plateTrainDirs;
    QList<QStringList> plateTrainImgFileNames;

    QList<QDir*> plateTestDirs;
    QList<QStringList> plateTestImgFileNames;

    QList<QDir*> plateSingleOrErrorDirs;
    QList<QStringList> plateSingleOrErrorImgFileNames;

    QList<QDir*> charTrainDirs;
    QList<QStringList> charTrainImgFileNames;

    QList<QDir*> charTestDirs;
    QList<QStringList> charTestImgFileNames;

    QList<QDir*> charSingleOrErrorDirs;
    QList<QStringList> charSingleOrErrorImgFileNames;

    Ui::SVMTrainner *ui;

    cv::Mat getHogdescriptorVisualImage(cv::Mat& origImg,
        std::vector<float>& descriptorValues,
        cv::Size winSize,
        cv::Size cellSize,
        int scaleFactor,
        double viz_factor);

    QImage Mat2QImage(cv::Mat mat, QImage::Format format);

    void refreshPlateSampleTree();

    void refreshPlateTestSampleTree();

    void refreshSingleOrErrorTree();

    void generateTestSetByTrainSet();

    void sampleFilter(int k, int j);

    void consoleOutput(QString consoleLine);

    void finishedComputing();

    void testedOne(int i, int tag);

    void standardTestedOne(int k, int i, int index, int tag);

    void finishTesting();

    //字符训练操作
    void refreshCharSampleTree();

    void refreshCharTestSampleTree();

    void refreshCharSingleOrErrorTree();

    void generateCharTestSetByTrainSet();

    void charSampleFilter(int k, int j);

    void charConsoleOutput(QString consoleLine);

    void finishedCharComputing();

    //void testedOne(int i, int tag);

    //void standardTestedOne(int k, int i, int index, int tag);

    //void finishTesting();
};

#endif // SVMTRAINNER_H
