#ifndef WORKBOOKINFOLIST_H
#define WORKBOOKINFOLIST_H

#include <QVector>
#include "Model/workbookinfo.h"

class WorkbookInfoDao
{
protected:
    static const QString WORKBOOK_LIST_SQL;
public:
    WorkbookInfoDao() = delete;
    static QVector<WorkbookInfo> getWorkbookInfoAll();
};

#endif // WORKBOOKINFOLIST_H
