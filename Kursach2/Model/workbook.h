#ifndef WORKBOOK_H
#define WORKBOOK_H

#include "question.h"
#include "workbookinfo.h"

class Workbook
{
protected:
    WorkbookInfo info;
    QVector<Question> questions;
public:
    Workbook();
    void setInfo(const WorkbookInfo &info);
    const WorkbookInfo &getInfo();
    QVector<Question> &getQuestions();
};

#endif // WORKBOOK_H
