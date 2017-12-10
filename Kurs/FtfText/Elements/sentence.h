#ifndef SENTENCE_H
#define SENTENCE_H

#include "FtfText/AbstractElement/ftfelement.h"
#include "FtfText/AbstractElement/ftfmediumelement.h"

template<>
class FtfElement<SENTENCE> : public FtfMediumElement<false, true, true>
{
public:
    FtfTag getTag()
    {
        return SENTENCE;
    }
    QString getHtml()
    {
        return *text->getText();
    }
};

#endif // SENTENCE_H
