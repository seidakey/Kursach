#ifndef REPETITORVIEW_H
#define REPETITORVIEW_H

#include <QWidget>
#include <QSharedPointer>
#include <QListWidget>
#include "Model/workbook.h"
#include "simplehintsandanswerbrowser.h"
#include "repetitorquestionbrowser.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include "Model/workbook.h"

class RepetitorView : public QWidget
{
    Q_OBJECT
protected:
    QListWidget *listWidget = new QListWidget;
    SimpleHintsAndAnswerBrowser *simpleHintsAndAnswerQuestionBrowser = new SimpleHintsAndAnswerBrowser;
    RepetitorQuestionBrowser *repetitorQuestionBrowser = new RepetitorQuestionBrowser;
    QStackedLayout *stackedLayout = new QStackedLayout;
    QSharedPointer<Workbook> workbook;
    QVector<Question> *questions;
    QLabel *lblQuestions = new QLabel("Вопросы");
public:
    RepetitorView();
    void setWorkbook(QSharedPointer<Workbook> workbook);
protected slots:
    void setQuestion(int idx);
};

#endif // REPETITORVIEW_H
