#include "ftftaginfo.h"

QVector<QString> FtfTagInfo::name_v;

void FtfTagInfo::init()
{
    name_v.resize(7);
    name_v[TEXT] = "text";
    name_v[PARAGRAPH] = "paragraph";
    name_v[QUESTION] = "question";
    name_v[QUESTIONS] = "questions";
    name_v[QUESTION_POINTER] = "question pointer";
    name_v[TITLE] = "title";
    name_v[PARAGRAPH] = "paragraph";
}

const QString &FtfTagInfo::getTagName(FtfTag tag)
{
    return name_v[tag];
}
