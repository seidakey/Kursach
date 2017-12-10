#ifndef WORKBOOKDAO_H
#define WORKBOOKDAO_H

#include <QString>
#include "Model/workbook.h"
#include <QSharedPointer>

class WorkbookDao
{
protected:
    static const QString WORKBOOK_BY_TABLE;
    static QSharedPointer<Workbook> workbook;
public:
    WorkbookDao() = delete;
    static void setWorkbookByWorkbookInfo(const WorkbookInfo &info);
    static QSharedPointer<Workbook> getWorkbook();
};

#endif // WORKBOOKDAO_H
