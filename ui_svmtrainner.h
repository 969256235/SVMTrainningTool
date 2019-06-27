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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SVMTrainner
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QTabWidget *mainTab;
    QWidget *plateTab;
    QPushButton *plateTrainButton;
    QPushButton *platePropertyButton;
    QPushButton *loadPlateSetButton;
    QPushButton *savePlateTrainButton;
    QTreeWidget *plateSampleTree;
    QTreeWidget *plateTestTree;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *plateGreyBox;
    QGridLayout *gridLayout_2;
    QLabel *plateOriginalLabel;
    QGroupBox *plateHogBox;
    QHBoxLayout *horizontalLayout;
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
    QPushButton *loadPlateTestSetButton;
    QPushButton *generatePlateTestSetButton;
    QPushButton *startPlateTestButton;
    QPushButton *singlePlateTestButton;
    QPushButton *loadPlateTrainResultButton;
    QPushButton *plateRefreshButton;
    QPushButton *equalizePlateTrainButton;
    QWidget *charTab;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *SVMTrainner)
    {
        if (SVMTrainner->objectName().isEmpty())
            SVMTrainner->setObjectName(QString::fromUtf8("SVMTrainner"));
        SVMTrainner->resize(1028, 671);
        centralWidget = new QWidget(SVMTrainner);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        mainTab = new QTabWidget(centralWidget);
        mainTab->setObjectName(QString::fromUtf8("mainTab"));
        mainTab->setIconSize(QSize(32, 32));
        plateTab = new QWidget();
        plateTab->setObjectName(QString::fromUtf8("plateTab"));
        plateTrainButton = new QPushButton(plateTab);
        plateTrainButton->setObjectName(QString::fromUtf8("plateTrainButton"));
        plateTrainButton->setGeometry(QRect(210, 0, 71, 31));
        platePropertyButton = new QPushButton(plateTab);
        platePropertyButton->setObjectName(QString::fromUtf8("platePropertyButton"));
        platePropertyButton->setGeometry(QRect(0, 0, 71, 31));
        loadPlateSetButton = new QPushButton(plateTab);
        loadPlateSetButton->setObjectName(QString::fromUtf8("loadPlateSetButton"));
        loadPlateSetButton->setGeometry(QRect(70, 0, 71, 31));
        savePlateTrainButton = new QPushButton(plateTab);
        savePlateTrainButton->setObjectName(QString::fromUtf8("savePlateTrainButton"));
        savePlateTrainButton->setGeometry(QRect(280, 0, 81, 31));
        plateSampleTree = new QTreeWidget(plateTab);
        plateSampleTree->setObjectName(QString::fromUtf8("plateSampleTree"));
        plateSampleTree->setGeometry(QRect(0, 40, 141, 541));
        plateSampleTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plateSampleTree->header()->setMinimumSectionSize(50);
        plateTestTree = new QTreeWidget(plateTab);
        plateTestTree->setObjectName(QString::fromUtf8("plateTestTree"));
        plateTestTree->setGeometry(QRect(490, 40, 141, 541));
        layoutWidget = new QWidget(plateTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 40, 331, 541));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        plateGreyBox = new QGroupBox(layoutWidget);
        plateGreyBox->setObjectName(QString::fromUtf8("plateGreyBox"));
        gridLayout_2 = new QGridLayout(plateGreyBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plateOriginalLabel = new QLabel(plateGreyBox);
        plateOriginalLabel->setObjectName(QString::fromUtf8("plateOriginalLabel"));

        gridLayout_2->addWidget(plateOriginalLabel, 0, 0, 1, 1);


        verticalLayout_3->addWidget(plateGreyBox);

        plateHogBox = new QGroupBox(layoutWidget);
        plateHogBox->setObjectName(QString::fromUtf8("plateHogBox"));
        horizontalLayout = new QHBoxLayout(plateHogBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plateHogLabel = new QLabel(plateHogBox);
        plateHogLabel->setObjectName(QString::fromUtf8("plateHogLabel"));

        horizontalLayout->addWidget(plateHogLabel);


        verticalLayout_3->addWidget(plateHogBox);

        plateSampleImfoBox = new QGroupBox(layoutWidget);
        plateSampleImfoBox->setObjectName(QString::fromUtf8("plateSampleImfoBox"));
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

        loadPlateTestSetButton = new QPushButton(plateTab);
        loadPlateTestSetButton->setObjectName(QString::fromUtf8("loadPlateTestSetButton"));
        loadPlateTestSetButton->setGeometry(QRect(360, 0, 71, 31));
        generatePlateTestSetButton = new QPushButton(plateTab);
        generatePlateTestSetButton->setObjectName(QString::fromUtf8("generatePlateTestSetButton"));
        generatePlateTestSetButton->setGeometry(QRect(580, 0, 71, 31));
        startPlateTestButton = new QPushButton(plateTab);
        startPlateTestButton->setObjectName(QString::fromUtf8("startPlateTestButton"));
        startPlateTestButton->setGeometry(QRect(650, 0, 71, 31));
        singlePlateTestButton = new QPushButton(plateTab);
        singlePlateTestButton->setObjectName(QString::fromUtf8("singlePlateTestButton"));
        singlePlateTestButton->setGeometry(QRect(720, 0, 71, 31));
        loadPlateTrainResultButton = new QPushButton(plateTab);
        loadPlateTrainResultButton->setObjectName(QString::fromUtf8("loadPlateTrainResultButton"));
        loadPlateTrainResultButton->setGeometry(QRect(430, 0, 81, 31));
        plateRefreshButton = new QPushButton(plateTab);
        plateRefreshButton->setObjectName(QString::fromUtf8("plateRefreshButton"));
        plateRefreshButton->setGeometry(QRect(510, 0, 71, 31));
        equalizePlateTrainButton = new QPushButton(plateTab);
        equalizePlateTrainButton->setObjectName(QString::fromUtf8("equalizePlateTrainButton"));
        equalizePlateTrainButton->setGeometry(QRect(140, 0, 71, 31));
        mainTab->addTab(plateTab, QString());
        charTab = new QWidget();
        charTab->setObjectName(QString::fromUtf8("charTab"));
        mainTab->addTab(charTab, QString());

        horizontalLayout_6->addWidget(mainTab);

        SVMTrainner->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(SVMTrainner);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SVMTrainner->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(SVMTrainner);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1028, 23));
        SVMTrainner->setMenuBar(menuBar);

        retranslateUi(SVMTrainner);

        mainTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SVMTrainner);
    } // setupUi

    void retranslateUi(QMainWindow *SVMTrainner)
    {
        SVMTrainner->setWindowTitle(QApplication::translate("SVMTrainner", "SVMTrainner", nullptr));
        plateTrainButton->setText(QApplication::translate("SVMTrainner", "\350\277\233\350\241\214\350\256\255\347\273\203", nullptr));
        platePropertyButton->setText(QApplication::translate("SVMTrainner", "\350\256\255\347\273\203\351\205\215\347\275\256", nullptr));
        loadPlateSetButton->setText(QApplication::translate("SVMTrainner", "\350\243\205\345\205\245\350\256\255\347\273\203\345\272\223", nullptr));
        savePlateTrainButton->setText(QApplication::translate("SVMTrainner", "\344\277\235\345\255\230\350\256\255\347\273\203\346\210\220\346\236\234", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = plateSampleTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SVMTrainner", "\346\240\267\346\234\254\351\233\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = plateTestTree->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("SVMTrainner", "\346\265\213\350\257\225\351\233\206", nullptr));
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
        loadPlateTestSetButton->setText(QApplication::translate("SVMTrainner", "\350\275\275\345\205\245\346\265\213\350\257\225\351\233\206", nullptr));
        generatePlateTestSetButton->setText(QApplication::translate("SVMTrainner", "\347\224\237\346\210\220\346\265\213\350\257\225\351\233\206", nullptr));
        startPlateTestButton->setText(QApplication::translate("SVMTrainner", "\350\277\233\350\241\214\346\265\213\350\257\225", nullptr));
        singlePlateTestButton->setText(QApplication::translate("SVMTrainner", "\345\215\225\345\274\240\345\233\276\346\265\213\350\257\225", nullptr));
        loadPlateTrainResultButton->setText(QApplication::translate("SVMTrainner", "\345\212\240\350\275\275\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        plateRefreshButton->setText(QApplication::translate("SVMTrainner", "\345\210\267\346\226\260", nullptr));
        equalizePlateTrainButton->setText(QApplication::translate("SVMTrainner", "\345\235\207\350\241\241\350\256\255\347\273\203\351\233\206", nullptr));
        mainTab->setTabText(mainTab->indexOf(plateTab), QApplication::translate("SVMTrainner", "\350\275\246\347\211\214\350\256\255\347\273\203", nullptr));
        mainTab->setTabText(mainTab->indexOf(charTab), QApplication::translate("SVMTrainner", "\345\255\227\347\254\246\350\256\255\347\273\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SVMTrainner: public Ui_SVMTrainner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SVMTRAINNER_H
