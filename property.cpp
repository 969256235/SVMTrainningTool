#include "property.h"

QString Property::plateTrainPath = "";
QString Property::plateResultPath = "";
QString Property::plateResultName = "plateLearned";
QString Property::plateTestPath = "";

bool Property::plateTrainPathDefault = false;
bool Property::plateResultPathDefault = false;
bool Property::plateTestLoadDefault = false;
bool Property::plateResultLoadDefault = false;

bool Property::similarityCheck = false;
float Property::thresholdForSimilarity[2] = {0.96f, 0.97f};

bool Property::generateTestSetByTrainSet = false;
short Property::testSetPercent = 30;
float Property::maxMultiple = 1.3f;
int Property::minPlateSampleNum = 300;

QString Property::charTrainPath = "";
QString Property::charResultPath = "";
QString Property::charResultName = "charLearned";
QString Property::charTestPath = "";

bool Property::charTrainPathDefault = false;
bool Property::charResultPathDefault = false;
bool Property::charTestLoadDefault = false;
bool Property::charResultLoadDefault = false;

bool Property::charSimilarityCheck = false;
float Property::charThresholdForSimilarity[4] = {0.96f, 0.97f, 0.95f, 0.95f};

bool Property::charGenerateTestSetByTrainSet = false;
short Property::charTestSetPercent = 30;
float Property::charMaxMultiple = 1.5f;
int Property::minCharSampleNum = 100;

Property::Property()
{

}
