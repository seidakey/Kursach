#ifndef CONSPECTUSVIEW_H
#define CONSPECTUSVIEW_H

#include <QWidget>
#include <QSharedPointer>
#include <QListWidget>
#include "Model/workbook.h"
#include "simplehintsandanswerbrowser.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

class ConspectusView : public QWidget
{
    Q_OBJECT
protected:
    QListWidget *listWidget = new QListWidget;
    SimpleHintsAndAnswerBrowser *simpleHintsAndAnswerQuestionBrowser = new SimpleHintsAndAnswerBrowser;
    QSharedPointer<Workbook> workbook;
    QVector<Question> *questions;
    QLabel *lblQuestions = new QLabel("Вопросы");
public:
    explicit ConspectusView(QWidget *parent = 0);
    void setWorkbook(QSharedPointer<Workbook> workbook);
signals:

protected slots:
    void setAnswer(int idx);
};

#endif // CONSPECTUSVIEW_H
