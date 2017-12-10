#include "mainwindow.h"
#include "View/conspectuschooser.h"
#include "DAO/workbookdao.h"
#include "View/mainwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    menuConspectus->addAction(actionOpen);
    menuBar->addMenu(menuConspectus);
    this->setMenuBar(menuBar);
    connect(actionOpen, SIGNAL(triggered(bool)), this, SLOT(openConspectus()));
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}

void MainWindow::openConspectus()
{
    ConspectusChooser chooser;
    if(chooser.exec() == QDialog::Accepted)
        mainWidget->setWorkbook(WorkbookDao::getWorkbook());
}
