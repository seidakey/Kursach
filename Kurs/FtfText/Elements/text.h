#ifndef TEXT_H
#define TEXT_H

#include "FtfText/AbstractElement/ftfelement.h"
#include "FtfText/AbstractElement/ftfmediumelement.h"
#include <QStringBuilder>

template<>
class FtfElement<TEXT> : public FtfMediumElement<noAttributes, hasElements, noText>
{
public:
    FtfTag getTag()
    {
        return TEXT;
    }
    QString getHtml()
    {
        QString html;
        html = html % QString("<html>");
        html = html % QString("<body>");
        for(QSharedPointer<FtfAbstractElement> element : *elements->getElements())
            html = html % element->getHtml() % "<br/>";
        html = html % "</body>";
        html = html % "</html>";
        return html;
    }
};

#endif // TEXT_H
