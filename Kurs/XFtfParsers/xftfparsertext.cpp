#include "xftfparsertext.h"
#include "xftftagname.h"
#include "FtfText/Elements/elements.h"
#include <QXmlStreamAttribute>
#include <QXmlStreamAttributes>
#include <QLoggingCategory>
#include "FtfText/ftftaginfo.h"
#include "XFtfParsers/xmltokentypeinfo.h"
#include "FtfText/Questions/question.h"
#include "FtfText/Questions/questions.h"

const QString logStartDocument = "StartDocument";
const QString logEndDocument = "EndDocument";
const QString logStartElement = "StartElement";
const QString logEndElement = "EndElement";

void XFtfParserText::skipCharacters()
{
    if(isTokenType(QXmlStreamReader::Characters))
        next();
}

XFtfParserText::XFtfParserText(FtfDocument *doc, QXmlStreamReader *xml)
    : doc(doc), xml(xml) {}

XFtfParserText &XFtfParserText::setDocument(FtfDocument *doc)
{
    this->doc = doc;
    return *this;
}

XFtfParserText &XFtfParserText::setXmlStreadReader(QXmlStreamReader *xml)
{
    this->xml = xml;
    return *this;
}

void XFtfParserText::next()
{
    xml->readNext();
}

QString XFtfParserText::getText()
{
    return xml->text().toString();
}

bool XFtfParserText::isTagName(const QString &tagName)
{
    return xml->name() == tagName;
}

bool XFtfParserText::isStartTagNameAssert(const QString &tagName)
{
    if(xml->name() != tagName)
    {
        logUnexpectedStartTag(tagName);
        return false;
    }
    return true;
}

bool XFtfParserText::isEndTagNameAssert(const QString &tagName)
{
    if(xml->name() != tagName)
    {
        logUnexpectedEndTag(tagName);
        return false;
    }
    return true;
}

bool XFtfParserText::isEndTagAssert(const QString &tagName)
{
    if(!isTokenTypeAssert(QXmlStreamReader::EndElement)
        || !isEndTagNameAssert(tagName))
        return false;
    return true;
}

bool XFtfParserText::isTokenType(QXmlStreamReader::TokenType tokenType)
{
    return xml->tokenType() == tokenType;
}

bool XFtfParserText::isTokenTypeAssert(QXmlStreamReader::TokenType tokenType)
{
    if(xml->tokenType() != tokenType)
    {
        logUnexpectedTokenType(XmlTokenTypeInfo::getName(tokenType));
        return false;
    }
    return true;
}

