#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include "View/mainwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    QMenu * menuConspectus = new QMenu("Конспект");
    QAction * actionOpen = new QAction("Открыть");
    QMenuBar * menuBar = new QMenuBar;
    MainWidget * mainWidget = new MainWidget;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void openConspectus();
};

#endif // MAINWINDOW_H
