#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "FtfText/AbstractElement/ftfelement.h"
#include "FtfText/AbstractElement/ftfmediumelement.h"
#include <QStringBuilder>

template<>
class FtfElement<PARAGRAPH> : public FtfMediumElement<false, true, false>
{
public:
    FtfTag getTag()
    {
        return PARAGRAPH;
    }
    QString getHtml()
    {
        QString html;
        QString space = " ";
        qDebug() << elements->getElements()->size();
        for(QSharedPointer<FtfAbstractElement> element : *elements->getElements())
            html = html % element->getHtml() % space;
        return html;
    }
};

#endif // PARAGRAPH_H
