#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Widgets/Modes/tutormodewidget.h"
#include <QtWebEngineWidgets>
#include <QPair>

MainWindow::MainWindow(QString html, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //MENU
    QList<Mode> modes;
    modes.append(Mode("Tutor", new TutorModeWidget));
    int num = 0;
    for(Mode mode : modes)
    {
        QAction *action = modeMenu->addAction(mode.name);
        stackedWidget->addWidget(mode.widg);
        action_m.insert(action, num);
        connect(action, SIGNAL(triggered(bool)), this, SLOT(setMode()));
        ++num;
    }
    menuBar->addMenu(modeMenu);
    this->setMenuBar(menuBar);
    //MENU END

    QWidget *mainWidg = new QWidget;
    QVBoxLayout *vbl = new QVBoxLayout;
    //view = new QWebEngineView();
    QPushButton *pb = new QPushButton("Push me");
    //vbl->addWidget(view);
    vbl->addWidget(pb);
    mainWidg->setLayout(vbl);
    //view->load(QUrl("http://www.qt.io/"));
    //view->load(QUrl("file:///home/misha/Programs/Kursach/Kurs/test.html"));
    //view->setHtml(html);
    this->setCentralWidget(stackedWidget);
    connect(pb, SIGNAL(clicked(bool)), this, SLOT(runJs()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMode()
{
    stackedWidget->setCurrentIndex(action_m[(QAction*)sender()]);
}
