#ifndef PLATEPROPERTY_H
#define PLATEPROPERTY_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

//#include "platecategory_svm.h"
#include "property.h"

namespace Ui {
class PlateProperty;
}

class PlateProperty : public QDialog
{
    Q_OBJECT

public:
    explicit PlateProperty(QWidget *parent = nullptr);
    ~PlateProperty();

private slots:
    void on_trainPathButton_clicked();

    void on_resultPathButton_clicked();

    void on_OKButton_clicked();

    void on_pushButton_2_clicked();

    void on_testPathButton_clicked();

private:
    Ui::PlateProperty *ui;
};

#endif // PLATEPROPERTY_H
