#include "workbookinfodao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

const QString WorkbookInfoDao::WORKBOOK_LIST_SQL = "SELECT * FROM CONSPECTUS";

QVector<WorkbookInfo> WorkbookInfoDao::getWorkbookInfoAll()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery qry(db);
    qry.exec(WORKBOOK_LIST_SQL);
    QSqlRecord record = qry.record();
    int idCol = record.indexOf("id");
    int titleCol = record.indexOf("title");
    int tableNameCol = record.indexOf("table_name");
    QVector<WorkbookInfo> info;
    while(qry.next())
        info.append(WorkbookInfo(qry.value(idCol).toInt(),
                                 qry.value(titleCol).toString(),
                                 qry.value(tableNameCol).toString()));
    return info;
}
