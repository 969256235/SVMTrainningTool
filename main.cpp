#include "svmtrainner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SVMTrainner w;
    w.show();

    return a.exec();
}
