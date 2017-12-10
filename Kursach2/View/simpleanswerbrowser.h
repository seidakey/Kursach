#ifndef SIMPLEANSWERBROWSER_H
#define SIMPLEANSWERBROWSER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QLabel>
#include "Model/question.h"
#include "View/hintsbrowser.h"

class SimpleAnswerBrowser : public QWidget
{
    Q_OBJECT
protected:
    QLabel *lblTitle = new QLabel;
    QTextBrowser *textBrowser = new QTextBrowser;
public:
    SimpleAnswerBrowser();
    void setQuestion(Question *question);
};

#endif // SIMPLEANSWERBROWSER_H
