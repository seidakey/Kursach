#include "database.h"
#include <QErrorMessage>
#include <QSqlError>

void Database::initDatabase(QString dbname, QString dbpath)
{
    QSqlDatabase::addDatabase(dbname);
    QSqlDatabase::database().setDatabaseName(dbpath);
    if(!QSqlDatabase::database().open()) {
        QErrorMessage errorMessage;
        errorMessage.showMessage(QString("Database \"%1\" can not be opened. %2.")
                                 .arg(dbname, QSqlDatabase::database().lastError().text()));
    }
}
