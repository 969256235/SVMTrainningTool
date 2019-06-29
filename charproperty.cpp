#include "charproperty.h"
#include "ui_charproperty.h"

CharProperty::CharProperty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CharProperty)
{
    ui->setupUi(this);
    this->ui->trainPathEdit->setText(Property::charTrainPath);
    this->ui->resultPathEdit->setText(Property::charResultPath);
    this->ui->resultNameEdit->setText(Property::charResultName);
    this->ui->testPathEdit->setText(Property::charTestPath);

    this->ui->trainPathCheckBox->setChecked(Property::charTrainPathDefault);
    this->ui->resultPathCheckBox->setChecked(Property::charResultPathDefault);
    this->ui->testPathCheckBox->setChecked(Property::charTestLoadDefault);
    this->ui->resultLoadCheckBox->setChecked(Property::charResultLoadDefault);

    this->ui->similarytyCheck->setChecked(Property::charSimilarityCheck);
    this->ui->thresholdForNonChar->setValue(Property::charThresholdForSimilarity[0]);
    this->ui->thresholdForNum->setValue(Property::charThresholdForSimilarity[1]);
    this->ui->thresholdForLetter->setValue(Property::charThresholdForSimilarity[2]);
    this->ui->thresholdForCnchar->setValue(Property::charThresholdForSimilarity[3]);

    this->ui->generateTestSetCheckBox->setChecked(Property::charGenerateTestSetByTrainSet);
    this->ui->testSetPercentage->setValue(Property::charTestSetPercent);
    this->ui->plateMultiplePercentage->setValue((int)(Property::charMaxMultiple * 100));
    this->ui->minPlateSampleBox->setValue(Property::minCharSampleNum);
}

CharProperty::~CharProperty()
{
    delete ui;
}

void CharProperty::on_trainPathButton_clicked()
{
    QString trainPath = QFileDialog::getExistingDirectory(this,tr("Select Trainning Set Path"),Property::plateTrainPath);
    if(trainPath.isEmpty()) return;
    this->ui->trainPathEdit->setText(trainPath);
}


void CharProperty::on_resultPathButton_clicked()
{
    QString resultPath = QFileDialog::getExistingDirectory(this,tr("Select Where to Put Result"),Property::plateResultPath);
    if(resultPath.isEmpty()) return;
    this->ui->resultPathEdit->setText(resultPath);
}

void CharProperty::on_testPathButton_clicked()
{
    QString testPath = QFileDialog::getExistingDirectory(this,tr("Select Where to Put Result"),Property::plateTestPath);
    if(testPath.isEmpty()) return;
    this->ui->testPathEdit->setText(testPath);
}

void CharProperty::on_OKButton_clicked()
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

    if(!QDir(this->ui->trainPathEdit->text()).exists())
    {
        QMessageBox::information(this, "Warnning!", "TrainSet Path Invalid!");
    }

    Property::charTrainPath = this->ui->trainPathEdit->text();
    Property::charResultPath = this->ui->resultPathEdit->text();
    Property::charResultName = this->ui->resultNameEdit->text();
    Property::charTestPath = this->ui->testPathEdit->text();

    Property::charTrainPathDefault = this->ui->trainPathCheckBox->checkState();
    Property::charResultPathDefault = this->ui->resultPathCheckBox->checkState();
    Property::charTestLoadDefault = this->ui->testPathCheckBox->checkState();
    Property::charResultLoadDefault = this->ui->resultLoadCheckBox->checkState();

    Property::charSimilarityCheck = this->ui->similarytyCheck->checkState();
    Property::charThresholdForSimilarity[0] = this->ui->thresholdForNonChar->value();
    Property::charThresholdForSimilarity[1] = this->ui->thresholdForNum->value();
    Property::charThresholdForSimilarity[2] = this->ui->thresholdForLetter->value();
    Property::charThresholdForSimilarity[3] = this->ui->thresholdForCnchar->value();

    Property::charGenerateTestSetByTrainSet = this->ui->generateTestSetCheckBox->checkState();
    Property::charTestSetPercent = this->ui->testSetPercentage->value();
    Property::charMaxMultiple = (float)this->ui->plateMultiplePercentage->value() / 100.0f;
    Property::minCharSampleNum = this->ui->minPlateSampleBox->value();

    this->close();
}

void CharProperty::on_cancelButton_clicked()
{
    this->close();
}
