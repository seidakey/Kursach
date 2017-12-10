#ifndef FTFTEXTMODULE_H
#define FTFTEXTMODULE_H

#include <QString>
#include <QLoggingCategory>

class FtfAbstractTextModule
{
public:
    virtual bool hasImplementation() = 0;
    virtual void setText(const QString &text) = 0;
    virtual const QString *getText() = 0;
    virtual ~FtfAbstractTextModule() {}
};

template<bool hasText>
class FtfTextModule : public FtfAbstractTextModule
{
public:
    bool hasImplementation()
    {
        return false;
    }
    void setText(const QString &text)
    {
        Q_UNUSED(text);
        qCritical() << "Text setting not supported. Got " << text;
    }

    const QString *getText()
    {
        qCritical() << "Text getting not supported.";
        return NULL;
    }
};

template<>
class FtfTextModule<true> : public FtfAbstractTextModule
{
protected:
    QString text;
public:
    bool hasImplementation()
    {
        return true;
    }
    void setText(const QString &text)
    {
        this->text = text;
    }

    const QString *getText()
    {
        return &text;
    }
};

#endif // FTFTEXTMODULE_H
