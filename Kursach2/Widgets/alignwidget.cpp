#include "alignwidget.h"
#include <QVBoxLayout>

AlignWidget::AlignWidget(QWidget *widg, Qt::Alignment alignment, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vblMain = new QVBoxLayout;
    vblMain->addWidget(widg);
    vblMain->setAlignment(alignment);
    setLayout(vblMain);
}
