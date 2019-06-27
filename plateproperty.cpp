#include "plateproperty.h"
#include "ui_plateproperty.h"

#include <iostream>

PlateProperty::PlateProperty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlateProperty)
{
    ui->setupUi(this);
    this->ui->trainPathEdit->setText(Property::plateTrainPath);
    this->ui->resultPathEdit->setText(Property::plateResultPath);
    this->ui->resultNameEdit->setText(Property::plateResultName);
    this->ui->testPathEdit->setText(Property::plateTestPath);

    this->ui->trainPathCheckBox->setChecked(Property::plateTrainPathDefault);
    this->ui->resultPathCheckBox->setChecked(Property::plateResultPathDefault);
    this->ui->testPathCheckBox->setChecked(Property::plateTestLoadDefault);
    this->ui->resultLoadCheckBox->setChecked(Property::plateResultLoadDefault);

    this->ui->similarytyCheck->setChecked(Property::similarityCheck);
    this->ui->thresholdForNonplate->setValue(Property::thresholdForSimilarity[0]);
    this->ui->thresholdForPlate->setValue(Property::thresholdForSimilarity[1]);

    this->ui->generateTestSetCheckBox->setChecked(Property::generateTestSetByTrainSet);
    this->ui->testSetPercentage->setValue(Property::testSetPercent);
    this->ui->plateMultiplePercentage->setValue((int)(Property::maxMultiple * 100));
}

PlateProperty::~PlateProperty()
{
    delete ui;
}

void PlateProperty::on_trainPathButton_clicked()
{
    QString trainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTrainPath);
    if(trainPath.isEmpty()) return;
    this->ui->trainPathEdit->setText(trainPath);
}

void PlateProperty::on_resultPathButton_clicked()
{
    QString resultPath = QFileDialog::getExistingDirectory(this,tr("Select Where to Put Result"),Property::plateResultPath);
    if(resultPath.isEmpty()) return;
    this->ui->resultPathEdit->setText(resultPath);
}

void PlateProperty::on_testPathButton_clicked()
{
    QString testPath = QFileDialog::getExistingDirectory(this,tr("Select Where to Put Result"),Property::plateTestPath);
    if(testPath.isEmpty()) return;
    this->ui->testPathEdit->setText(testPath);
}

void PlateProperty::on_OKButton_clicked()
{
    if((this->ui->trainPathCheckBox->checkState() && this->ui->trainPathEdit->text().isEmpty()) ||
            ((this->ui->resultPathCheckBox->checkState() ||  this->ui->resultLoadCheckBox->checkState()) && this->ui->resultPathEdit->text().isEmpty()) ||
            (this->ui->testPathCheckBox->checkState() && this->ui->testPathEdit->text().isEmpty()))
    {
        QMessageBox::information(NULL, "Warning!", "Default Path Can't Be Empty!",QMessageBox::Ok);
        this->ui->trainPathCheckBox->setChecked(false);
        this->ui->resultPathCheckBox->setChecked(false);
        this->ui->resultLoadCheckBox->setChecked(false);
        this->ui->testPathCheckBox->setChecked(false);
        return;
    }

    if(this->ui->resultNameEdit->text().isEmpty())
    {
        QMessageBox::information(NULL, "Warning!", "Filename of Result Can't Be Empty!",QMessageBox::Ok);
        return;
    }

    Property::plateTrainPath = this->ui->trainPathEdit->text();
    Property::plateResultPath = this->ui->resultPathEdit->text();
    Property:: plateResultName = this->ui->resultNameEdit->text();
    Property::plateTestPath = this->ui->testPathEdit->text();

    Property::plateTrainPathDefault = this->ui->trainPathCheckBox->checkState();
    Property::plateResultPathDefault = this->ui->resultPathCheckBox->checkState();
    Property::plateTestLoadDefault = this->ui->testPathCheckBox->checkState();
    Property::plateResultLoadDefault = this->ui->resultLoadCheckBox->checkState();

    Property::similarityCheck = this->ui->similarytyCheck->checkState();
    Property::thresholdForSimilarity[0] = this->ui->thresholdForNonplate->value();
    Property::thresholdForSimilarity[1] = this->ui->thresholdForPlate->value();

    Property::generateTestSetByTrainSet = this->ui->generateTestSetCheckBox->checkState();
    Property::testSetPercent = this->ui->testSetPercentage->value();
    Property::maxMultiple = (float)this->ui->plateMultiplePercentage->value() / 100.0f;

    this->close();
}

void PlateProperty::on_pushButton_2_clicked()
{
    this->close();
}
