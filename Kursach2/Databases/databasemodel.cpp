#include "databasemodel.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QErrorMessage>
#include <QSqlError>
#include <QDebug>

DatabaseModel::DatabaseModel(QString dbname, QString dbpath)
{
    db = QSqlDatabase::addDatabase(dbname);
    db.setDatabaseName(dbpath);
    if(!db.open()) {
        QErrorMessage errorMessage;
        errorMessage.showMessage(QString("Database \"%1\" can not be opened. %2.").arg(dbname, db.lastError().text()));
    }
}

QSqlDatabase &DatabaseModel::getDatabase()
{
    return db;
}

DatabaseModel::~DatabaseModel() {
    db.close();
}
