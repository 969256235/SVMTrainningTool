/********************************************************************************
** Form generated from reading UI file 'plateproperty.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLATEPROPERTY_H
#define UI_PLATEPROPERTY_H

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

class Ui_PlateProperty
{
public:
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QCheckBox *trainPathCheckBox;
    QPushButton *trainPathButton;
    QLineEdit *trainPathEdit;
    QLabel *trainPatLabel;
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
    QCheckBox *similarytyCheck;
    QGridLayout *gridLayout_5;
    QLabel *layout;
    QPushButton *pushButton_2;
    QPushButton *OKButton;
    QLabel *plateSimilarity;
    QLabel *nonplateSimilarity;
    QDoubleSpinBox *thresholdForNonplate;
    QDoubleSpinBox *thresholdForPlate;

    void setupUi(QDialog *PlateProperty)
    {
        if (PlateProperty->objectName().isEmpty())
            PlateProperty->setObjectName(QString::fromUtf8("PlateProperty"));
        PlateProperty->resize(362, 548);
        verticalLayout_5 = new QVBoxLayout(PlateProperty);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(PlateProperty);
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

        trainPatLabel = new QLabel(groupBox);
        trainPatLabel->setObjectName(QString::fromUtf8("trainPatLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        trainPatLabel->setFont(font1);

        gridLayout->addWidget(trainPatLabel, 0, 0, 1, 1);


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

        similarytyCheck = new QCheckBox(groupBox);
        similarytyCheck->setObjectName(QString::fromUtf8("similarytyCheck"));
        similarytyCheck->setFont(font3);

        verticalLayout->addWidget(similarytyCheck);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        layout = new QLabel(groupBox);
        layout->setObjectName(QString::fromUtf8("layout"));

        gridLayout_5->addWidget(layout, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_5->addWidget(pushButton_2, 2, 3, 1, 1);

        OKButton = new QPushButton(groupBox);
        OKButton->setObjectName(QString::fromUtf8("OKButton"));

        gridLayout_5->addWidget(OKButton, 2, 2, 1, 1);

        plateSimilarity = new QLabel(groupBox);
        plateSimilarity->setObjectName(QString::fromUtf8("plateSimilarity"));
        plateSimilarity->setFont(font);

        gridLayout_5->addWidget(plateSimilarity, 1, 0, 1, 1);

        nonplateSimilarity = new QLabel(groupBox);
        nonplateSimilarity->setObjectName(QString::fromUtf8("nonplateSimilarity"));
        nonplateSimilarity->setFont(font);

        gridLayout_5->addWidget(nonplateSimilarity, 0, 0, 1, 1);

        thresholdForNonplate = new QDoubleSpinBox(groupBox);
        thresholdForNonplate->setObjectName(QString::fromUtf8("thresholdForNonplate"));
        thresholdForNonplate->setDecimals(3);
        thresholdForNonplate->setMaximum(1.000000000000000);
        thresholdForNonplate->setSingleStep(0.010000000000000);

        gridLayout_5->addWidget(thresholdForNonplate, 0, 2, 1, 1);

        thresholdForPlate = new QDoubleSpinBox(groupBox);
        thresholdForPlate->setObjectName(QString::fromUtf8("thresholdForPlate"));
        thresholdForPlate->setDecimals(3);
        thresholdForPlate->setMaximum(1.000000000000000);
        thresholdForPlate->setSingleStep(0.010000000000000);

        gridLayout_5->addWidget(thresholdForPlate, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_5);


        verticalLayout_5->addWidget(groupBox);


        retranslateUi(PlateProperty);

        QMetaObject::connectSlotsByName(PlateProperty);
    } // setupUi

    void retranslateUi(QDialog *PlateProperty)
    {
        PlateProperty->setWindowTitle(QApplication::translate("PlateProperty", "Setting", nullptr));
        groupBox->setTitle(QApplication::translate("PlateProperty", "\351\205\215\347\275\256", nullptr));
        trainPathCheckBox->setText(QApplication::translate("PlateProperty", "\350\256\276\344\270\272\351\273\230\350\256\244\345\200\274", nullptr));
        trainPathButton->setText(QApplication::translate("PlateProperty", "\342\200\246", nullptr));
        trainPatLabel->setText(QApplication::translate("PlateProperty", "\350\256\255\347\273\203\345\272\223\350\267\257\345\276\204\357\274\232", nullptr));
        resultPathButton->setText(QApplication::translate("PlateProperty", "\342\200\246", nullptr));
        resultPatLabel->setText(QApplication::translate("PlateProperty", "\346\210\220\346\236\234\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", nullptr));
        resultNameEdit->setText(QString());
        resultNameLabel->setText(QApplication::translate("PlateProperty", "\351\273\230\350\256\244\346\210\220\346\236\234\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        resultLoadCheckBox->setText(QApplication::translate("PlateProperty", "\350\256\276\344\270\272\350\257\273\345\217\226\346\227\266\347\232\204\351\273\230\350\256\244\345\200\274", nullptr));
        resultPathCheckBox->setText(QApplication::translate("PlateProperty", "\350\256\276\344\270\272\344\277\235\345\255\230\346\227\266\347\232\204\351\273\230\350\256\244\345\200\274", nullptr));
        testPathLabel->setText(QApplication::translate("PlateProperty", "\346\265\213\350\257\225\351\233\206\350\267\257\345\276\204\357\274\232", nullptr));
        testPathButton->setText(QApplication::translate("PlateProperty", "\342\200\246", nullptr));
        testPathCheckBox->setText(QApplication::translate("PlateProperty", "\350\256\276\344\270\272\351\273\230\350\256\244\345\200\274", nullptr));
        generateTestSetCheckBox->setText(QApplication::translate("PlateProperty", "\344\273\216\350\256\255\347\273\203\351\233\206\344\270\255\346\212\275\345\217\226\346\265\213\350\257\225\351\233\206 \346\212\275\345\217\226\346\257\224\344\276\213\357\274\232", nullptr));
        percentLabel->setText(QApplication::translate("PlateProperty", "%", nullptr));
        allowedMultipleLabel->setText(QApplication::translate("PlateProperty", "\346\240\267\346\234\254\351\233\206\345\267\256\345\274\202\345\200\215\346\225\260\346\234\200\345\244\247\345\200\274\357\274\232", nullptr));
        plateMultiplePercentLabel->setText(QApplication::translate("PlateProperty", "%", nullptr));
        similarytyCheck->setText(QApplication::translate("PlateProperty", "\345\257\274\345\205\245\350\256\255\347\273\203\345\272\223\346\227\266\345\211\224\351\231\244\347\233\270\344\274\274\345\233\276\345\203\217", nullptr));
        layout->setText(QString());
        pushButton_2->setText(QApplication::translate("PlateProperty", "Cancel", nullptr));
        OKButton->setText(QApplication::translate("PlateProperty", "OK", nullptr));
        plateSimilarity->setText(QApplication::translate("PlateProperty", "\350\275\246\347\211\214\347\233\270\344\274\274\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        nonplateSimilarity->setText(QApplication::translate("PlateProperty", "\351\235\236\350\275\246\347\211\214\347\233\270\344\274\274\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlateProperty: public Ui_PlateProperty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLATEPROPERTY_H
