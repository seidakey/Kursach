#include "textbrowser.h"

TextBrowser::TextBrowser()
{
    QVBoxLayout *vbl = new QVBoxLayout;
    vbl->addWidget(listWidget);
    vbl->addWidget(lineEdit);
    vbl->addWidget(btn_add_hint);
    QHBoxLayout *hblMain = new QHBoxLayout;
    hblMain->addLayout(vbl);
    hblMain->addWidget(textBrowser);
    setLayout(hblMain);
}

void TextBrowser::setQuestion(Question *question)
{
    listWidget->clear();
    QVector<QString> hints = question->getHints();
    for(auto it = hints.begin(); it != hints.end(); ++it)
        listWidget->addItem(*it);
    textBrowser->setText(question->getAnswer());
}
