#ifndef QUESTION_H
#define QUESTION_H

#include <QVector>
#include <QString>

class Question
{
    QString question;
    QString answer;
    QVector<QString> hints;
public:
    Question();
    Question(QString question, QString answer);
    void setQuestion(const QString &question);
    const QString &getQuestion();
    void setAnswer(const QString &answer);
    const QString &getAnswer();
    QVector<QString> &getHints();
};

#endif // QUESTION_H
