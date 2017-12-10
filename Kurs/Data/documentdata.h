#ifndef DOCUMENTDATA_H
#define DOCUMENTDATA_H

#include "FtfText/ftfdocument.h"
#include <QIODevice>

class DocumentData
{
private:
    static FtfDocument *document;
public:
    DocumentData() = delete;
    static void load(QIODevice *device);
    static FtfDocument *getDocument();
};

#endif // DOCUMENTDATA_H
