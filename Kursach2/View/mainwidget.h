#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include <QListWidget>
#include "Widgets/listmenulayout.h"
#include "conspectusview.h"
#include "repetitorview.h"

class MainWidget : public QWidget
{
    Q_OBJECT
protected:
    ListMenuLayout *listMenuLayout = new ListMenuLayout;
    ConspectusView *conspectusView = new ConspectusView;
    RepetitorView *repetitorView = new RepetitorView;
public:
    explicit MainWidget(QWidget *parent = 0);
    void setWorkbook(QSharedPointer<Workbook> workbook);
signals:

public slots:
};

#endif // MAINWIDGET_H
