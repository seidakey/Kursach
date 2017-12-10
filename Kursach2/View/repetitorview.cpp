#include "repetitorview.h"
#include "Widgets/alignwidget.h"

RepetitorView::RepetitorView()
{
    lblQuestions->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *vblLeft = new QVBoxLayout;
    vblLeft->addWidget(lblQuestions);
    vblLeft->addWidget(listWidget);
    stackedLayout->addWidget(new AlignWidget(repetitorQuestionBrowser, Qt::AlignHCenter));
    stackedLayout->addWidget(simpleHintsAndAnswerQuestionBrowser);
    QHBoxLayout *hblMain = new QHBoxLayout;
    hblMain->addLayout(vblLeft);
    hblMain->addLayout(stackedLayout);
    setLayout(hblMain);
    listWidget->setWordWrap(true);
    listWidget->setFixedWidth(200);
    connect(listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(setQuestion(int)));
}

void RepetitorView::setQuestion(int idx)
{
    if(idx < 0) return;
    repetitorQuestionBrowser->setQuestion(&(*questions)[idx]);
    simpleHintsAndAnswerQuestionBrowser->setQuestion(&(*questions)[idx]);
}

void RepetitorView::setWorkbook(QSharedPointer<Workbook> workbook)
{
    this->workbook = workbook;
    questions = &workbook->getQuestions();
    listWidget->clear();
    for(auto it = questions->begin(); it != questions->end(); ++it)
        listWidget->addItem(it->getQuestion());
}
