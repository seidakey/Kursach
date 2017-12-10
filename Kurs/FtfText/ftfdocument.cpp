#include "ftfdocument.h"

FtfDocument::FtfDocument()
    : text(new FtfElement<TEXT>), questions(new Questions) {}

QSharedPointer<FtfElement<TEXT>> FtfDocument::getText()
{
    return text;
}

QSharedPointer<Questions> FtfDocument::getQuestions()
{
    return questions;
}
