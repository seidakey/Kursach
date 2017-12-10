#include "question.h"

Question::Question() {}

Question::Question(QString question, QString answer)
    : question(question), answer(answer) {}

const QString &Question::getAnswer() { return answer; }

const QString &Question::getQuestion() { return question; }

QVector<QString> &Question::getHints() { return hints; }

void Question::setAnswer(const QString &answer) { this->answer = answer; }

void Question::setQuestion(const QString &question) { this->question = question; }
