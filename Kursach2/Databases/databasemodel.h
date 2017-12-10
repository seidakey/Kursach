#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include <QString>
#include <QVector>
#include <QtSql/QSqlQueryModel>

class DatabaseModel
{
protected:
    QSqlDatabase db;
public:
    DatabaseModel(QString dbname, QString dbpath);
    QSqlDatabase &getDatabase();
    ~DatabaseModel();
};

#endif // DATABASEMODEL_H
