#ifndef ALIGNLAYOUT_H
#define ALIGNLAYOUT_H

#include <QLayout>

class AlignLayout : public QLayout
{
public:
    AlignLayout();
    void setWidget(QWidget *widget);
};

#endif // ALIGNLAYOUT_H
