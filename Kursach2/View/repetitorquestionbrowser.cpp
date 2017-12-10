#include "repetitorquestionbrowser.h"

RepetitorQuestionBrowser::RepetitorQuestionBrowser()
{
    lblMain->setAlignment(Qt::AlignHCenter);
    lblQuestion->setAlignment(Qt::AlignHCenter);
    lblHint->setAlignment(Qt::AlignHCenter);
    lblQuestion->setWordWrap(true);
    lblHint->setWordWrap(true);
    setFixedSize(500,350);
    QHBoxLayout *hblYesNo = new QHBoxLayout;
    hblYesNo->addWidget(pbNo);
    hblYesNo->addWidget(pbYes);
    QHBoxLayout *hblNextPrev = new QHBoxLayout;
    hblNextPrev->addWidget(pbPrev);
    hblNextPrev->addWidget(pbNext);

    QVBoxLayout *vblMain = new QVBoxLayout;
    vblMain->addWidget(lblMain);
    vblMain->addWidget(lblQuestion);
    vblMain->addWidget(lblHint);
    vblMain->addWidget(pbHint);
    vblMain->addLayout(hblYesNo);
    vblMain->addLayout(hblNextPrev);
    setLayout(vblMain);

    connect(pbNext, SIGNAL(clicked(bool)), this, SIGNAL(next_pressed()));
    connect(pbPrev, SIGNAL(clicked(bool)), this, SIGNAL(prev_pressed()));
    connect(pbHint, SIGNAL(clicked(bool)), this, SLOT(hint_pressed()));
}

void RepetitorQuestionBrowser::setQuestion(Question *question)
{
    hints = &question->getHints();
    lblQuestion->setText(question->getQuestion());
}

void RepetitorQuestionBrowser::hint_pressed()
{

}
