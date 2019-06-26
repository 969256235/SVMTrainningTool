﻿#include "property.h"

QString Property::plateTrainPath = "";
QString Property::plateResultPath = "";
QString Property::plateResultName = "WhatILearned";
QString Property::plateTestPath = "";

bool Property::plateTrainPathDefault = false;
bool Property::plateResultPathDefault = false;
bool Property::plateTestLoadDefault = false;
bool Property::plateRusultLoadDefault = false;

bool Property::similarityCheck = false;
float Property::thresholdForSimilarity[2] = {0.96f, 0.97f};

bool Property::generateTestSetByTrainSet = false;
short Property::testSetPercent = 30;

Property::Property()
{

}
