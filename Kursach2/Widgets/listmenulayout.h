#ifndef LISTMENULAYOUT_H
#define LISTMENULAYOUT_H

#include <QStackedWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QLabel>

class ListMenuLayout : public QHBoxLayout
{
    Q_OBJECT
    QStackedWidget *stackedWidget = new QStackedWidget;
    QListWidget *listWidget = new QListWidget;
    QLabel *lblTitle = new QLabel;
public:
    ListMenuLayout(QWidget *parent = 0);
    void addMenu(QListWidgetItem *item, QWidget *widget);
    void setTitle(const QString &title);
};

#endif // LISTMENUWIDGET_H
