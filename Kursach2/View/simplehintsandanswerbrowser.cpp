#include "simplehintsandanswerbrowser.h"

SimpleHintsAndAnswerBrowser::SimpleHintsAndAnswerBrowser()
{
    hintsBrowser->setFixedWidth(200);
    QHBoxLayout *hblMain = new QHBoxLayout;
    hblMain->addWidget(hintsBrowser);
    hblMain->addWidget(simpleAnswerBrowser);
    hblMain->setSpacing(0);
    hblMain->setMargin(0);
    setLayout(hblMain);
}

void SimpleHintsAndAnswerBrowser::setQuestion(Question *question)
{
    hintsBrowser->setHints(&question->getHints());
    simpleAnswerBrowser->setQuestion(question);
}
