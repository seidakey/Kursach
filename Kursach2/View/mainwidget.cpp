#include "mainwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidgetItem>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    QListWidgetItem *item;
    item = new QListWidgetItem("Просмотр");
    listMenuLayout->addMenu(item, conspectusView);
    item = new QListWidgetItem("Репититор");
    listMenuLayout->addMenu(item, repetitorView);
    item = new QListWidgetItem("Тестер");
    listMenuLayout->addMenu(item, new QPushButton);
    item = new QListWidgetItem("Экзаменатор");
    listMenuLayout->addMenu(item, new QPushButton);
    setLayout(listMenuLayout);
}

void MainWidget::setWorkbook(QSharedPointer<Workbook> workbook)
{
    listMenuLayout->setTitle(workbook->getInfo().getTitle());
    conspectusView->setWorkbook(workbook);
    repetitorView->setWorkbook(workbook);
}
