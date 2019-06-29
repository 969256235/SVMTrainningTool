#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>

class Property
{
public:
    Property();

    static QString plateTrainPath; //车牌训练库路径
    static QString plateResultPath; //车牌训练结果路径
    static QString plateResultName; //车牌训练结果文件名
    static QString plateTestPath; //车牌测试集路径

    static bool plateTrainPathDefault; //是否使用默认车牌训练库路径
    static bool plateResultPathDefault; //是否使用默认的车牌训练结果路径
    static bool plateResultLoadDefault; //是否使用默认结果读取路径
    static bool plateTestLoadDefault; //是否使用默认测试集路径

    static bool similarityCheck; //是否做相似度剔除
    static float thresholdForSimilarity[2];

    static bool generateTestSetByTrainSet; //是否从训练集中抽取除测试集
    static short testSetPercent; //抽取测试集的比例
    static float maxMultiple; //允许的样本训练数据倍数差
    static int minPlateSampleNum;

    static QString charTrainPath; //车牌训练库路径
    static QString charResultPath; //车牌训练结果路径
    static QString charResultName; //车牌训练结果文件名
    static QString charTestPath; //车牌测试集路径

    static bool charTrainPathDefault; //是否使用默认车牌训练库路径
    static bool charResultPathDefault; //是否使用默认的车牌训练结果路径
    static bool charResultLoadDefault; //是否使用默认结果读取路径
    static bool charTestLoadDefault; //是否使用默认测试集路径

    static bool charSimilarityCheck; //是否做相似度剔除
    static float charThresholdForSimilarity[4];

    static bool charGenerateTestSetByTrainSet; //是否从训练集中抽取除测试集
    static short charTestSetPercent; //抽取测试集的比例
    static float charMaxMultiple; //允许的样本训练数据倍数差
    static int charMinPlateSampleNum;
};

#endif // PROPERTY_H
