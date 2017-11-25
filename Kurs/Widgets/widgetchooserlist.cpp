#include "widgetchooserlist.h"

WidgetChooserList::WidgetChooserList() {}

WidgetChooserList::WidgetChooserList(QVector<WidgetChooserItem> &item_v)
{
    /*----------------------------VIEW----------------------------*/

    addItems(item_v);

    listWidget->setFixedWidth(230);

    mainHBL->setSpacing(0);

    mainHBL->addWidget(listWidget);
    mainHBL->addWidget(stackedWidget);

    setLayout(mainHBL);

    /*-------------------------CONTROLLER-------------------------*/

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
}

void WidgetChooserList::addItems(QVector<WidgetChooserItem> &item_v)
{
    for(auto it = item_v.begin(); it < item_v.end(); ++it)
        addItem(*it);
}

void WidgetChooserList::addItem(WidgetChooserItem &item) {
    listWidget->addItem(item.getWidgetName());
    stackedWidget->addWidget(item.getWidget());
}
