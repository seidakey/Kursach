#ifndef XFTFPARSERTEXT_H
#define XFTFPARSERTEXT_H

#include <QXmlStreamReader>
#include <functional>
#include "FtfText/AbstractElement/ftfabstractelement.h"
#include "FtfText/ftfdocument.h"

class XFtfParserText
{
protected:
    static const QString logStartDocument;
    static const QString logEndDocument;
    static const QString logStartElement;
    static const QString logEndElement;
    QList<const QString *> functionNameStack;
    void next();
    QString getText();
    QString getFullInfo();
    void skipCharacters();
    bool isTokenType(QXmlStreamReader::TokenType tokenType);
    bool isTokenTypeAssert(QXmlStreamReader::TokenType tokenType);
    bool isTagName(const QString &tagName);
    bool isStartTagNameAssert(const QString &tagName);
    bool isEndTagNameAssert(const QString &tagName);
    bool isEndTagAssert(const QString &tagName);
    bool attrsCountEqualsAssert(int got, int expected);
    bool readQuestions();
    bool readQuestion();
    bool readText();
    bool readParagraph(QSharedPointer<FtfAbstractElement> parent);
    bool readSentence(QSharedPointer<FtfAbstractElement> parent);
    bool readTitle(QSharedPointer<FtfAbstractElement> parent);
    bool readQuestionPointer(QSharedPointer<FtfAbstractElement> parent);
    void logUnexpectedStartTag();
    void logUnexpectedEndTag();
    void logUnexpectedStartTag(const QString &tagExpected);
    void logUnexpectedEndTag(const QString &tagExpected);
    void logUnexpectedTokenType(const QString &tokenTypeExpected);
    void logExpectedContent();
    FtfDocument *doc;
    QXmlStreamReader *xml;
public:
    XFtfParserText() = delete;
    XFtfParserText(FtfDocument *doc, QXmlStreamReader *xml);
    XFtfParserText &setDocument(FtfDocument *doc);
    XFtfParserText &setXmlStreadReader(QXmlStreamReader *xml);
    bool readDocument();
};

#endif // XFTFPARSERTEXT_H
