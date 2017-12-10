#include "workbook.h"

Workbook::Workbook() {}

void Workbook::setInfo(const WorkbookInfo &info)
{
    this->info = info;
}

const WorkbookInfo &Workbook::getInfo()
{
    return info;
}

QVector<Question> &Workbook::getQuestions()
{
    return questions;
}
