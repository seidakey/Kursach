#ifndef TITLE_H
#define TITLE_H

#include "FtfText/AbstractElement/ftfelement.h"
#include "FtfText/AbstractElement/ftfmediumelement.h"

template<>
class FtfElement<TITLE> : public FtfMediumElement<false, false, true>
{
public:
    FtfTag getTag()
    {
        return TITLE;
    }
    QString getHtml()
    {
        return *text->getText();
    }
};

#endif // TITLE_H
