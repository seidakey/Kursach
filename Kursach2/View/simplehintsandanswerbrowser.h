#ifndef SIMPLEHINTSANSANSWERBROWSER_H
#define SIMPLEHINTSANSANSWERBROWSER_H

#include <QWidget>
#include <QVBoxLayout>
#include "simpleanswerbrowser.h"
#include "hintsbrowser.h"

class SimpleHintsAndAnswerBrowser : public QWidget
{
protected:
    SimpleAnswerBrowser *simpleAnswerBrowser = new SimpleAnswerBrowser;
    HintsBrowser *hintsBrowser = new HintsBrowser;
public:
    SimpleHintsAndAnswerBrowser();
    void setQuestion(Question *question);
};

#endif // SIMPLEQUESTIONBROWSER_H
