#include "mainwindow.h"
#include <QApplication>
#include "Databases/database.h"

int main(int argc, char *argv[])
{
    Database::initDatabase("QSQLITE", R"(/home/misha/Programs/Kursach2/db.db)");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
