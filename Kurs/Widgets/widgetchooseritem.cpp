#include "widgetchooseritem.h"

WidgetChooserItem::WidgetChooserItem()
    : widget_(NULL) {}

WidgetChooserItem::WidgetChooserItem(QString widgetName, QWidget *widget)
    : widgetName_(widgetName), widget_(widget) {}

void WidgetChooserItem::setWidget(QWidget *widget)
{
    widget_ = widget;
}

void WidgetChooserItem::setWidgetName(const QString &widgetName)
{
    widgetName_ = widgetName;
}

void WidgetChooserItem::setWidgetName(QString &&widgetName) {
    widgetName_ = widgetName;
}

QWidget* WidgetChooserItem::getWidget() {
    return widget_;
}

const QString& WidgetChooserItem::getWidgetName() const {
    return widgetName_;
}
