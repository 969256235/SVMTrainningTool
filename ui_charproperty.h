/********************************************************************************
** Form generated from reading UI file 'charproperty.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARPROPERTY_H
#define UI_CHARPROPERTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CharProperty
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QCheckBox *trainPathCheckBox;
    QPushButton *trainPathButton;
    QLineEdit *trainPathEdit;
    QLabel *trainPathLabel;
    QGridLayout *gridLayout_2;
    QPushButton *resultPathButton;
    QLabel *resultPatLabel;
    QLineEdit *resultPathEdit;
    QGridLayout *gridLayout_4;
    QLineEdit *resultNameEdit;
    QLabel *resultNameLabel;
    QCheckBox *resultLoadCheckBox;
    QCheckBox *resultPathCheckBox;
    QGridLayout *gridLayout_3;
    QLabel *testPathLabel;
    QLineEdit *testPathEdit;
    QPushButton *testPathButton;
    QCheckBox *testPathCheckBox;
    QHBoxLayout *addedPercentage;
    QCheckBox *generateTestSetCheckBox;
    QSpinBox *testSetPercentage;
    QLabel *percentLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *allowedMultipleLabel;
    QSpinBox *plateMultiplePercentage;
    QLabel *plateMultiplePercentLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *minPlateSampleLabel;
    QSpinBox *minPlateSampleBox;
    QCheckBox *similarytyCheck;
    QGridLayout *gridLayout_5;
    QLabel *numSimilarity;
    QLabel *cncharSimilarity;
    QDoubleSpinBox *thresholdForNum;
    QLabel *layout;
    QPushButton *OKButton;
    QDoubleSpinBox *thresholdForNonChar;
    QDoubleSpinBox *thresholdForCnchar;
    QPushButton *cancelButton;
    QLabel *charHogWinSizeLabel;
    QLabel *letterSimilarity;
    QDoubleSpinBox *thresholdForLetter;
    QLabel *noncharSimilarity;
    QSpinBox *charHogWinSizeY;
    QLabel *charHogWinSizeMultipleLabel;
    QSpinBox *charHogWInSizeX;

    void setupUi(QDialog *CharProperty)
    {
        if (CharProperty->objectName().isEmpty())
            CharProperty->setObjectName(QString::fromUtf8("CharProperty"));
        CharProperty->resize(389, 651);
        horizontalLayout_3 = new QHBoxLayout(CharProperty);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(CharProperty);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        trainPathCheckBox = new QCheckBox(groupBox);
        trainPathCheckBox->setObjectName(QString::fromUtf8("trainPathCheckBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        trainPathCheckBox->setFont(font);

        gridLayout->addWidget(trainPathCheckBox, 2, 0, 1, 1);

        trainPathButton = new QPushButton(groupBox);
        trainPathButton->setObjectName(QString::fromUtf8("trainPathButton"));

        gridLayout->addWidget(trainPathButton, 1, 1, 1, 1);

        trainPathEdit = new QLineEdit(groupBox);
        trainPathEdit->setObjectName(QString::fromUtf8("trainPathEdit"));

        gridLayout->addWidget(trainPathEdit, 1, 0, 1, 1);

        trainPathLabel = new QLabel(groupBox);
        trainPathLabel->setObjectName(QString::fromUtf8("trainPathLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        trainPathLabel->setFont(font1);

        gridLayout->addWidget(trainPathLabel, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        resultPathButton = new QPushButton(groupBox);
        resultPathButton->setObjectName(QString::fromUtf8("resultPathButton"));

        gridLayout_2->addWidget(resultPathButton, 1, 1, 1, 1);

        resultPatLabel = new QLabel(groupBox);
        resultPatLabel->setObjectName(QString::fromUtf8("resultPatLabel"));
        resultPatLabel->setFont(font1);

        gridLayout_2->addWidget(resultPatLabel, 0, 0, 1, 2);

        resultPathEdit = new QLineEdit(groupBox);
        resultPathEdit->setObjectName(QString::fromUtf8("resultPathEdit"));

        gridLayout_2->addWidget(resultPathEdit, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        resultNameEdit = new QLineEdit(groupBox);
        resultNameEdit->setObjectName(QString::fromUtf8("resultNameEdit"));

        gridLayout_4->addWidget(resultNameEdit, 1, 2, 1, 1);

        resultNameLabel = new QLabel(groupBox);
        resultNameLabel->setObjectName(QString::fromUtf8("resultNameLabel"));
        resultNameLabel->setFont(font1);

        gridLayout_4->addWidget(resultNameLabel, 1, 0, 1, 2);

        resultLoadCheckBox = new QCheckBox(groupBox);
        resultLoadCheckBox->setObjectName(QString::fromUtf8("resultLoadCheckBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(11);
        resultLoadCheckBox->setFont(font2);

        gridLayout_4->addWidget(resultLoadCheckBox, 0, 1, 1, 2);

        resultPathCheckBox = new QCheckBox(groupBox);
        resultPathCheckBox->setObjectName(QString::fromUtf8("resultPathCheckBox"));
        resultPathCheckBox->setFont(font2);

        gridLayout_4->addWidget(resultPathCheckBox, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        testPathLabel = new QLabel(groupBox);
        testPathLabel->setObjectName(QString::fromUtf8("testPathLabel"));
        testPathLabel->setEnabled(true);
        testPathLabel->setFont(font1);

        gridLayout_3->addWidget(testPathLabel, 0, 0, 1, 1);

        testPathEdit = new QLineEdit(groupBox);
        testPathEdit->setObjectName(QString::fromUtf8("testPathEdit"));

        gridLayout_3->addWidget(testPathEdit, 1, 0, 1, 1);

        testPathButton = new QPushButton(groupBox);
        testPathButton->setObjectName(QString::fromUtf8("testPathButton"));

        gridLayout_3->addWidget(testPathButton, 1, 1, 1, 1);

        testPathCheckBox = new QCheckBox(groupBox);
        testPathCheckBox->setObjectName(QString::fromUtf8("testPathCheckBox"));
        testPathCheckBox->setFont(font);

        gridLayout_3->addWidget(testPathCheckBox, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        addedPercentage = new QHBoxLayout();
        addedPercentage->setObjectName(QString::fromUtf8("addedPercentage"));
        generateTestSetCheckBox = new QCheckBox(groupBox);
        generateTestSetCheckBox->setObjectName(QString::fromUtf8("generateTestSetCheckBox"));
        generateTestSetCheckBox->setFont(font2);

        addedPercentage->addWidget(generateTestSetCheckBox);

        testSetPercentage = new QSpinBox(groupBox);
        testSetPercentage->setObjectName(QString::fromUtf8("testSetPercentage"));

        addedPercentage->addWidget(testSetPercentage);

        percentLabel = new QLabel(groupBox);
        percentLabel->setObjectName(QString::fromUtf8("percentLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(14);
        percentLabel->setFont(font3);

        addedPercentage->addWidget(percentLabel);


        verticalLayout->addLayout(addedPercentage);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        allowedMultipleLabel = new QLabel(groupBox);
        allowedMultipleLabel->setObjectName(QString::fromUtf8("allowedMultipleLabel"));
        allowedMultipleLabel->setFont(font);

        horizontalLayout->addWidget(allowedMultipleLabel);

        plateMultiplePercentage = new QSpinBox(groupBox);
        plateMultiplePercentage->setObjectName(QString::fromUtf8("plateMultiplePercentage"));
        plateMultiplePercentage->setMinimum(100);
        plateMultiplePercentage->setMaximum(300);
        plateMultiplePercentage->setSingleStep(10);
        plateMultiplePercentage->setValue(100);

        horizontalLayout->addWidget(plateMultiplePercentage);

        plateMultiplePercentLabel = new QLabel(groupBox);
        plateMultiplePercentLabel->setObjectName(QString::fromUtf8("plateMultiplePercentLabel"));
        plateMultiplePercentLabel->setFont(font3);

        horizontalLayout->addWidget(plateMultiplePercentLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        minPlateSampleLabel = new QLabel(groupBox);
        minPlateSampleLabel->setObjectName(QString::fromUtf8("minPlateSampleLabel"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(8);
        minPlateSampleLabel->setFont(font4);

        horizontalLayout_2->addWidget(minPlateSampleLabel);

        minPlateSampleBox = new QSpinBox(groupBox);
        minPlateSampleBox->setObjectName(QString::fromUtf8("minPlateSampleBox"));
        minPlateSampleBox->setMaximum(65535);
        minPlateSampleBox->setSingleStep(50);

        horizontalLayout_2->addWidget(minPlateSampleBox);


        verticalLayout->addLayout(horizontalLayout_2);

        similarytyCheck = new QCheckBox(groupBox);
        similarytyCheck->setObjectName(QString::fromUtf8("similarytyCheck"));
        similarytyCheck->setFont(font3);

        verticalLayout->addWidget(similarytyCheck);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        numSimilarity = new QLabel(groupBox);
        numSimilarity->setObjectName(QString::fromUtf8("numSimilarity"));
        numSimilarity->setFont(font);

        gridLayout_5->addWidget(numSimilarity, 1, 0, 1, 2);

        cncharSimilarity = new QLabel(groupBox);
        cncharSimilarity->setObjectName(QString::fromUtf8("cncharSimilarity"));
        cncharSimilarity->setFont(font);

        gridLayout_5->addWidget(cncharSimilarity, 3, 0, 1, 2);

        thresholdForNum = new QDoubleSpinBox(groupBox);
        thresholdForNum->setObjectName(QString::fromUtf8("thresholdForNum"));
        thresholdForNum->setDecimals(3);
        thresholdForNum->setMaximum(1.000000000000000);
        thresholdForNum->setSingleStep(0.010000000000000);

        gridLayout_5->addWidget(thresholdForNum, 1, 3, 1, 3);

        layout = new QLabel(groupBox);
        layout->setObjectName(QString::fromUtf8("layout"));

        gridLayout_5->addWidget(layout, 5, 0, 1, 2);

        OKButton = new QPushButton(groupBox);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));

        gridLayout_5->addWidget(OKButton, 5, 2, 1, 4);

        thresholdForNonChar = new QDoubleSpinBox(groupBox);
        thresholdForNonChar->setObjectName(QString::fromUtf8("thresholdForNonChar"));
        thresholdForNonChar->setDecimals(3);
        thresholdForNonChar->setMaximum(1.000000000000000);
        thresholdForNonChar->setSingleStep(0.010000000000000);

        gridLayout_5->addWidget(thresholdForNonChar, 0, 3, 1, 3);

        thresholdForCnchar = new QDoubleSpinBox(groupBox);
        thresholdForCnchar->setObjectName(QString::fromUtf8("thresholdForCnchar"));
        thresholdForCnchar->setDecimals(3);
        thresholdForCnchar->setMaximum(1.000000000000000);
        thresholdForCnchar->setSingleStep(0.010000000000000);

        gridLayout_5->addWidget(thresholdForCnchar, 3, 3, 1, 3);

        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_5->addWidget(cancelButton, 5, 7, 1, 1);

        charHogWinSizeLabel = new QLabel(groupBox);
        charHogWinSizeLabel->setObjectName(QString::fromUtf8("charHogWinSizeLabel"));
        charHogWinSizeLabel->setFont(font);

        gridLayout_5->addWidget(charHogWinSizeLabel, 4, 0, 1, 2);

        letterSimilarity = new QLabel(groupBox);
        letterSimilarity->setObjectName(QString::fromUtf8("letterSimilarity"));
        letterSimilarity->setFont(font);

        gridLayout_5->addWidget(letterSimilarity, 2, 0, 1, 2);

        thresholdForLetter = new QDoubleSpinBox(groupBox);
        thresholdForLetter->setObjectName(QString::fromUtf8("thresholdForLetter"));
        thresholdForLetter->setDecimals(3);
        thresholdForLetter->setMaximum(1.000000000000000);
        thresholdForLetter->setSingleStep(0.010000000000000);

        gridLayout_5->addWidget(thresholdForLetter, 2, 3, 1, 3);

        noncharSimilarity = new QLabel(groupBox);
        noncharSimilarity->setObjectName(QString::fromUtf8("noncharSimilarity"));
        noncharSimilarity->setFont(font);

        gridLayout_5->addWidget(noncharSimilarity, 0, 0, 1, 3);

        charHogWinSizeY = new QSpinBox(groupBox);
        charHogWinSizeY->setObjectName(QString::fromUtf8("charHogWinSizeY"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font5.setPointSize(10);
        charHogWinSizeY->setFont(font5);
        charHogWinSizeY->setMinimum(8);
        charHogWinSizeY->setMaximum(1024);
        charHogWinSizeY->setSingleStep(8);

        gridLayout_5->addWidget(charHogWinSizeY, 4, 7, 1, 1);

        charHogWinSizeMultipleLabel = new QLabel(groupBox);
        charHogWinSizeMultipleLabel->setObjectName(QString::fromUtf8("charHogWinSizeMultipleLabel"));
        charHogWinSizeMultipleLabel->setFont(font3);

        gridLayout_5->addWidget(charHogWinSizeMultipleLabel, 4, 6, 1, 1);

        charHogWInSizeX = new QSpinBox(groupBox);
        charHogWInSizeX->setObjectName(QString::fromUtf8("charHogWInSizeX"));
        charHogWInSizeX->setFont(font5);
        charHogWInSizeX->setMinimum(8);
        charHogWInSizeX->setMaximum(1024);
        charHogWInSizeX->setSingleStep(8);

        gridLayout_5->addWidget(charHogWInSizeX, 4, 2, 1, 4);


        verticalLayout->addLayout(gridLayout_5);


        horizontalLayout_3->addWidget(groupBox);


        retranslateUi(CharProperty);

        QMetaObject::connectSlotsByName(CharProperty);
    } // setupUi

    void retranslateUi(QDialog *CharProperty)
    {
        CharProperty->setWindowTitle(QApplication::translate("CharProperty", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("CharProperty", "\351\205\215\347\275\256", nullptr));
        trainPathCheckBox->setText(QApplication::translate("CharProperty", "\350\256\276\344\270\272\351\273\230\350\256\244\345\200\274", nullptr));
        trainPathButton->setText(QApplication::translate("CharProperty", "\342\200\246", nullptr));
        trainPathLabel->setText(QApplication::translate("CharProperty", "\350\256\255\347\273\203\345\272\223\350\267\257\345\276\204\357\274\232", nullptr));
        resultPathButton->setText(QApplication::translate("CharProperty", "\342\200\246", nullptr));
        resultPatLabel->setText(QApplication::translate("CharProperty", "\346\210\220\346\236\234\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", nullptr));
        resultNameEdit->setText(QString());
        resultNameLabel->setText(QApplication::translate("CharProperty", "\351\273\230\350\256\244\346\210\220\346\236\234\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        resultLoadCheckBox->setText(QApplication::translate("CharProperty", "\350\256\276\344\270\272\350\257\273\345\217\226\346\227\266\347\232\204\351\273\230\350\256\244\345\200\274", nullptr));
        resultPathCheckBox->setText(QApplication::translate("CharProperty", "\350\256\276\344\270\272\344\277\235\345\255\230\346\227\266\347\232\204\351\273\230\350\256\244\345\200\274", nullptr));
        testPathLabel->setText(QApplication::translate("CharProperty", "\346\265\213\350\257\225\351\233\206\350\267\257\345\276\204\357\274\232", nullptr));
        testPathButton->setText(QApplication::translate("CharProperty", "\342\200\246", nullptr));
        testPathCheckBox->setText(QApplication::translate("CharProperty", "\350\256\276\344\270\272\351\273\230\350\256\244\345\200\274", nullptr));
        generateTestSetCheckBox->setText(QApplication::translate("CharProperty", "\344\273\216\350\256\255\347\273\203\351\233\206\344\270\255\346\212\275\345\217\226\346\265\213\350\257\225\351\233\206 \346\212\275\345\217\226\346\257\224\344\276\213\357\274\232", nullptr));
        percentLabel->setText(QApplication::translate("CharProperty", "%", nullptr));
        allowedMultipleLabel->setText(QApplication::translate("CharProperty", "\346\240\267\346\234\254\351\233\206\345\267\256\345\274\202\345\200\215\346\225\260\346\234\200\345\244\247\345\200\274\357\274\232", nullptr));
        plateMultiplePercentLabel->setText(QApplication::translate("CharProperty", "%", nullptr));
        minPlateSampleLabel->setText(QApplication::translate("CharProperty", "\346\234\200\345\260\217\346\240\267\346\234\254\346\225\260\357\274\210\345\235\207\350\241\241\345\214\226\346\227\266\345\260\221\344\272\216\350\257\245\346\225\260\351\207\217\347\232\204\346\240\267\346\234\254\351\233\206\344\274\232\350\242\253\346\227\240\350\247\206\357\274\211\357\274\232", nullptr));
        similarytyCheck->setText(QApplication::translate("CharProperty", "\345\257\274\345\205\245\350\256\255\347\273\203\345\272\223\346\227\266\345\211\224\351\231\244\347\233\270\344\274\274\345\233\276\345\203\217", nullptr));
        numSimilarity->setText(QApplication::translate("CharProperty", "\346\225\260\345\255\227\347\233\270\344\274\274\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        cncharSimilarity->setText(QApplication::translate("CharProperty", "\346\225\260\345\255\227\347\233\270\344\274\274\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        layout->setText(QString());
        OKButton->setText(QApplication::translate("CharProperty", "OK", nullptr));
        cancelButton->setText(QApplication::translate("CharProperty", "Cancel", nullptr));
        charHogWinSizeLabel->setText(QApplication::translate("CharProperty", "Hog\347\252\227\345\217\243\345\260\272\345\257\270:", nullptr));
        letterSimilarity->setText(QApplication::translate("CharProperty", "\345\255\227\346\257\215\347\233\270\344\274\274\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        noncharSimilarity->setText(QApplication::translate("CharProperty", "\351\235\236\345\255\227\347\254\246\347\233\270\344\274\274\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        charHogWinSizeMultipleLabel->setText(QApplication::translate("CharProperty", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharProperty: public Ui_CharProperty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARPROPERTY_H
