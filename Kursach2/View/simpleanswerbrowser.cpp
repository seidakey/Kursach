#include "simpleanswerbrowser.h"
#include <QFont>

SimpleAnswerBrowser::SimpleAnswerBrowser()
{
    QVBoxLayout *vblRight = new QVBoxLayout;
    lblTitle->setWordWrap(true);
    lblTitle->setAlignment(Qt::AlignHCenter);
    QFont font = lblTitle->font();
    font.setPointSize(10);
    font.setBold(true);
    lblTitle->setFont(font);
    vblRight->addWidget(lblTitle);
    vblRight->addWidget(textBrowser);
    vblRight->setMargin(2);
    setLayout(vblRight);
}

void SimpleAnswerBrowser::setQuestion(Question *question)
{
    textBrowser->setText(question->getAnswer());
    lblTitle->setText(question->getQuestion());
}
