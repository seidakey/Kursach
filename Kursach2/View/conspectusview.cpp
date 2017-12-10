#include "conspectusview.h"
#include <QDebug>

ConspectusView::ConspectusView(QWidget *parent) : QWidget(parent)
{
    lblQuestions->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *vblLeft = new QVBoxLayout;
    vblLeft->addWidget(lblQuestions);
    vblLeft->addWidget(listWidget);
    QHBoxLayout *hblMain = new QHBoxLayout;
    hblMain->addLayout(vblLeft);
    hblMain->addWidget(simpleHintsAndAnswerQuestionBrowser);
    setLayout(hblMain);
    listWidget->setWordWrap(true);
    listWidget->setFixedWidth(200);
    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(setAnswer(int)));
}

void ConspectusView::setWorkbook(QSharedPointer<Workbook> workbook)
{
    this->workbook = workbook;
    questions = &workbook->getQuestions();
    listWidget->clear();
    for(auto it = questions->begin(); it != questions->end(); ++it)
        listWidget->addItem(it->getQuestion());
}

void ConspectusView::setAnswer(int idx)
{
    if(idx < 0) return;
    simpleHintsAndAnswerQuestionBrowser->setQuestion(&(*questions)[idx]);
}
