#ifndef CHARPROPERTY_H
#define CHARPROPERTY_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include "property.h"

namespace Ui {
class CharProperty;
}

class CharProperty : public QDialog
{
    Q_OBJECT

public:
    explicit CharProperty(QWidget *parent = nullptr);
    ~CharProperty();

private slots:
    void on_trainPathButton_clicked();

    void on_resultPathButton_clicked();

    void on_testPathButton_clicked();

    void on_OKButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CharProperty *ui;
};

#endif // CHARPROPERTY_H
