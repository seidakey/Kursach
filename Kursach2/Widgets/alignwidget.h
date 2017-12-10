#ifndef ALIGNWIDGET_H
#define ALIGNWIDGET_H

#include <QWidget>

class AlignWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AlignWidget(QWidget *widg, Qt::Alignment alignment, QWidget *parent = 0);
signals:

public slots:
};

#endif // ALIGNWIDGET_H
