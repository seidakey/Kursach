#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebEngineWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QWidget *mainWidg = new QWidget;
    QVBoxLayout *vbl = new QVBoxLayout;
    view = new QWebEngineView();
    QPushButton *pb = new QPushButton("Push me");
    vbl->addWidget(view);
    vbl->addWidget(pb);
    mainWidg->setLayout(vbl);
    ui->setupUi(this);
    view->load(QUrl("http://www.qt.io/"));
    view->load(QUrl("file:///home/misha/Programs/Kursach/Kurs/test.html"));
    this->setCentralWidget(mainWidg);
    connect(pb, SIGNAL(clicked(bool)), this, SLOT(runJs()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
