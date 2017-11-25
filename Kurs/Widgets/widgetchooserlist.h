#ifndef WIDGETCHOOSERLIST_H
#define WIDGETCHOOSERLIST_H

#include <QWidget>
#include <QStackedWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "widgetchooseritem.h"

class WidgetChooserList : public QWidget
{
protected:
    QStackedWidget *stackedWidget = new QStackedWidget;
    QListWidget *listWidget = new QListWidget;
    QHBoxLayout *mainHBL = new QHBoxLayout;
public:
    WidgetChooserList();
    WidgetChooserList(QVector<WidgetChooserItem> &item_v);
    void addItem(WidgetChooserItem &item);
    void addItems(QVector<WidgetChooserItem> &item_v);
};

#endif // WIDGETCHOOSERLIST_H
