#ifndef SVMTRAINNER_H
#define SVMTRAINNER_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QThread>

#include "plateproperty.h"
#include "platecategory_svm.h"
#include "computesimilarity.h"

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

private:
    class computeSimilarity *computerThread;

    cv::Size HOGWinSize = cv::Size(16, 16);
    cv::Size HOGBlockSize = cv::Size(16, 16);
    cv::Size HOGBlockStride = cv::Size(8,8);
    cv::Size HOGCellSize = cv::Size(8, 8);
    int HOGNBits = 9;
    cv::HOGDescriptor *hog = new cv::HOGDescriptor(HOGWinSize, HOGBlockSize, HOGBlockStride, HOGCellSize, HOGNBits);

    int sampleSum;
    int testSum;
    int currentPlateFrom = 0;

    QList<int> plateTestResults;
    QList<int> errorPlateTag;
    bool standardPlateTestSet = false;

    bool plateTrainned = false;

    bool afterTest = false;

    bool singleTest = false;

    QList<QDir*> plateTrainDirs;
    QList<QStringList> plateTrainImgFileNames;

    QList<QDir*> plateTestDirs;
    QList<QStringList> plateTestImgFileNames;

    QList<QDir*> plateSingleOrErrorDirs;
    QList<QStringList> plateSingleOrErrorImgFileNames;

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

};

#endif // SVMTRAINNER_H
