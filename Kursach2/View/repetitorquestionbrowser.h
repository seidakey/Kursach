#ifndef REPETITORQUESTIONBROWSER_H
#define REPETITORQUESTIONBROWSER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "Model/question.h"

class RepetitorQuestionBrowser : public QWidget
{
    Q_OBJECT
protected:
    QPushButton *pbNext  = new QPushButton("Следующий");
    QPushButton *pbPrev = new QPushButton("Предыдущий");
    QPushButton *pbYes = new QPushButton("Да");
    QPushButton *pbNo = new QPushButton("Нет");
    QPushButton *pbHint = new QPushButton("Подсказка");
    QLabel *lblHint = new QLabel;
    QLabel *lblQuestion = new QLabel;
    QLabel *lblMain = new QLabel("Знаете ли вы ответ на следующий вопрос?");
    QVector<QString> *hints;
public:
    RepetitorQuestionBrowser();
    void setQuestion(Question *question);
protected slots:
    void hint_pressed();
signals:
    void prev_pressed();
    void next_pressed();
};

#endif // REPETITORQUESTIONBROWSER_H
