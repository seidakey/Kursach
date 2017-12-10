#include "conspectuschooser.h"
#include "DAO/workbookdao.h"
#include <QDebug>

ConspectusChooser::ConspectusChooser(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Выберите конспект");
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    for(auto it = info.begin(); it != info.end(); ++it)
        listWidget->addItem(it->getTitle());
    QHBoxLayout *hblDefaultButtons = new QHBoxLayout;
    hblDefaultButtons->setAlignment(Qt::AlignRight);
    hblDefaultButtons->addWidget(pbCancel);
    hblDefaultButtons->addWidget(pbOpen);
    QVBoxLayout *vblMain = new QVBoxLayout;
    vblMain->addWidget(lblConspectuses);
    vblMain->addWidget(listWidget);
    vblMain->addLayout(hblDefaultButtons);
    setLayout(vblMain);
    connect(pbOpen, SIGNAL(clicked(bool)), this, SLOT(open_pressed()));
    connect(pbCancel, SIGNAL(clicked(bool)), this, SLOT(cancel_pressed()));
}

void ConspectusChooser::open_pressed()
{
    int idx = listWidget->currentRow();
    WorkbookDao::setWorkbookByWorkbookInfo(info[idx]);
    accept();
}

void ConspectusChooser::cancel_pressed()
{
    reject();
}
