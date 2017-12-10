#include "hintsbrowser.h"

HintsBrowser::HintsBrowser()
{
    lblHints->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *vblMain = new QVBoxLayout;
    vblMain->setMargin(2);
    vblMain->addWidget(lblHints);
    vblMain->addWidget(listWidget);
    vblMain->addWidget(lineEdit);
    vblMain->addWidget(btnAddHint);
    setLayout(vblMain);
    connect(btnAddHint, SIGNAL(clicked(bool)), this, SLOT(addHint()));
}

void HintsBrowser::setHints(QVector<QString> *hints)
{
    this->hints = hints;
}

void HintsBrowser::addHint()
{
    hints->append(lineEdit->text());
    listWidget->addItem(lineEdit->text());
    lineEdit->clear();
}
