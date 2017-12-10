#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    struct Mode
    {
        QString name;
        QWidget * widg;
        Mode(QString name, QWidget *widg)
            : name(name), widg(widg) {}
    };

public:
    QMenu * modeMenu = new QMenu("Mode");
    QMenuBar * menuBar = new QMenuBar;
    QStackedWidget * stackedWidget = new QStackedWidget;
    QMap<QAction*, int> action_m;
    //QWebEngineView *view;
    explicit MainWindow(QString html, QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void runJs() {
        //QWebEnginePage *page = view->page();
        //page->runJavaScript("alert(document.getElementById('1').value);", [](const QVariant &v) { qDebug() << v.toString(); });
    }
    void setMode();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
