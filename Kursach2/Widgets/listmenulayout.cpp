#include "listmenulayout.h"
#include <QSizePolicy>
#include <QDebug>

ListMenuLayout::ListMenuLayout(QWidget *parent)
    : QHBoxLayout(parent)
{
    /*----------------------------VIEW----------------------------*/

    listWidget->setFixedWidth(100);
    listWidget->setFixedHeight(120);

    lblTitle->setWordWrap(true);
    lblTitle->setAlignment(Qt::AlignHCenter);
    QFont font = lblTitle->font();
    font.setPointSize(12);
    font.setBold(true);
    lblTitle->setFont(font);
    this->setSpacing(0);
    this->addWidget(listWidget);
    QVBoxLayout *vblRight = new QVBoxLayout;
    vblRight->addWidget(lblTitle);
    vblRight->addWidget(stackedWidget);
    this->addLayout(vblRight);
    this->setAlignment(listWidget, Qt::AlignTop);
}

void ListMenuLayout::addMenu(QListWidgetItem *item, QWidget *widget)
{
    listWidget->addItem(item);
    stackedWidget->addWidget(widget);
    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
}

void ListMenuLayout::setTitle(const QString &title)
{
    qDebug() << title;
    lblTitle->setText(title);
}
