#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
public:
    Database() = delete;
    static void initDatabase(QString dbname, QString dbpath);
};

#endif // DATABASE_H
