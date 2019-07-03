#ifndef SVMTRAINNER_H
#define SVMTRAINNER_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QThread>
#include <QTimer>

#include "plateproperty.h"
#include "platecategory_svm.h"
#include "platechar_svm.h"
#include "computesimilarity.h"
#include "platetestthread.h"
#include "charproperty.h"
#include "trainthread.h"

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

signals:
    void stopComputingSimilarity();

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

    void on_charSampleChangeButton_clicked();

    void on_charSampleDeleteButton_clicked();

    void on_loadCharTestSetButton_clicked();

    void on_charTestTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_testCharChangeTagButton_clicked();

    void on_charRefreshButton_clicked();

    void on_generateCharTestSetButton_clicked();

    void on_equalizeCharTrainButton_clicked();

    void on_loadCharTrainResultButton_clicked();

    void on_singleCharTestButton_clicked();

    void on_correctCharButton_clicked();

    void on_startCharTestButton_clicked();

    void on_singleOrErrorCharTree_itemClicked(QTreeWidgetItem *item, int column);

private:
    class computeSimilarity *computerThread; //车牌相似度比较线程
    class PlateTestThread *plateTestThread; //车牌批量测试线程

    class computeSimilarity *charComputerThread; //字符相似度比对线程
    class PlateTestThread *charTestThread; //字符批量测试线程

    class TrainThread *plateTrainThread; //车牌训练线程
    class TrainThread *charTrainThread; //车牌训练线程

    int sampleSum; //车牌训练集样本数
    int testSum; //车牌测试集样本数
    int currentPlateFrom = 0; //表示用户正在窗口中查看的图片来自哪个集

    int charSampleSum; //字符训练集样本数
    int charTestSum; //字符测试集样本数
    int currentCharFrom = 0; //表示用户正在窗口中查看的字符图片来自哪个集

    QList<int> plateTestResults; //测试集测试结果列
    QList<int> errorPlateTag;   //车牌错误标签列
    bool standardPlateTestSet = false;  //车牌测试集是否已标签化

    QList<int> charTestResults; //字符测试结果列
    QList<int> errorCharTag;    //错误的车牌测试结果列
    bool standardCharTestSet = false;   //字符测试集是否标签化

    bool plateTrainned = false; //已进行了车牌训练

    bool afterTest = false; //已进行了车牌测试

    bool singleTest = false;    //测试了单张车牌

    bool charTrainned = false;  //已进行了字符训练

    bool afterCharTest = false; //已进行了字符测试

    bool singleCharTest = false; //测试了单张字符

    QList<QDir*> plateTrainDirs;    //车牌训练集根文件夹目录
    QList<QStringList> plateTrainImgFileNames;  //车牌训练集文件名

    QList<QDir*> plateTestDirs; //车牌测试集文件夹目录
    QList<QStringList> plateTestImgFileNames;   //车牌测试集文件名

    QList<QDir*> plateSingleOrErrorDirs;    //标准车牌测试集测试后找到的错误图路径队列
    QList<QStringList> plateSingleOrErrorImgFileNames;  //标准车牌测试集测试后找到的错误图文件名

    QList<QDir*> charTrainDirs; //字符训练集文件夹目录
    QList<QStringList> charTrainImgFileNames;   //字符训练集文件名目录

    QList<QDir*> charTestDirs;  //字符测试集文件夹目录
    QList<QStringList> charTestImgFileNames;    //字符测试集文件名目录

    QList<QDir*> charSingleOrErrorDirs; //标准字符测试集测试后找到的错误图的文件夹队列
    QList<QStringList> charSingleOrErrorImgFileNames;   //标准字符测试集测试后找到的错误图文件名目录

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

    void finishPlateTrain();

    //字符训练操作
    void refreshCharSampleTree();

    void refreshCharTestSampleTree();

    void refreshCharSingleOrErrorTree();

    void generateCharTestSetByTrainSet();

    void charSampleFilter(int k, int j);

    void charConsoleOutput(QString consoleLine);

    void finishedCharComputing();

    void testedOneChar(int i, int tag);

    void standardTestedOneChar(int k, int i, int index, int tag);

    void finishTestingChar();

    void finishCharTrain();
};

#endif // SVMTRAINNER_H
