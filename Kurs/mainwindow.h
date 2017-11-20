#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWebEngineView *view;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void runJs() {
        QWebEnginePage *page = view->page();
        page->runJavaScript("alert(document.getElementById('1').value);", [](const QVariant &v) { qDebug() << v.toString(); });
    }

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
