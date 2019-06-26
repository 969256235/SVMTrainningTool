﻿#ifndef SVMTRAINNER_H
#define SVMTRAINNER_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QListWidgetItem>

#include "plateproperty.h"
#include "platecategory_svm.h"

namespace Ui {
class SVMTrainner;
}

class SVMTrainner : public QMainWindow
{
    Q_OBJECT

public:
    explicit SVMTrainner(QWidget *parent = nullptr);
    ~SVMTrainner();

private slots:
    void on_platePropertyButton_clicked();

    void on_plateTrainButton_clicked();

    void on_loadPlateSetButton_clicked();

    void on_plateSampleTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_plateSampleChangeButton_clicked();

    void on_plateSampleDeleteButton_clicked();

private:
    cv::Size HOGWinSize = cv::Size(16, 16);
    cv::Size HOGBlockSize = cv::Size(16, 16);
    cv::Size HOGBlockStride = cv::Size(8,8);
    cv::Size HOGCellSize = cv::Size(8, 8);
    int HOGNBits = 9;
    cv::HOGDescriptor *hog = new cv::HOGDescriptor(HOGWinSize, HOGBlockSize, HOGBlockStride, HOGCellSize, HOGNBits);

    int sum;

    QList<QDir*> plateTrainDirs;
    QList<QStringList> plateTrainImgFileNames;

    QList<QDir*> plateTestDirs;
    QList<QStringList> platTestImgFileNames;

    Ui::SVMTrainner *ui;

    float computeSimilarity(QString matPath1, QString matPath2);

    cv::Mat getHogdescriptorVisualImage(cv::Mat& origImg,
        std::vector<float>& descriptorValues,
        cv::Size winSize,
        cv::Size cellSize,
        int scaleFactor,
        double viz_factor);

    QImage Mat2QImage(cv::Mat mat, QImage::Format format);

    void refreshPlateSampleTree();
};

#endif // SVMTRAINNER_H