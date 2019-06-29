#include "platetestthread.h"

PlateTestThread::PlateTestThread(bool standard_, QList<QDir*> dirs_, QList<QStringList> imgFileNames_)
{
    this->standard = standard_;
    this->dirs = dirs_;
    this->imgFileNames = imgFileNames_;
}

void PlateTestThread::run()
{
    int i, k, index;
    int tag;
    if(!standard)
    {
        for(i = 0; i < imgFileNames[0].size(); i++)
        {
            tag = PlateCategory_SVM::Test(dirs[0]->path() + "\\" + imgFileNames[0].at(i));
            emit testResult(i, tag);
        }
    }
    else {
        for(k = 0, index = 0; k < PlateCategoryString.size(); k++)
        {
            for(i = 0; i < imgFileNames[k].size(); i++)
            {
                tag = PlateCategory_SVM::Test(dirs[k]->path() + "\\" + imgFileNames[k].at(i));
                index++;
                emit standardTestResult(k, i, index, tag);
            }
        }
    }

    emit finished();
}
