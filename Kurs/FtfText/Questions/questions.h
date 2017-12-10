#ifndef QUESTIONS_H
#define QUESTIONS_H

#include "question.h"
#include <QMap>

class Questions
{
protected:
    QMap<QString, Question> question_m;
public:
    QMap<QString, Question> &getQuestions();
};

#endif // QUESTIONS_H
