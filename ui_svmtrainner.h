/********************************************************************************
** Form generated from reading UI file 'svmtrainner.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SVMTRAINNER_H
#define UI_SVMTRAINNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SVMTrainner
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *mainTab;
    QWidget *plateTab;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *platePropertyButton;
    QPushButton *loadPlateSetButton;
    QPushButton *equalizePlateTrainButton;
    QPushButton *plateTrainButton;
    QPushButton *savePlateTrainButton;
    QPushButton *loadPlateTestSetButton;
    QPushButton *loadPlateTrainResultButton;
    QPushButton *plateRefreshButton;
    QPushButton *generatePlateTestSetButton;
    QPushButton *startPlateTestButton;
    QPushButton *singlePlateTestButton;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *plateSampleTree;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *plateGreyBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *plateOriginalLabel;
    QGroupBox *plateHogBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *plateHogLabel;
    QGroupBox *plateSampleImfoBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QWidget *plateSampleImfo;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *plateSampleImfoGrid;
    QLabel *plateSampleName;
    QLabel *plateHogSizeLabel;
    QLabel *plateHogSize;
    QPushButton *plateSampleChangeButton;
    QComboBox *plateSampleLabelCombo;
    QLabel *plateSampleLabelLabel;
    QLabel *plateSampleNameLabel;
    QLabel *plateSampleSize;
    QLabel *plateSampleSizeLabel;
    QPushButton *plateSampleDeleteButton;
    QWidget *plateTestImfo;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *testPlateHogSize;
    QLabel *testPlateSampleSize;
    QLabel *testPlateSampleSizeLabel;
    QLabel *testPlateHogSizeLabel;
    QLabel *testPlateSampleNameLabel;
    QLabel *testPlateSampleName;
    QWidget *rightPlateTag;
    QHBoxLayout *horizontalLayout_7;
    QLabel *testPlateSampleLabelLabel;
    QComboBox *plateTestRighTagCombo;
    QPushButton *testPlateChangeTagButton;
    QWidget *plateTestResult;
    QHBoxLayout *horizontalLayout_2;
    QLabel *plateTestResultLabel;
    QComboBox *plateTestResultCombo;
    QPushButton *correctPlateButton;
    QTreeWidget *plateTestTree;
    QVBoxLayout *verticalLayout_5;
    QTreeWidget *singleOrErrorPlateTree;
    QTextBrowser *plateConsole;
    QWidget *charTab;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *charTrainButtons;
    QPushButton *charPropertyButton;
    QPushButton *loadCharSetButton;
    QPushButton *equalizeCharTrainButton;
    QPushButton *charTrainButton;
    QPushButton *saveCharTrainButton;
    QPushButton *loadCharTestSetButton;
    QPushButton *loadCharTrainResultButton;
    QPushButton *charRefreshButton;
    QPushButton *generateCharTestSetButton;
    QPushButton *startCharTestButton;
    QPushButton *singleCharTestButton;
    QHBoxLayout *horizontalLayout_6;
    QTreeWidget *charSampleTree;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *charGreyBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *charOriginalLabel;
    QGroupBox *charHogBox;
    QHBoxLayout *horizontalLayout_11;
    QLabel *charHogLabel;
    QGroupBox *charSampleImfoBox;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_13;
    QWidget *charSampleImfo;
    QHBoxLayout *horizontalLayout_14;
    QGridLayout *plateSampleImfoGrid_2;
    QLabel *charSampleName;
    QLabel *charHogSizeLabel;
    QLabel *charHogSize;
    QPushButton *charSampleChangeButton;
    QComboBox *charSampleLabelCombo;
    QLabel *charSampleLabelLabel;
    QLabel *charSampleNameLabel;
    QLabel *charSampleSize;
    QLabel *charSampleSizeLabel;
    QPushButton *charSampleDeleteButton;
    QWidget *charTestImfo;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout_2;
    QLabel *testCharHogSize;
    QLabel *testCharSampleSize;
    QLabel *testCharSampleSizeLabel;
    QLabel *testCharHogSizeLabel;
    QLabel *testCharSampleNameLabel;
    QLabel *testCharSampleName;
    QWidget *rightCharTag;
    QHBoxLayout *horizontalLayout_15;
    QLabel *testCharSampleLabelLabel;
    QComboBox *charTestRighTagCombo;
    QPushButton *testCharChangeTagButton;
    QWidget *charTestResult;
    QHBoxLayout *horizontalLayout_16;
    QLabel *charTestResultLabel;
    QComboBox *charTestResultCombo;
    QPushButton *correctCharButton;
    QTreeWidget *charTestTree;
    QVBoxLayout *verticalLayout_12;
    QTreeWidget *singleOrErrorCharTree;
    QTextBrowser *charConsole;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *SVMTrainner)
    {
        if (SVMTrainner->objectName().isEmpty())
            SVMTrainner->setObjectName(QString::fromUtf8("SVMTrainner"));
        SVMTrainner->resize(1031, 669);
        centralWidget = new QWidget(SVMTrainner);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        mainTab = new QTabWidget(centralWidget);
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        mainTab->setIconSize(QSize(32, 32));
        plateTab = new QWidget();
        plateTab->setObjectName(QString::fromUtf8("plateTab"));
        verticalLayout_6 = new QVBoxLayout(plateTab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        platePropertyButton = new QPushButton(plateTab);
        platePropertyButton->setObjectName(QString::fromUtf8("platePropertyButton"));

        horizontalLayout_9->addWidget(platePropertyButton);

        loadPlateSetButton = new QPushButton(plateTab);
        loadPlateSetButton->setObjectName(QString::fromUtf8("loadPlateSetButton"));

        horizontalLayout_9->addWidget(loadPlateSetButton);

        equalizePlateTrainButton = new QPushButton(plateTab);
        equalizePlateTrainButton->setObjectName(QString::fromUtf8("equalizePlateTrainButton"));

        horizontalLayout_9->addWidget(equalizePlateTrainButton);

        plateTrainButton = new QPushButton(plateTab);
        plateTrainButton->setObjectName(QString::fromUtf8("plateTrainButton"));

        horizontalLayout_9->addWidget(plateTrainButton);

        savePlateTrainButton = new QPushButton(plateTab);
        savePlateTrainButton->setObjectName(QString::fromUtf8("savePlateTrainButton"));

        horizontalLayout_9->addWidget(savePlateTrainButton);

        loadPlateTestSetButton = new QPushButton(plateTab);
        loadPlateTestSetButton->setObjectName(QString::fromUtf8("loadPlateTestSetButton"));

        horizontalLayout_9->addWidget(loadPlateTestSetButton);

        loadPlateTrainResultButton = new QPushButton(plateTab);
        loadPlateTrainResultButton->setObjectName(QString::fromUtf8("loadPlateTrainResultButton"));

        horizontalLayout_9->addWidget(loadPlateTrainResultButton);

        plateRefreshButton = new QPushButton(plateTab);
        plateRefreshButton->setObjectName(QString::fromUtf8("plateRefreshButton"));

        horizontalLayout_9->addWidget(plateRefreshButton);

        generatePlateTestSetButton = new QPushButton(plateTab);
        generatePlateTestSetButton->setObjectName(QString::fromUtf8("generatePlateTestSetButton"));

        horizontalLayout_9->addWidget(generatePlateTestSetButton);

        startPlateTestButton = new QPushButton(plateTab);
        startPlateTestButton->setObjectName(QString::fromUtf8("startPlateTestButton"));

        horizontalLayout_9->addWidget(startPlateTestButton);

        singlePlateTestButton = new QPushButton(plateTab);
        singlePlateTestButton->setObjectName(QString::fromUtf8("singlePlateTestButton"));

        horizontalLayout_9->addWidget(singlePlateTestButton);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plateSampleTree = new QTreeWidget(plateTab);
        plateSampleTree->setObjectName(QString::fromUtf8("plateSampleTree"));
        plateSampleTree->setMinimumSize(QSize(129, 536));
        plateSampleTree->setMaximumSize(QSize(450, 16777215));
        plateSampleTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plateSampleTree->header()->setMinimumSectionSize(50);

        horizontalLayout->addWidget(plateSampleTree);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        plateGreyBox = new QGroupBox(plateTab);
        plateGreyBox->setObjectName(QString::fromUtf8("plateGreyBox"));
        plateGreyBox->setMinimumSize(QSize(329, 0));
        plateGreyBox->setMaximumSize(QSize(329, 16777215));
        horizontalLayout_8 = new QHBoxLayout(plateGreyBox);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        plateOriginalLabel = new QLabel(plateGreyBox);
        plateOriginalLabel->setObjectName(QString::fromUtf8("plateOriginalLabel"));

        horizontalLayout_8->addWidget(plateOriginalLabel);


        verticalLayout_3->addWidget(plateGreyBox);

        plateHogBox = new QGroupBox(plateTab);
        plateHogBox->setObjectName(QString::fromUtf8("plateHogBox"));
        plateHogBox->setMinimumSize(QSize(329, 0));
        plateHogBox->setMaximumSize(QSize(329, 16777215));
        verticalLayout_4 = new QVBoxLayout(plateHogBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        plateHogLabel = new QLabel(plateHogBox);
        plateHogLabel->setObjectName(QString::fromUtf8("plateHogLabel"));

        verticalLayout_4->addWidget(plateHogLabel);


        verticalLayout_3->addWidget(plateHogBox);

        plateSampleImfoBox = new QGroupBox(plateTab);
        plateSampleImfoBox->setObjectName(QString::fromUtf8("plateSampleImfoBox"));
        plateSampleImfoBox->setMinimumSize(QSize(329, 0));
        plateSampleImfoBox->setMaximumSize(QSize(329, 16777215));
        horizontalLayout_4 = new QHBoxLayout(plateSampleImfoBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        plateSampleImfo = new QWidget(plateSampleImfoBox);
        plateSampleImfo->setObjectName(QString::fromUtf8("plateSampleImfo"));
        plateSampleImfo->setEnabled(true);
        horizontalLayout_5 = new QHBoxLayout(plateSampleImfo);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        plateSampleImfoGrid = new QGridLayout();
        plateSampleImfoGrid->setSpacing(6);
        plateSampleImfoGrid->setObjectName(QString::fromUtf8("plateSampleImfoGrid"));
        plateSampleName = new QLabel(plateSampleImfo);
        plateSampleName->setObjectName(QString::fromUtf8("plateSampleName"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        plateSampleName->setFont(font);

        plateSampleImfoGrid->addWidget(plateSampleName, 0, 1, 1, 2);

        plateHogSizeLabel = new QLabel(plateSampleImfo);
        plateHogSizeLabel->setObjectName(QString::fromUtf8("plateHogSizeLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        plateHogSizeLabel->setFont(font1);

        plateSampleImfoGrid->addWidget(plateHogSizeLabel, 2, 0, 1, 1);

        plateHogSize = new QLabel(plateSampleImfo);
        plateHogSize->setObjectName(QString::fromUtf8("plateHogSize"));
        plateHogSize->setFont(font1);

        plateSampleImfoGrid->addWidget(plateHogSize, 2, 1, 1, 1);

        plateSampleChangeButton = new QPushButton(plateSampleImfo);
        plateSampleChangeButton->setObjectName(QString::fromUtf8("plateSampleChangeButton"));

        plateSampleImfoGrid->addWidget(plateSampleChangeButton, 3, 2, 1, 1);

        plateSampleLabelCombo = new QComboBox(plateSampleImfo);
        plateSampleLabelCombo->addItem(QString());
        plateSampleLabelCombo->addItem(QString());
        plateSampleLabelCombo->setObjectName(QString::fromUtf8("plateSampleLabelCombo"));
        plateSampleLabelCombo->setFont(font);

        plateSampleImfoGrid->addWidget(plateSampleLabelCombo, 3, 1, 1, 1);

        plateSampleLabelLabel = new QLabel(plateSampleImfo);
        plateSampleLabelLabel->setObjectName(QString::fromUtf8("plateSampleLabelLabel"));
        plateSampleLabelLabel->setFont(font1);

        plateSampleImfoGrid->addWidget(plateSampleLabelLabel, 3, 0, 1, 1);

        plateSampleNameLabel = new QLabel(plateSampleImfo);
        plateSampleNameLabel->setObjectName(QString::fromUtf8("plateSampleNameLabel"));
        plateSampleNameLabel->setFont(font1);

        plateSampleImfoGrid->addWidget(plateSampleNameLabel, 0, 0, 1, 1);

        plateSampleSize = new QLabel(plateSampleImfo);
        plateSampleSize->setObjectName(QString::fromUtf8("plateSampleSize"));
        plateSampleSize->setFont(font1);

        plateSampleImfoGrid->addWidget(plateSampleSize, 1, 1, 1, 1);

        plateSampleSizeLabel = new QLabel(plateSampleImfo);
        plateSampleSizeLabel->setObjectName(QString::fromUtf8("plateSampleSizeLabel"));
        plateSampleSizeLabel->setFont(font1);

        plateSampleImfoGrid->addWidget(plateSampleSizeLabel, 1, 0, 1, 1);

        plateSampleDeleteButton = new QPushButton(plateSampleImfo);
        plateSampleDeleteButton->setObjectName(QString::fromUtf8("plateSampleDeleteButton"));

        plateSampleImfoGrid->addWidget(plateSampleDeleteButton, 4, 2, 1, 1);


        horizontalLayout_5->addLayout(plateSampleImfoGrid);


        horizontalLayout_3->addWidget(plateSampleImfo);

        plateTestImfo = new QWidget(plateSampleImfoBox);
        plateTestImfo->setObjectName(QString::fromUtf8("plateTestImfo"));
        verticalLayout_2 = new QVBoxLayout(plateTestImfo);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        testPlateHogSize = new QLabel(plateTestImfo);
        testPlateHogSize->setObjectName(QString::fromUtf8("testPlateHogSize"));
        testPlateHogSize->setFont(font1);

        gridLayout->addWidget(testPlateHogSize, 2, 1, 1, 1);

        testPlateSampleSize = new QLabel(plateTestImfo);
        testPlateSampleSize->setObjectName(QString::fromUtf8("testPlateSampleSize"));
        testPlateSampleSize->setFont(font1);

        gridLayout->addWidget(testPlateSampleSize, 1, 1, 1, 1);

        testPlateSampleSizeLabel = new QLabel(plateTestImfo);
        testPlateSampleSizeLabel->setObjectName(QString::fromUtf8("testPlateSampleSizeLabel"));
        testPlateSampleSizeLabel->setFont(font1);

        gridLayout->addWidget(testPlateSampleSizeLabel, 1, 0, 1, 1);

        testPlateHogSizeLabel = new QLabel(plateTestImfo);
        testPlateHogSizeLabel->setObjectName(QString::fromUtf8("testPlateHogSizeLabel"));
        testPlateHogSizeLabel->setFont(font1);

        gridLayout->addWidget(testPlateHogSizeLabel, 2, 0, 1, 1);

        testPlateSampleNameLabel = new QLabel(plateTestImfo);
        testPlateSampleNameLabel->setObjectName(QString::fromUtf8("testPlateSampleNameLabel"));
        testPlateSampleNameLabel->setFont(font1);

        gridLayout->addWidget(testPlateSampleNameLabel, 0, 0, 1, 1);

        testPlateSampleName = new QLabel(plateTestImfo);
        testPlateSampleName->setObjectName(QString::fromUtf8("testPlateSampleName"));
        testPlateSampleName->setFont(font);

        gridLayout->addWidget(testPlateSampleName, 0, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        rightPlateTag = new QWidget(plateTestImfo);
        rightPlateTag->setObjectName(QString::fromUtf8("rightPlateTag"));
        horizontalLayout_7 = new QHBoxLayout(rightPlateTag);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        testPlateSampleLabelLabel = new QLabel(rightPlateTag);
        testPlateSampleLabelLabel->setObjectName(QString::fromUtf8("testPlateSampleLabelLabel"));
        testPlateSampleLabelLabel->setFont(font);

        horizontalLayout_7->addWidget(testPlateSampleLabelLabel);

        plateTestRighTagCombo = new QComboBox(rightPlateTag);
        plateTestRighTagCombo->addItem(QString());
        plateTestRighTagCombo->addItem(QString());
        plateTestRighTagCombo->addItem(QString());
        plateTestRighTagCombo->setObjectName(QString::fromUtf8("plateTestRighTagCombo"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(9);
        plateTestRighTagCombo->setFont(font2);

        horizontalLayout_7->addWidget(plateTestRighTagCombo);

        testPlateChangeTagButton = new QPushButton(rightPlateTag);
        testPlateChangeTagButton->setObjectName(QString::fromUtf8("testPlateChangeTagButton"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(8);
        testPlateChangeTagButton->setFont(font3);

        horizontalLayout_7->addWidget(testPlateChangeTagButton);


        verticalLayout->addWidget(rightPlateTag);

        plateTestResult = new QWidget(plateTestImfo);
        plateTestResult->setObjectName(QString::fromUtf8("plateTestResult"));
        horizontalLayout_2 = new QHBoxLayout(plateTestResult);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        plateTestResultLabel = new QLabel(plateTestResult);
        plateTestResultLabel->setObjectName(QString::fromUtf8("plateTestResultLabel"));
        plateTestResultLabel->setFont(font);

        horizontalLayout_2->addWidget(plateTestResultLabel);

        plateTestResultCombo = new QComboBox(plateTestResult);
        plateTestResultCombo->addItem(QString());
        plateTestResultCombo->addItem(QString());
        plateTestResultCombo->setObjectName(QString::fromUtf8("plateTestResultCombo"));
        plateTestResultCombo->setFont(font2);

        horizontalLayout_2->addWidget(plateTestResultCombo);

        correctPlateButton = new QPushButton(plateTestResult);
        correctPlateButton->setObjectName(QString::fromUtf8("correctPlateButton"));
        correctPlateButton->setFont(font3);

        horizontalLayout_2->addWidget(correctPlateButton);


        verticalLayout->addWidget(plateTestResult);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(plateTestImfo);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(plateSampleImfoBox);


        horizontalLayout->addLayout(verticalLayout_3);

        plateTestTree = new QTreeWidget(plateTab);
        plateTestTree->setObjectName(QString::fromUtf8("plateTestTree"));
        plateTestTree->setMinimumSize(QSize(129, 536));
        plateTestTree->setMaximumSize(QSize(450, 16777215));

        horizontalLayout->addWidget(plateTestTree);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        singleOrErrorPlateTree = new QTreeWidget(plateTab);
        singleOrErrorPlateTree->headerItem()->setText(0, QString());
        singleOrErrorPlateTree->setObjectName(QString::fromUtf8("singleOrErrorPlateTree"));
        singleOrErrorPlateTree->setMinimumSize(QSize(378, 150));
        singleOrErrorPlateTree->setMaximumSize(QSize(16777215, 150));

        verticalLayout_5->addWidget(singleOrErrorPlateTree);

        plateConsole = new QTextBrowser(plateTab);
        plateConsole->setObjectName(QString::fromUtf8("plateConsole"));

        verticalLayout_5->addWidget(plateConsole);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout);

        mainTab->addTab(plateTab, QString());
        charTab = new QWidget();
        charTab->setObjectName(QString::fromUtf8("charTab"));
        verticalLayout_9 = new QVBoxLayout(charTab);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        charTrainButtons = new QHBoxLayout();
        charTrainButtons->setSpacing(6);
        charTrainButtons->setObjectName(QString::fromUtf8("charTrainButtons"));
        charPropertyButton = new QPushButton(charTab);
        charPropertyButton->setObjectName(QString::fromUtf8("charPropertyButton"));

        charTrainButtons->addWidget(charPropertyButton);

        loadCharSetButton = new QPushButton(charTab);
        loadCharSetButton->setObjectName(QString::fromUtf8("loadCharSetButton"));

        charTrainButtons->addWidget(loadCharSetButton);

        equalizeCharTrainButton = new QPushButton(charTab);
        equalizeCharTrainButton->setObjectName(QString::fromUtf8("equalizeCharTrainButton"));

        charTrainButtons->addWidget(equalizeCharTrainButton);

        charTrainButton = new QPushButton(charTab);
        charTrainButton->setObjectName(QString::fromUtf8("charTrainButton"));

        charTrainButtons->addWidget(charTrainButton);

        saveCharTrainButton = new QPushButton(charTab);
        saveCharTrainButton->setObjectName(QString::fromUtf8("saveCharTrainButton"));

        charTrainButtons->addWidget(saveCharTrainButton);

        loadCharTestSetButton = new QPushButton(charTab);
        loadCharTestSetButton->setObjectName(QString::fromUtf8("loadCharTestSetButton"));

        charTrainButtons->addWidget(loadCharTestSetButton);

        loadCharTrainResultButton = new QPushButton(charTab);
        loadCharTrainResultButton->setObjectName(QString::fromUtf8("loadCharTrainResultButton"));

        charTrainButtons->addWidget(loadCharTrainResultButton);

        charRefreshButton = new QPushButton(charTab);
        charRefreshButton->setObjectName(QString::fromUtf8("charRefreshButton"));

        charTrainButtons->addWidget(charRefreshButton);

        generateCharTestSetButton = new QPushButton(charTab);
        generateCharTestSetButton->setObjectName(QString::fromUtf8("generateCharTestSetButton"));

        charTrainButtons->addWidget(generateCharTestSetButton);

        startCharTestButton = new QPushButton(charTab);
        startCharTestButton->setObjectName(QString::fromUtf8("startCharTestButton"));

        charTrainButtons->addWidget(startCharTestButton);

        singleCharTestButton = new QPushButton(charTab);
        singleCharTestButton->setObjectName(QString::fromUtf8("singleCharTestButton"));

        charTrainButtons->addWidget(singleCharTestButton);


        verticalLayout_9->addLayout(charTrainButtons);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        charSampleTree = new QTreeWidget(charTab);
        charSampleTree->setObjectName(QString::fromUtf8("charSampleTree"));
        charSampleTree->setMinimumSize(QSize(129, 536));
        charSampleTree->setMaximumSize(QSize(450, 16777215));
        charSampleTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        charSampleTree->header()->setMinimumSectionSize(50);

        horizontalLayout_6->addWidget(charSampleTree);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        charGreyBox = new QGroupBox(charTab);
        charGreyBox->setObjectName(QString::fromUtf8("charGreyBox"));
        charGreyBox->setMinimumSize(QSize(150, 0));
        charGreyBox->setMaximumSize(QSize(329, 16777215));
        horizontalLayout_10 = new QHBoxLayout(charGreyBox);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        charOriginalLabel = new QLabel(charGreyBox);
        charOriginalLabel->setObjectName(QString::fromUtf8("charOriginalLabel"));
        charOriginalLabel->setMinimumSize(QSize(150, 0));
        charOriginalLabel->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_10->addWidget(charOriginalLabel);


        verticalLayout_8->addWidget(charGreyBox);

        charHogBox = new QGroupBox(charTab);
        charHogBox->setObjectName(QString::fromUtf8("charHogBox"));
        charHogBox->setMinimumSize(QSize(329, 0));
        charHogBox->setMaximumSize(QSize(329, 16777215));
        horizontalLayout_11 = new QHBoxLayout(charHogBox);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        charHogLabel = new QLabel(charHogBox);
        charHogLabel->setObjectName(QString::fromUtf8("charHogLabel"));
        charHogLabel->setMinimumSize(QSize(150, 0));
        charHogLabel->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_11->addWidget(charHogLabel);


        verticalLayout_8->addWidget(charHogBox);

        charSampleImfoBox = new QGroupBox(charTab);
        charSampleImfoBox->setObjectName(QString::fromUtf8("charSampleImfoBox"));
        charSampleImfoBox->setMinimumSize(QSize(329, 0));
        charSampleImfoBox->setMaximumSize(QSize(329, 16777215));
        horizontalLayout_12 = new QHBoxLayout(charSampleImfoBox);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        charSampleImfo = new QWidget(charSampleImfoBox);
        charSampleImfo->setObjectName(QString::fromUtf8("charSampleImfo"));
        charSampleImfo->setEnabled(true);
        horizontalLayout_14 = new QHBoxLayout(charSampleImfo);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        plateSampleImfoGrid_2 = new QGridLayout();
        plateSampleImfoGrid_2->setSpacing(6);
        plateSampleImfoGrid_2->setObjectName(QString::fromUtf8("plateSampleImfoGrid_2"));
        charSampleName = new QLabel(charSampleImfo);
        charSampleName->setObjectName(QString::fromUtf8("charSampleName"));
        charSampleName->setFont(font);

        plateSampleImfoGrid_2->addWidget(charSampleName, 0, 1, 1, 2);

        charHogSizeLabel = new QLabel(charSampleImfo);
        charHogSizeLabel->setObjectName(QString::fromUtf8("charHogSizeLabel"));
        charHogSizeLabel->setFont(font1);

        plateSampleImfoGrid_2->addWidget(charHogSizeLabel, 2, 0, 1, 1);

        charHogSize = new QLabel(charSampleImfo);
        charHogSize->setObjectName(QString::fromUtf8("charHogSize"));
        charHogSize->setFont(font1);

        plateSampleImfoGrid_2->addWidget(charHogSize, 2, 1, 1, 1);

        charSampleChangeButton = new QPushButton(charSampleImfo);
        charSampleChangeButton->setObjectName(QString::fromUtf8("charSampleChangeButton"));

        plateSampleImfoGrid_2->addWidget(charSampleChangeButton, 3, 2, 1, 1);

        charSampleLabelCombo = new QComboBox(charSampleImfo);
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->addItem(QString());
        charSampleLabelCombo->setObjectName(QString::fromUtf8("charSampleLabelCombo"));
        charSampleLabelCombo->setFont(font);

        plateSampleImfoGrid_2->addWidget(charSampleLabelCombo, 3, 1, 1, 1);

        charSampleLabelLabel = new QLabel(charSampleImfo);
        charSampleLabelLabel->setObjectName(QString::fromUtf8("charSampleLabelLabel"));
        charSampleLabelLabel->setFont(font1);

        plateSampleImfoGrid_2->addWidget(charSampleLabelLabel, 3, 0, 1, 1);

        charSampleNameLabel = new QLabel(charSampleImfo);
        charSampleNameLabel->setObjectName(QString::fromUtf8("charSampleNameLabel"));
        charSampleNameLabel->setFont(font1);

        plateSampleImfoGrid_2->addWidget(charSampleNameLabel, 0, 0, 1, 1);

        charSampleSize = new QLabel(charSampleImfo);
        charSampleSize->setObjectName(QString::fromUtf8("charSampleSize"));
        charSampleSize->setFont(font1);

        plateSampleImfoGrid_2->addWidget(charSampleSize, 1, 1, 1, 1);

        charSampleSizeLabel = new QLabel(charSampleImfo);
        charSampleSizeLabel->setObjectName(QString::fromUtf8("charSampleSizeLabel"));
        charSampleSizeLabel->setFont(font1);

        plateSampleImfoGrid_2->addWidget(charSampleSizeLabel, 1, 0, 1, 1);

        charSampleDeleteButton = new QPushButton(charSampleImfo);
        charSampleDeleteButton->setObjectName(QString::fromUtf8("charSampleDeleteButton"));

        plateSampleImfoGrid_2->addWidget(charSampleDeleteButton, 4, 2, 1, 1);


        horizontalLayout_14->addLayout(plateSampleImfoGrid_2);


        horizontalLayout_13->addWidget(charSampleImfo);

        charTestImfo = new QWidget(charSampleImfoBox);
        charTestImfo->setObjectName(QString::fromUtf8("charTestImfo"));
        verticalLayout_10 = new QVBoxLayout(charTestImfo);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        testCharHogSize = new QLabel(charTestImfo);
        testCharHogSize->setObjectName(QString::fromUtf8("testCharHogSize"));
        testCharHogSize->setFont(font1);

        gridLayout_2->addWidget(testCharHogSize, 2, 1, 1, 1);

        testCharSampleSize = new QLabel(charTestImfo);
        testCharSampleSize->setObjectName(QString::fromUtf8("testCharSampleSize"));
        testCharSampleSize->setFont(font1);

        gridLayout_2->addWidget(testCharSampleSize, 1, 1, 1, 1);

        testCharSampleSizeLabel = new QLabel(charTestImfo);
        testCharSampleSizeLabel->setObjectName(QString::fromUtf8("testCharSampleSizeLabel"));
        testCharSampleSizeLabel->setFont(font1);

        gridLayout_2->addWidget(testCharSampleSizeLabel, 1, 0, 1, 1);

        testCharHogSizeLabel = new QLabel(charTestImfo);
        testCharHogSizeLabel->setObjectName(QString::fromUtf8("testCharHogSizeLabel"));
        testCharHogSizeLabel->setFont(font1);

        gridLayout_2->addWidget(testCharHogSizeLabel, 2, 0, 1, 1);

        testCharSampleNameLabel = new QLabel(charTestImfo);
        testCharSampleNameLabel->setObjectName(QString::fromUtf8("testCharSampleNameLabel"));
        testCharSampleNameLabel->setFont(font1);

        gridLayout_2->addWidget(testCharSampleNameLabel, 0, 0, 1, 1);

        testCharSampleName = new QLabel(charTestImfo);
        testCharSampleName->setObjectName(QString::fromUtf8("testCharSampleName"));
        testCharSampleName->setFont(font);

        gridLayout_2->addWidget(testCharSampleName, 0, 1, 1, 2);


        verticalLayout_11->addLayout(gridLayout_2);

        rightCharTag = new QWidget(charTestImfo);
        rightCharTag->setObjectName(QString::fromUtf8("rightCharTag"));
        horizontalLayout_15 = new QHBoxLayout(rightCharTag);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        testCharSampleLabelLabel = new QLabel(rightCharTag);
        testCharSampleLabelLabel->setObjectName(QString::fromUtf8("testCharSampleLabelLabel"));
        testCharSampleLabelLabel->setFont(font);

        horizontalLayout_15->addWidget(testCharSampleLabelLabel);

        charTestRighTagCombo = new QComboBox(rightCharTag);
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->addItem(QString());
        charTestRighTagCombo->setObjectName(QString::fromUtf8("charTestRighTagCombo"));
        charTestRighTagCombo->setFont(font);

        horizontalLayout_15->addWidget(charTestRighTagCombo);

        testCharChangeTagButton = new QPushButton(rightCharTag);
        testCharChangeTagButton->setObjectName(QString::fromUtf8("testCharChangeTagButton"));
        testCharChangeTagButton->setFont(font3);

        horizontalLayout_15->addWidget(testCharChangeTagButton);


        verticalLayout_11->addWidget(rightCharTag);

        charTestResult = new QWidget(charTestImfo);
        charTestResult->setObjectName(QString::fromUtf8("charTestResult"));
        horizontalLayout_16 = new QHBoxLayout(charTestResult);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        charTestResultLabel = new QLabel(charTestResult);
        charTestResultLabel->setObjectName(QString::fromUtf8("charTestResultLabel"));
        charTestResultLabel->setFont(font);

        horizontalLayout_16->addWidget(charTestResultLabel);

        charTestResultCombo = new QComboBox(charTestResult);
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->addItem(QString());
        charTestResultCombo->setObjectName(QString::fromUtf8("charTestResultCombo"));
        charTestResultCombo->setFont(font);

        horizontalLayout_16->addWidget(charTestResultCombo);

        correctCharButton = new QPushButton(charTestResult);
        correctCharButton->setObjectName(QString::fromUtf8("correctCharButton"));
        correctCharButton->setFont(font3);

        horizontalLayout_16->addWidget(correctCharButton);


        verticalLayout_11->addWidget(charTestResult);


        verticalLayout_10->addLayout(verticalLayout_11);


        horizontalLayout_13->addWidget(charTestImfo);


        horizontalLayout_12->addLayout(horizontalLayout_13);


        verticalLayout_8->addWidget(charSampleImfoBox);


        horizontalLayout_6->addLayout(verticalLayout_8);

        charTestTree = new QTreeWidget(charTab);
        charTestTree->setObjectName(QString::fromUtf8("charTestTree"));
        charTestTree->setMinimumSize(QSize(129, 536));
        charTestTree->setMaximumSize(QSize(450, 16777215));

        horizontalLayout_6->addWidget(charTestTree);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        singleOrErrorCharTree = new QTreeWidget(charTab);
        singleOrErrorCharTree->headerItem()->setText(0, QString());
        singleOrErrorCharTree->setObjectName(QString::fromUtf8("singleOrErrorCharTree"));
        singleOrErrorCharTree->setMinimumSize(QSize(378, 150));
        singleOrErrorCharTree->setMaximumSize(QSize(16777215, 150));

        verticalLayout_12->addWidget(singleOrErrorCharTree);

        charConsole = new QTextBrowser(charTab);
        charConsole->setObjectName(QString::fromUtf8("charConsole"));

        verticalLayout_12->addWidget(charConsole);


        horizontalLayout_6->addLayout(verticalLayout_12);


        verticalLayout_9->addLayout(horizontalLayout_6);

        mainTab->addTab(charTab, QString());

        verticalLayout_7->addWidget(mainTab);

        SVMTrainner->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(SVMTrainner);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SVMTrainner->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(SVMTrainner);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1031, 22));
        SVMTrainner->setMenuBar(menuBar);

        retranslateUi(SVMTrainner);

        mainTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SVMTrainner);
    } // setupUi

    void retranslateUi(QMainWindow *SVMTrainner)
    {
        SVMTrainner->setWindowTitle(QApplication::translate("SVMTrainner", "SVMTrainner", nullptr));
        platePropertyButton->setText(QApplication::translate("SVMTrainner", "\350\256\255\347\273\203\351\205\215\347\275\256", nullptr));
        loadPlateSetButton->setText(QApplication::translate("SVMTrainner", "\350\243\205\345\205\245\350\256\255\347\273\203\345\272\223", nullptr));
        equalizePlateTrainButton->setText(QApplication::translate("SVMTrainner", "\345\235\207\350\241\241\350\256\255\347\273\203\351\233\206", nullptr));
        plateTrainButton->setText(QApplication::translate("SVMTrainner", "\350\277\233\350\241\214\350\256\255\347\273\203", nullptr));
        savePlateTrainButton->setText(QApplication::translate("SVMTrainner", "\344\277\235\345\255\230\350\256\255\347\273\203\346\210\220\346\236\234", nullptr));
        loadPlateTestSetButton->setText(QApplication::translate("SVMTrainner", "\350\275\275\345\205\245\346\265\213\350\257\225\351\233\206", nullptr));
        loadPlateTrainResultButton->setText(QApplication::translate("SVMTrainner", "\345\212\240\350\275\275\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        plateRefreshButton->setText(QApplication::translate("SVMTrainner", "\345\210\267\346\226\260", nullptr));
        generatePlateTestSetButton->setText(QApplication::translate("SVMTrainner", "\347\224\237\346\210\220\346\265\213\350\257\225\351\233\206", nullptr));
        startPlateTestButton->setText(QApplication::translate("SVMTrainner", "\346\211\271\351\207\217\346\265\213\350\257\225", nullptr));
        singlePlateTestButton->setText(QApplication::translate("SVMTrainner", "\345\215\225\345\274\240\345\233\276\346\265\213\350\257\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = plateSampleTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SVMTrainner", "\346\240\267\346\234\254\351\233\206", nullptr));
        plateGreyBox->setTitle(QApplication::translate("SVMTrainner", "\347\201\260\345\272\246\345\233\276", nullptr));
        plateOriginalLabel->setText(QString());
        plateHogBox->setTitle(QApplication::translate("SVMTrainner", "Hog", nullptr));
        plateHogLabel->setText(QString());
        plateSampleImfoBox->setTitle(QApplication::translate("SVMTrainner", "Imfo", nullptr));
        plateSampleName->setText(QString());
        plateHogSizeLabel->setText(QApplication::translate("SVMTrainner", "HOG\347\273\264\345\272\246\357\274\232", nullptr));
        plateHogSize->setText(QString());
        plateSampleChangeButton->setText(QApplication::translate("SVMTrainner", "\346\233\264\346\224\271\346\240\207\347\255\276", nullptr));
        plateSampleLabelCombo->setItemText(0, QApplication::translate("SVMTrainner", "\351\235\236\350\275\246\347\211\214", nullptr));
        plateSampleLabelCombo->setItemText(1, QApplication::translate("SVMTrainner", "\346\231\256\351\200\232\350\275\246\347\211\214", nullptr));

        plateSampleLabelLabel->setText(QApplication::translate("SVMTrainner", "\346\240\207\347\255\276\357\274\232", nullptr));
        plateSampleNameLabel->setText(QApplication::translate("SVMTrainner", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        plateSampleSize->setText(QString());
        plateSampleSizeLabel->setText(QApplication::translate("SVMTrainner", "\345\216\237\345\233\276\345\260\272\345\257\270\357\274\232", nullptr));
        plateSampleDeleteButton->setText(QApplication::translate("SVMTrainner", "\345\210\240\351\231\244\346\240\267\346\234\254", nullptr));
        testPlateHogSize->setText(QString());
        testPlateSampleSize->setText(QString());
        testPlateSampleSizeLabel->setText(QApplication::translate("SVMTrainner", "\345\216\237\345\233\276\345\260\272\345\257\270\357\274\232", nullptr));
        testPlateHogSizeLabel->setText(QApplication::translate("SVMTrainner", "HOG\347\273\264\345\272\246\357\274\232", nullptr));
        testPlateSampleNameLabel->setText(QApplication::translate("SVMTrainner", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        testPlateSampleName->setText(QString());
        testPlateSampleLabelLabel->setText(QApplication::translate("SVMTrainner", "\346\255\243\347\241\256\346\240\207\347\255\276\357\274\232", nullptr));
        plateTestRighTagCombo->setItemText(0, QApplication::translate("SVMTrainner", "\346\234\252\347\237\245", nullptr));
        plateTestRighTagCombo->setItemText(1, QApplication::translate("SVMTrainner", "\351\235\236\350\275\246\347\211\214", nullptr));
        plateTestRighTagCombo->setItemText(2, QApplication::translate("SVMTrainner", "\346\231\256\351\200\232\350\275\246\347\211\214", nullptr));

        testPlateChangeTagButton->setText(QApplication::translate("SVMTrainner", "\346\233\264\346\224\271\346\240\207\347\255\276", nullptr));
        plateTestResultLabel->setText(QApplication::translate("SVMTrainner", "\346\265\213\350\257\225\347\273\223\346\236\234\357\274\232", nullptr));
        plateTestResultCombo->setItemText(0, QApplication::translate("SVMTrainner", "\351\235\236\350\275\246\347\211\214", nullptr));
        plateTestResultCombo->setItemText(1, QApplication::translate("SVMTrainner", "\346\231\256\351\200\232\350\275\246\347\211\214", nullptr));

        correctPlateButton->setText(QApplication::translate("SVMTrainner", "\345\212\240\345\205\245\350\256\255\347\273\203\345\272\223", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = plateTestTree->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("SVMTrainner", "\346\265\213\350\257\225\351\233\206", nullptr));
        mainTab->setTabText(mainTab->indexOf(plateTab), QApplication::translate("SVMTrainner", "\350\275\246\347\211\214\350\256\255\347\273\203", nullptr));
        charPropertyButton->setText(QApplication::translate("SVMTrainner", "\350\256\255\347\273\203\351\205\215\347\275\256", nullptr));
        loadCharSetButton->setText(QApplication::translate("SVMTrainner", "\350\243\205\345\205\245\350\256\255\347\273\203\345\272\223", nullptr));
        equalizeCharTrainButton->setText(QApplication::translate("SVMTrainner", "\345\235\207\350\241\241\350\256\255\347\273\203\351\233\206", nullptr));
        charTrainButton->setText(QApplication::translate("SVMTrainner", "\350\277\233\350\241\214\350\256\255\347\273\203", nullptr));
        saveCharTrainButton->setText(QApplication::translate("SVMTrainner", "\344\277\235\345\255\230\350\256\255\347\273\203\346\210\220\346\236\234", nullptr));
        loadCharTestSetButton->setText(QApplication::translate("SVMTrainner", "\350\275\275\345\205\245\346\265\213\350\257\225\351\233\206", nullptr));
        loadCharTrainResultButton->setText(QApplication::translate("SVMTrainner", "\345\212\240\350\275\275\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        charRefreshButton->setText(QApplication::translate("SVMTrainner", "\345\210\267\346\226\260", nullptr));
        generateCharTestSetButton->setText(QApplication::translate("SVMTrainner", "\347\224\237\346\210\220\346\265\213\350\257\225\351\233\206", nullptr));
        startCharTestButton->setText(QApplication::translate("SVMTrainner", "\346\211\271\351\207\217\346\265\213\350\257\225", nullptr));
        singleCharTestButton->setText(QApplication::translate("SVMTrainner", "\345\215\225\345\274\240\345\233\276\346\265\213\350\257\225", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = charSampleTree->headerItem();
        ___qtreewidgetitem2->setText(0, QApplication::translate("SVMTrainner", "\346\240\267\346\234\254\351\233\206", nullptr));
        charGreyBox->setTitle(QApplication::translate("SVMTrainner", "\347\201\260\345\272\246\345\233\276", nullptr));
        charOriginalLabel->setText(QString());
        charHogBox->setTitle(QApplication::translate("SVMTrainner", "Hog", nullptr));
        charHogLabel->setText(QString());
        charSampleImfoBox->setTitle(QApplication::translate("SVMTrainner", "Imfo", nullptr));
        charSampleName->setText(QString());
        charHogSizeLabel->setText(QApplication::translate("SVMTrainner", "HOG\347\273\264\345\272\246\357\274\232", nullptr));
        charHogSize->setText(QString());
        charSampleChangeButton->setText(QApplication::translate("SVMTrainner", "\346\233\264\346\224\271\346\240\207\347\255\276", nullptr));
        charSampleLabelCombo->setItemText(0, QApplication::translate("SVMTrainner", "\351\235\236\345\255\227\347\254\246", nullptr));
        charSampleLabelCombo->setItemText(1, QApplication::translate("SVMTrainner", "\347\251\227", nullptr));
        charSampleLabelCombo->setItemText(2, QApplication::translate("SVMTrainner", "A", nullptr));
        charSampleLabelCombo->setItemText(3, QApplication::translate("SVMTrainner", "B", nullptr));
        charSampleLabelCombo->setItemText(4, QApplication::translate("SVMTrainner", "C", nullptr));
        charSampleLabelCombo->setItemText(5, QApplication::translate("SVMTrainner", "D", nullptr));
        charSampleLabelCombo->setItemText(6, QApplication::translate("SVMTrainner", "E", nullptr));
        charSampleLabelCombo->setItemText(7, QApplication::translate("SVMTrainner", "F", nullptr));
        charSampleLabelCombo->setItemText(8, QApplication::translate("SVMTrainner", "G", nullptr));
        charSampleLabelCombo->setItemText(9, QApplication::translate("SVMTrainner", "H", nullptr));
        charSampleLabelCombo->setItemText(10, QApplication::translate("SVMTrainner", "I", nullptr));
        charSampleLabelCombo->setItemText(11, QApplication::translate("SVMTrainner", "J", nullptr));
        charSampleLabelCombo->setItemText(12, QApplication::translate("SVMTrainner", "K", nullptr));
        charSampleLabelCombo->setItemText(13, QApplication::translate("SVMTrainner", "L", nullptr));
        charSampleLabelCombo->setItemText(14, QApplication::translate("SVMTrainner", "M", nullptr));
        charSampleLabelCombo->setItemText(15, QApplication::translate("SVMTrainner", "N", nullptr));
        charSampleLabelCombo->setItemText(16, QApplication::translate("SVMTrainner", "O", nullptr));
        charSampleLabelCombo->setItemText(17, QApplication::translate("SVMTrainner", "P", nullptr));
        charSampleLabelCombo->setItemText(18, QApplication::translate("SVMTrainner", "Q", nullptr));
        charSampleLabelCombo->setItemText(19, QApplication::translate("SVMTrainner", "R", nullptr));
        charSampleLabelCombo->setItemText(20, QApplication::translate("SVMTrainner", "S", nullptr));
        charSampleLabelCombo->setItemText(21, QApplication::translate("SVMTrainner", "T", nullptr));
        charSampleLabelCombo->setItemText(22, QApplication::translate("SVMTrainner", "U", nullptr));
        charSampleLabelCombo->setItemText(23, QApplication::translate("SVMTrainner", "V", nullptr));
        charSampleLabelCombo->setItemText(24, QApplication::translate("SVMTrainner", "W", nullptr));
        charSampleLabelCombo->setItemText(25, QApplication::translate("SVMTrainner", "X", nullptr));
        charSampleLabelCombo->setItemText(26, QApplication::translate("SVMTrainner", "Y", nullptr));
        charSampleLabelCombo->setItemText(27, QApplication::translate("SVMTrainner", "Z", nullptr));
        charSampleLabelCombo->setItemText(28, QApplication::translate("SVMTrainner", "0", nullptr));
        charSampleLabelCombo->setItemText(29, QApplication::translate("SVMTrainner", "1", nullptr));
        charSampleLabelCombo->setItemText(30, QApplication::translate("SVMTrainner", "2", nullptr));
        charSampleLabelCombo->setItemText(31, QApplication::translate("SVMTrainner", "3", nullptr));
        charSampleLabelCombo->setItemText(32, QApplication::translate("SVMTrainner", "4", nullptr));
        charSampleLabelCombo->setItemText(33, QApplication::translate("SVMTrainner", "5", nullptr));
        charSampleLabelCombo->setItemText(34, QApplication::translate("SVMTrainner", "6", nullptr));
        charSampleLabelCombo->setItemText(35, QApplication::translate("SVMTrainner", "7", nullptr));
        charSampleLabelCombo->setItemText(36, QApplication::translate("SVMTrainner", "8", nullptr));
        charSampleLabelCombo->setItemText(37, QApplication::translate("SVMTrainner", "9", nullptr));
        charSampleLabelCombo->setItemText(38, QApplication::translate("SVMTrainner", "\347\202\271", nullptr));
        charSampleLabelCombo->setItemText(39, QApplication::translate("SVMTrainner", "\344\272\254", nullptr));
        charSampleLabelCombo->setItemText(40, QApplication::translate("SVMTrainner", "\346\264\245", nullptr));
        charSampleLabelCombo->setItemText(41, QApplication::translate("SVMTrainner", "\346\262\252", nullptr));
        charSampleLabelCombo->setItemText(42, QApplication::translate("SVMTrainner", "\346\270\235", nullptr));
        charSampleLabelCombo->setItemText(43, QApplication::translate("SVMTrainner", "\350\222\231", nullptr));
        charSampleLabelCombo->setItemText(44, QApplication::translate("SVMTrainner", "\346\226\260", nullptr));
        charSampleLabelCombo->setItemText(45, QApplication::translate("SVMTrainner", "\350\227\217", nullptr));
        charSampleLabelCombo->setItemText(46, QApplication::translate("SVMTrainner", "\345\256\201", nullptr));
        charSampleLabelCombo->setItemText(47, QApplication::translate("SVMTrainner", "\346\241\202", nullptr));
        charSampleLabelCombo->setItemText(48, QApplication::translate("SVMTrainner", "\346\270\257", nullptr));
        charSampleLabelCombo->setItemText(49, QApplication::translate("SVMTrainner", "\346\276\263", nullptr));
        charSampleLabelCombo->setItemText(50, QApplication::translate("SVMTrainner", "\351\273\221", nullptr));
        charSampleLabelCombo->setItemText(51, QApplication::translate("SVMTrainner", "\345\220\211", nullptr));
        charSampleLabelCombo->setItemText(52, QApplication::translate("SVMTrainner", "\350\276\275", nullptr));
        charSampleLabelCombo->setItemText(53, QApplication::translate("SVMTrainner", "\346\231\213", nullptr));
        charSampleLabelCombo->setItemText(54, QApplication::translate("SVMTrainner", "\345\206\200", nullptr));
        charSampleLabelCombo->setItemText(55, QApplication::translate("SVMTrainner", "\351\235\222", nullptr));
        charSampleLabelCombo->setItemText(56, QApplication::translate("SVMTrainner", "\351\262\201", nullptr));
        charSampleLabelCombo->setItemText(57, QApplication::translate("SVMTrainner", "\350\261\253", nullptr));
        charSampleLabelCombo->setItemText(58, QApplication::translate("SVMTrainner", "\350\213\217", nullptr));
        charSampleLabelCombo->setItemText(59, QApplication::translate("SVMTrainner", "\347\232\226", nullptr));
        charSampleLabelCombo->setItemText(60, QApplication::translate("SVMTrainner", "\346\265\231", nullptr));
        charSampleLabelCombo->setItemText(61, QApplication::translate("SVMTrainner", "\351\227\275", nullptr));
        charSampleLabelCombo->setItemText(62, QApplication::translate("SVMTrainner", "\350\265\243", nullptr));
        charSampleLabelCombo->setItemText(63, QApplication::translate("SVMTrainner", "\346\271\230", nullptr));
        charSampleLabelCombo->setItemText(64, QApplication::translate("SVMTrainner", "\351\204\202", nullptr));
        charSampleLabelCombo->setItemText(65, QApplication::translate("SVMTrainner", "\347\262\244", nullptr));
        charSampleLabelCombo->setItemText(66, QApplication::translate("SVMTrainner", "\347\220\274", nullptr));
        charSampleLabelCombo->setItemText(67, QApplication::translate("SVMTrainner", "\347\224\230", nullptr));
        charSampleLabelCombo->setItemText(68, QApplication::translate("SVMTrainner", "\351\231\225", nullptr));
        charSampleLabelCombo->setItemText(69, QApplication::translate("SVMTrainner", "\350\264\265", nullptr));
        charSampleLabelCombo->setItemText(70, QApplication::translate("SVMTrainner", "\344\272\221", nullptr));
        charSampleLabelCombo->setItemText(71, QApplication::translate("SVMTrainner", "\345\267\235", nullptr));
        charSampleLabelCombo->setItemText(72, QApplication::translate("SVMTrainner", "\350\255\246", nullptr));

        charSampleLabelLabel->setText(QApplication::translate("SVMTrainner", "\346\240\207\347\255\276\357\274\232", nullptr));
        charSampleNameLabel->setText(QApplication::translate("SVMTrainner", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        charSampleSize->setText(QString());
        charSampleSizeLabel->setText(QApplication::translate("SVMTrainner", "\345\216\237\345\233\276\345\260\272\345\257\270\357\274\232", nullptr));
        charSampleDeleteButton->setText(QApplication::translate("SVMTrainner", "\345\210\240\351\231\244\346\240\267\346\234\254", nullptr));
        testCharHogSize->setText(QString());
        testCharSampleSize->setText(QString());
        testCharSampleSizeLabel->setText(QApplication::translate("SVMTrainner", "\345\216\237\345\233\276\345\260\272\345\257\270\357\274\232", nullptr));
        testCharHogSizeLabel->setText(QApplication::translate("SVMTrainner", "HOG\347\273\264\345\272\246\357\274\232", nullptr));
        testCharSampleNameLabel->setText(QApplication::translate("SVMTrainner", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        testCharSampleName->setText(QString());
        testCharSampleLabelLabel->setText(QApplication::translate("SVMTrainner", "\346\255\243\347\241\256\346\240\207\347\255\276\357\274\232", nullptr));
        charTestRighTagCombo->setItemText(0, QApplication::translate("SVMTrainner", "\351\235\236\345\255\227\347\254\246", nullptr));
        charTestRighTagCombo->setItemText(1, QApplication::translate("SVMTrainner", "\347\251\227", nullptr));
        charTestRighTagCombo->setItemText(2, QApplication::translate("SVMTrainner", "A", nullptr));
        charTestRighTagCombo->setItemText(3, QApplication::translate("SVMTrainner", "B", nullptr));
        charTestRighTagCombo->setItemText(4, QApplication::translate("SVMTrainner", "C", nullptr));
        charTestRighTagCombo->setItemText(5, QApplication::translate("SVMTrainner", "D", nullptr));
        charTestRighTagCombo->setItemText(6, QApplication::translate("SVMTrainner", "E", nullptr));
        charTestRighTagCombo->setItemText(7, QApplication::translate("SVMTrainner", "F", nullptr));
        charTestRighTagCombo->setItemText(8, QApplication::translate("SVMTrainner", "G", nullptr));
        charTestRighTagCombo->setItemText(9, QApplication::translate("SVMTrainner", "H", nullptr));
        charTestRighTagCombo->setItemText(10, QApplication::translate("SVMTrainner", "I", nullptr));
        charTestRighTagCombo->setItemText(11, QApplication::translate("SVMTrainner", "J", nullptr));
        charTestRighTagCombo->setItemText(12, QApplication::translate("SVMTrainner", "K", nullptr));
        charTestRighTagCombo->setItemText(13, QApplication::translate("SVMTrainner", "L", nullptr));
        charTestRighTagCombo->setItemText(14, QApplication::translate("SVMTrainner", "M", nullptr));
        charTestRighTagCombo->setItemText(15, QApplication::translate("SVMTrainner", "N", nullptr));
        charTestRighTagCombo->setItemText(16, QApplication::translate("SVMTrainner", "O", nullptr));
        charTestRighTagCombo->setItemText(17, QApplication::translate("SVMTrainner", "P", nullptr));
        charTestRighTagCombo->setItemText(18, QApplication::translate("SVMTrainner", "Q", nullptr));
        charTestRighTagCombo->setItemText(19, QApplication::translate("SVMTrainner", "R", nullptr));
        charTestRighTagCombo->setItemText(20, QApplication::translate("SVMTrainner", "S", nullptr));
        charTestRighTagCombo->setItemText(21, QApplication::translate("SVMTrainner", "T", nullptr));
        charTestRighTagCombo->setItemText(22, QApplication::translate("SVMTrainner", "U", nullptr));
        charTestRighTagCombo->setItemText(23, QApplication::translate("SVMTrainner", "V", nullptr));
        charTestRighTagCombo->setItemText(24, QApplication::translate("SVMTrainner", "W", nullptr));
        charTestRighTagCombo->setItemText(25, QApplication::translate("SVMTrainner", "X", nullptr));
        charTestRighTagCombo->setItemText(26, QApplication::translate("SVMTrainner", "Y", nullptr));
        charTestRighTagCombo->setItemText(27, QApplication::translate("SVMTrainner", "Z", nullptr));
        charTestRighTagCombo->setItemText(28, QApplication::translate("SVMTrainner", "0", nullptr));
        charTestRighTagCombo->setItemText(29, QApplication::translate("SVMTrainner", "1", nullptr));
        charTestRighTagCombo->setItemText(30, QApplication::translate("SVMTrainner", "2", nullptr));
        charTestRighTagCombo->setItemText(31, QApplication::translate("SVMTrainner", "3", nullptr));
        charTestRighTagCombo->setItemText(32, QApplication::translate("SVMTrainner", "4", nullptr));
        charTestRighTagCombo->setItemText(33, QApplication::translate("SVMTrainner", "5", nullptr));
        charTestRighTagCombo->setItemText(34, QApplication::translate("SVMTrainner", "6", nullptr));
        charTestRighTagCombo->setItemText(35, QApplication::translate("SVMTrainner", "7", nullptr));
        charTestRighTagCombo->setItemText(36, QApplication::translate("SVMTrainner", "8", nullptr));
        charTestRighTagCombo->setItemText(37, QApplication::translate("SVMTrainner", "9", nullptr));
        charTestRighTagCombo->setItemText(38, QApplication::translate("SVMTrainner", "\347\202\271", nullptr));
        charTestRighTagCombo->setItemText(39, QApplication::translate("SVMTrainner", "\344\272\254", nullptr));
        charTestRighTagCombo->setItemText(40, QApplication::translate("SVMTrainner", "\346\264\245", nullptr));
        charTestRighTagCombo->setItemText(41, QApplication::translate("SVMTrainner", "\346\262\252", nullptr));
        charTestRighTagCombo->setItemText(42, QApplication::translate("SVMTrainner", "\346\270\235", nullptr));
        charTestRighTagCombo->setItemText(43, QApplication::translate("SVMTrainner", "\350\222\231", nullptr));
        charTestRighTagCombo->setItemText(44, QApplication::translate("SVMTrainner", "\346\226\260", nullptr));
        charTestRighTagCombo->setItemText(45, QApplication::translate("SVMTrainner", "\350\227\217", nullptr));
        charTestRighTagCombo->setItemText(46, QApplication::translate("SVMTrainner", "\345\256\201", nullptr));
        charTestRighTagCombo->setItemText(47, QApplication::translate("SVMTrainner", "\346\241\202", nullptr));
        charTestRighTagCombo->setItemText(48, QApplication::translate("SVMTrainner", "\346\270\257", nullptr));
        charTestRighTagCombo->setItemText(49, QApplication::translate("SVMTrainner", "\346\276\263", nullptr));
        charTestRighTagCombo->setItemText(50, QApplication::translate("SVMTrainner", "\351\273\221", nullptr));
        charTestRighTagCombo->setItemText(51, QApplication::translate("SVMTrainner", "\345\220\211", nullptr));
        charTestRighTagCombo->setItemText(52, QApplication::translate("SVMTrainner", "\350\276\275", nullptr));
        charTestRighTagCombo->setItemText(53, QApplication::translate("SVMTrainner", "\346\231\213", nullptr));
        charTestRighTagCombo->setItemText(54, QApplication::translate("SVMTrainner", "\345\206\200", nullptr));
        charTestRighTagCombo->setItemText(55, QApplication::translate("SVMTrainner", "\351\235\222", nullptr));
        charTestRighTagCombo->setItemText(56, QApplication::translate("SVMTrainner", "\351\262\201", nullptr));
        charTestRighTagCombo->setItemText(57, QApplication::translate("SVMTrainner", "\350\261\253", nullptr));
        charTestRighTagCombo->setItemText(58, QApplication::translate("SVMTrainner", "\350\213\217", nullptr));
        charTestRighTagCombo->setItemText(59, QApplication::translate("SVMTrainner", "\347\232\226", nullptr));
        charTestRighTagCombo->setItemText(60, QApplication::translate("SVMTrainner", "\346\265\231", nullptr));
        charTestRighTagCombo->setItemText(61, QApplication::translate("SVMTrainner", "\351\227\275", nullptr));
        charTestRighTagCombo->setItemText(62, QApplication::translate("SVMTrainner", "\350\265\243", nullptr));
        charTestRighTagCombo->setItemText(63, QApplication::translate("SVMTrainner", "\346\271\230", nullptr));
        charTestRighTagCombo->setItemText(64, QApplication::translate("SVMTrainner", "\351\204\202", nullptr));
        charTestRighTagCombo->setItemText(65, QApplication::translate("SVMTrainner", "\347\262\244", nullptr));
        charTestRighTagCombo->setItemText(66, QApplication::translate("SVMTrainner", "\347\220\274", nullptr));
        charTestRighTagCombo->setItemText(67, QApplication::translate("SVMTrainner", "\347\224\230", nullptr));
        charTestRighTagCombo->setItemText(68, QApplication::translate("SVMTrainner", "\351\231\225", nullptr));
        charTestRighTagCombo->setItemText(69, QApplication::translate("SVMTrainner", "\350\264\265", nullptr));
        charTestRighTagCombo->setItemText(70, QApplication::translate("SVMTrainner", "\344\272\221", nullptr));
        charTestRighTagCombo->setItemText(71, QApplication::translate("SVMTrainner", "\345\267\235", nullptr));
        charTestRighTagCombo->setItemText(72, QApplication::translate("SVMTrainner", "\350\255\246", nullptr));

        testCharChangeTagButton->setText(QApplication::translate("SVMTrainner", "\346\233\264\346\224\271\346\240\207\347\255\276", nullptr));
        charTestResultLabel->setText(QApplication::translate("SVMTrainner", "\346\265\213\350\257\225\347\273\223\346\236\234\357\274\232", nullptr));
        charTestResultCombo->setItemText(0, QApplication::translate("SVMTrainner", "\351\235\236\345\255\227\347\254\246", nullptr));
        charTestResultCombo->setItemText(1, QApplication::translate("SVMTrainner", "\347\251\227", nullptr));
        charTestResultCombo->setItemText(2, QApplication::translate("SVMTrainner", "A", nullptr));
        charTestResultCombo->setItemText(3, QApplication::translate("SVMTrainner", "B", nullptr));
        charTestResultCombo->setItemText(4, QApplication::translate("SVMTrainner", "C", nullptr));
        charTestResultCombo->setItemText(5, QApplication::translate("SVMTrainner", "D", nullptr));
        charTestResultCombo->setItemText(6, QApplication::translate("SVMTrainner", "E", nullptr));
        charTestResultCombo->setItemText(7, QApplication::translate("SVMTrainner", "F", nullptr));
        charTestResultCombo->setItemText(8, QApplication::translate("SVMTrainner", "G", nullptr));
        charTestResultCombo->setItemText(9, QApplication::translate("SVMTrainner", "H", nullptr));
        charTestResultCombo->setItemText(10, QApplication::translate("SVMTrainner", "I", nullptr));
        charTestResultCombo->setItemText(11, QApplication::translate("SVMTrainner", "J", nullptr));
        charTestResultCombo->setItemText(12, QApplication::translate("SVMTrainner", "K", nullptr));
        charTestResultCombo->setItemText(13, QApplication::translate("SVMTrainner", "L", nullptr));
        charTestResultCombo->setItemText(14, QApplication::translate("SVMTrainner", "M", nullptr));
        charTestResultCombo->setItemText(15, QApplication::translate("SVMTrainner", "N", nullptr));
        charTestResultCombo->setItemText(16, QApplication::translate("SVMTrainner", "O", nullptr));
        charTestResultCombo->setItemText(17, QApplication::translate("SVMTrainner", "P", nullptr));
        charTestResultCombo->setItemText(18, QApplication::translate("SVMTrainner", "Q", nullptr));
        charTestResultCombo->setItemText(19, QApplication::translate("SVMTrainner", "R", nullptr));
        charTestResultCombo->setItemText(20, QApplication::translate("SVMTrainner", "S", nullptr));
        charTestResultCombo->setItemText(21, QApplication::translate("SVMTrainner", "T", nullptr));
        charTestResultCombo->setItemText(22, QApplication::translate("SVMTrainner", "U", nullptr));
        charTestResultCombo->setItemText(23, QApplication::translate("SVMTrainner", "V", nullptr));
        charTestResultCombo->setItemText(24, QApplication::translate("SVMTrainner", "W", nullptr));
        charTestResultCombo->setItemText(25, QApplication::translate("SVMTrainner", "X", nullptr));
        charTestResultCombo->setItemText(26, QApplication::translate("SVMTrainner", "Y", nullptr));
        charTestResultCombo->setItemText(27, QApplication::translate("SVMTrainner", "Z", nullptr));
        charTestResultCombo->setItemText(28, QApplication::translate("SVMTrainner", "0", nullptr));
        charTestResultCombo->setItemText(29, QApplication::translate("SVMTrainner", "1", nullptr));
        charTestResultCombo->setItemText(30, QApplication::translate("SVMTrainner", "2", nullptr));
        charTestResultCombo->setItemText(31, QApplication::translate("SVMTrainner", "3", nullptr));
        charTestResultCombo->setItemText(32, QApplication::translate("SVMTrainner", "4", nullptr));
        charTestResultCombo->setItemText(33, QApplication::translate("SVMTrainner", "5", nullptr));
        charTestResultCombo->setItemText(34, QApplication::translate("SVMTrainner", "6", nullptr));
        charTestResultCombo->setItemText(35, QApplication::translate("SVMTrainner", "7", nullptr));
        charTestResultCombo->setItemText(36, QApplication::translate("SVMTrainner", "8", nullptr));
        charTestResultCombo->setItemText(37, QApplication::translate("SVMTrainner", "9", nullptr));
        charTestResultCombo->setItemText(38, QApplication::translate("SVMTrainner", "\347\202\271", nullptr));
        charTestResultCombo->setItemText(39, QApplication::translate("SVMTrainner", "\344\272\254", nullptr));
        charTestResultCombo->setItemText(40, QApplication::translate("SVMTrainner", "\346\264\245", nullptr));
        charTestResultCombo->setItemText(41, QApplication::translate("SVMTrainner", "\346\262\252", nullptr));
        charTestResultCombo->setItemText(42, QApplication::translate("SVMTrainner", "\346\270\235", nullptr));
        charTestResultCombo->setItemText(43, QApplication::translate("SVMTrainner", "\350\222\231", nullptr));
        charTestResultCombo->setItemText(44, QApplication::translate("SVMTrainner", "\346\226\260", nullptr));
        charTestResultCombo->setItemText(45, QApplication::translate("SVMTrainner", "\350\227\217", nullptr));
        charTestResultCombo->setItemText(46, QApplication::translate("SVMTrainner", "\345\256\201", nullptr));
        charTestResultCombo->setItemText(47, QApplication::translate("SVMTrainner", "\346\241\202", nullptr));
        charTestResultCombo->setItemText(48, QApplication::translate("SVMTrainner", "\346\270\257", nullptr));
        charTestResultCombo->setItemText(49, QApplication::translate("SVMTrainner", "\346\276\263", nullptr));
        charTestResultCombo->setItemText(50, QApplication::translate("SVMTrainner", "\351\273\221", nullptr));
        charTestResultCombo->setItemText(51, QApplication::translate("SVMTrainner", "\345\220\211", nullptr));
        charTestResultCombo->setItemText(52, QApplication::translate("SVMTrainner", "\350\276\275", nullptr));
        charTestResultCombo->setItemText(53, QApplication::translate("SVMTrainner", "\346\231\213", nullptr));
        charTestResultCombo->setItemText(54, QApplication::translate("SVMTrainner", "\345\206\200", nullptr));
        charTestResultCombo->setItemText(55, QApplication::translate("SVMTrainner", "\351\235\222", nullptr));
        charTestResultCombo->setItemText(56, QApplication::translate("SVMTrainner", "\351\262\201", nullptr));
        charTestResultCombo->setItemText(57, QApplication::translate("SVMTrainner", "\350\261\253", nullptr));
        charTestResultCombo->setItemText(58, QApplication::translate("SVMTrainner", "\350\213\217", nullptr));
        charTestResultCombo->setItemText(59, QApplication::translate("SVMTrainner", "\347\232\226", nullptr));
        charTestResultCombo->setItemText(60, QApplication::translate("SVMTrainner", "\346\265\231", nullptr));
        charTestResultCombo->setItemText(61, QApplication::translate("SVMTrainner", "\351\227\275", nullptr));
        charTestResultCombo->setItemText(62, QApplication::translate("SVMTrainner", "\350\265\243", nullptr));
        charTestResultCombo->setItemText(63, QApplication::translate("SVMTrainner", "\346\271\230", nullptr));
        charTestResultCombo->setItemText(64, QApplication::translate("SVMTrainner", "\351\204\202", nullptr));
        charTestResultCombo->setItemText(65, QApplication::translate("SVMTrainner", "\347\262\244", nullptr));
        charTestResultCombo->setItemText(66, QApplication::translate("SVMTrainner", "\347\220\274", nullptr));
        charTestResultCombo->setItemText(67, QApplication::translate("SVMTrainner", "\347\224\230", nullptr));
        charTestResultCombo->setItemText(68, QApplication::translate("SVMTrainner", "\351\231\225", nullptr));
        charTestResultCombo->setItemText(69, QApplication::translate("SVMTrainner", "\350\264\265", nullptr));
        charTestResultCombo->setItemText(70, QApplication::translate("SVMTrainner", "\344\272\221", nullptr));
        charTestResultCombo->setItemText(71, QApplication::translate("SVMTrainner", "\345\267\235", nullptr));
        charTestResultCombo->setItemText(72, QApplication::translate("SVMTrainner", "\350\255\246", nullptr));

        correctCharButton->setText(QApplication::translate("SVMTrainner", "\345\212\240\345\205\245\350\256\255\347\273\203\345\272\223", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = charTestTree->headerItem();
        ___qtreewidgetitem3->setText(0, QApplication::translate("SVMTrainner", "\346\265\213\350\257\225\351\233\206", nullptr));
        mainTab->setTabText(mainTab->indexOf(charTab), QApplication::translate("SVMTrainner", "\345\255\227\347\254\246\350\256\255\347\273\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SVMTrainner: public Ui_SVMTrainner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SVMTRAINNER_H
