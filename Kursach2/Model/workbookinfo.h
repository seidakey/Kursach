#ifndef WORKBOOKINFO_H
#define WORKBOOKINFO_H

#include <QString>

class WorkbookInfo
{
    int id;
    QString title;
    QString tableName;
public:
    WorkbookInfo();
    WorkbookInfo(int id, QString name, QString tableName);
    int getId() const;
    void setId(int id);
    const QString &getTitle() const;
    void setTitle(const QString &title);
    const QString &getTableName() const;
    void setTableName(const QString &tableName);
};

#endif // WORKBOOKINFO_H
