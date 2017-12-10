#include "workbookinfo.h"

WorkbookInfo::WorkbookInfo() {}

WorkbookInfo::WorkbookInfo(int id, QString title, QString tableName)
    : id(id), title(title), tableName(tableName) {}

int WorkbookInfo::getId() const
{
    return id;
}

void WorkbookInfo::setId(int id)
{
    this->id = id;
}

const QString &WorkbookInfo::getTitle() const
{
    return title;
}

void WorkbookInfo::setTitle(const QString &title)
{
    this->title = title;
}

const QString &WorkbookInfo::getTableName() const
{
    return tableName;
}

void WorkbookInfo::setTableName(const QString &tableName)
{
    this->tableName = tableName;
}