bool XFtfParserText::readDocument() {
    static const QString functionName = "XFtfParserText::readDocument";
    functionNameStack.push_back(&functionName);
    //Check StartDocument
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::StartDocument))
        return false;
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::StartElement))
        return false;
    else if(!isStartTagNameAssert(XFtfTagName::DOCUMENT))
        return false;
    //Read questions
    next();
    skipCharacters();
    if(!isTokenTypeAssert(QXmlStreamReader::StartElement))
        return false;
    else if(!isStartTagNameAssert(XFtfTagName::QUESTIONS))
        return false;
    if(!readQuestions())
        return false;
    //Read text
    next();
    skipCharacters();
    if(!isTokenTypeAssert(QXmlStreamReader::StartElement))
        return false;
    else if(!isStartTagNameAssert(XFtfTagName::TEXT))
        return false;
    if(!readText())
        return false;
    //Check EndDocument
    next();
    skipCharacters();
    if(!isTokenTypeAssert(QXmlStreamReader::EndElement))
        return false;
    else if(!isStartTagNameAssert(XFtfTagName::DOCUMENT))
        return false;
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::EndDocument))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readQuestions()
{
    static const QString functionName = "XFtfParserText::readQuestions";
    functionNameStack.push_back(&functionName);
    for(next();;next()) {
        if(isTokenType(QXmlStreamReader::Characters))
            continue;
        if(!isTokenType(QXmlStreamReader::StartElement))
            break;
        if(!isStartTagNameAssert(XFtfTagName::QUESTION))
            return false;
        else if(!readQuestion())
            return false;
    }
    if(!isEndTagAssert(XFtfTagName::QUESTIONS))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readQuestion()
{
    static const QString functionName = "XFtfParserText::readQuestion";
    functionNameStack.push_back(&functionName);
    QXmlStreamAttributes attrs= xml->attributes();
    if(!attrsCountEqualsAssert(attrs.size(),1))
        return false;
    static const QString tagName = "tag";
    if(attrs.at(0).name() != tagName)
    {
        qCritical() << "Attribute tag not found";
        return false;
    }
    QMap<QString,Question>::iterator it = doc->getQuestions()->getQuestions()
            .insert(attrs.at(0).value().toString(), Question());
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::Characters))
        return false;
    it.value().setText(getText());
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::EndElement))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readText()
{
    static const QString functionName = "XFtfParserText::readText";
    functionNameStack.push_back(&functionName);
    QSharedPointer<FtfElement<TEXT>> elem = doc->getText();
    for(next();;next()) {
        if(isTokenType(QXmlStreamReader::Characters))
            continue;
        if(!isTokenType(QXmlStreamReader::StartElement))
            break;
        bool result;
        if(isTagName(XFtfTagName::PARAGRAPH))
            result = readParagraph(elem);
        else if(isTagName(XFtfTagName::TITLE))
            result = readTitle(elem);
        else {
            logUnexpectedStartTag();
            return false;
        }
        if(!result)
            return false;
    }
    if(!isEndTagAssert(XFtfTagName::TEXT))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readParagraph(QSharedPointer<FtfAbstractElement> parent)
{
    static const QString functionName = "XFtfParserText::readParagraph";
    functionNameStack.push_back(&functionName);
    QSharedPointer<FtfElement<PARAGRAPH>> elem(new FtfElement<PARAGRAPH>);
    parent->elements->addElement(elem);
    for(next();;next()) {
        if(isTokenType(QXmlStreamReader::Characters))
            continue;
        if(!isTokenType(QXmlStreamReader::StartElement))
            break;
        bool result;
        if(isTagName(XFtfTagName::SENTENCE))
            result = readSentence(elem);
        else if (isTagName(XFtfTagName::QUESTION_POINTER))
            result = readQuestionPointer(elem);
        else {
            logUnexpectedStartTag();
            return false;
        }
        if(!result)
            return false;
    }
    if(!isEndTagAssert(XFtfTagName::PARAGRAPH))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readSentence(QSharedPointer<FtfAbstractElement> parent)
{
    static const QString functionName = "XFtfParserText::readSentence";
    functionNameStack.push_back(&functionName);
    QSharedPointer<FtfElement<SENTENCE>> elem(new FtfElement<SENTENCE>);
    parent->elements->addElement(elem);
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::Characters))
        return false;
    elem->text->setText(getText());
    next();
    if(!isEndTagAssert(XFtfTagName::SENTENCE))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readQuestionPointer(QSharedPointer<FtfAbstractElement> parent)
{
    static const QString functionName = "XFtfParserText::readQuestionPointer";
    functionNameStack.push_back(&functionName);
    QXmlStreamAttributes attrs= xml->attributes();
    if(!attrsCountEqualsAssert(attrs.size(),1))
        return false;
    static const QString tagName = "tag";
    if(attrs.at(0).name() != tagName)
    {
        qCritical() << "Attribute tag not found";
        return false;
    }
    QMap<QString,Question>::iterator it = doc->getQuestions()->getQuestions()
            .find(attrs.at(0).value().toString());
    it.value().addAnswer(parent);
    next();
    if(!isEndTagAssert(XFtfTagName::QUESTION_POINTER))
        return false;
    functionNameStack.pop_back();
    return true;
}

bool XFtfParserText::readTitle(QSharedPointer<FtfAbstractElement> parent)
{
    static const QString functionName = "XFtfParserText::readTitle";
    functionNameStack.push_back(&functionName);
    QSharedPointer<FtfElement<TITLE>> elem(new FtfElement<TITLE>);
    parent->elements->addElement(elem);
    next();
    if(!isTokenTypeAssert(QXmlStreamReader::Characters))
        return false;
    elem->text->setText(getText());
    next();
    if(!isEndTagAssert(XFtfTagName::TITLE))
        return false;
    functionNameStack.pop_back();
    return true;
}

void XFtfParserText::logUnexpectedStartTag()
{
    qCritical() << *functionNameStack.last() << " : Unexpected start tag <" << xml->name() << ">";
}

void XFtfParserText::logUnexpectedEndTag()
{
    qCritical() << *functionNameStack.last() << " : Unexpected end tag </" << xml->name() << ">";
}

void XFtfParserText::logUnexpectedStartTag(const QString &tagExpected)
{
    qCritical() << *functionNameStack.last() << " : Unexpected start tag <" << xml->name() << ">. Expected </"
                << tagExpected << ">";
}

void XFtfParserText::logUnexpectedEndTag(const QString &tagExpected)
{
    qCritical() << *functionNameStack.last() << " : Unexpected end tag </" << xml->name() << ">. Expected </"
                << tagExpected << ">";
}

void XFtfParserText::logUnexpectedTokenType(const QString &tokenTypeExpected)
{
    qCritical() << *functionNameStack.last() << " : Unexpected token type: '" << xml->tokenString()
                << "' Expected: " << tokenTypeExpected << xml->errorString();
}

void XFtfParserText::logExpectedContent()
{
    qCritical() << *functionNameStack.last() << " : Expected element content.";
}

bool XFtfParserText::attrsCountEqualsAssert(int got, int expected)
{
    if(got != expected){
        qCritical() << "Wrong count of attributes at tag " << xml->name()
                    << ". Expected: " << expected << ". Got: " << expected;
        return false;
    }
    return true;
}

QString XFtfParserText::getFullInfo()
{
    QString info = " ";
    info += "name: " + xml->name() + ", ";
    info += "text: " + xml->text() + ", ";
    info += "tokenType: " + xml->tokenString();
    return info;
}
