﻿#include "platetestthread.h"

PlateTestThread::PlateTestThread(bool standard_, QList<QDir*> dirs_, QList<QStringList> imgFileNames_, bool mode_)
{
    this->standard = standard_;
    this->dirs = dirs_;
    this->imgFileNames = imgFileNames_;
    this->mode = mode_;
}

void PlateTestThread::run()
{
    int i, k, index;
    int tag;
    if(!standard)
    {
        for(i = 0; i < imgFileNames[0].size(); i++)
        {
            tag = mode? PlateCategory_SVM::Test(dirs[0]->path() + "\\" + imgFileNames[0].at(i)):PlateChar_SVM::Test(dirs[0]->path() + "\\" + imgFileNames[0].at(i));
            emit testResult(i, tag);
        }
    }
    else {
        for(k = 0, index = 0; k < (mode? PlateCategoryString.size():PlateCharString.size()); k++)
        {
            for(i = 0; i < imgFileNames[k].size(); i++)
            {
                tag = mode? PlateCategory_SVM::Test(dirs[k]->path() + "\\" + imgFileNames[k].at(i)):PlateChar_SVM::Test(dirs[k]->path() + "\\" + imgFileNames[k].at(i));
                index++;
                emit standardTestResult(k, i, index, tag);
            }
        }
    }
    std::cout<<"here"<<std::endl;

    emit finished();
}
