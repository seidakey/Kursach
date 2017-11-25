#ifndef WIDGETCHOOSERITEM_H
#define WIDGETCHOOSERITEM_H

#include <QWidget>
#include <QString>

class WidgetChooserItem
{
protected:
    QString widgetName_;
    QWidget *widget_;
public:
    WidgetChooserItem();
    WidgetChooserItem(QString widgetName, QWidget *widget);
    const QString &getWidgetName() const;
    QWidget *getWidget();
    void setWidgetName(const QString &widgetName);
    void setWidgetName(QString &&widgetName);
    void setWidget(QWidget * widget);
};

#endif // WIDGETCHOOSERITEM_H
