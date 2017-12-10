#ifndef CONSPECTUSCHOOSER_H
#define CONSPECTUSCHOOSER_H

#include <QDialog>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "Model/workbookinfo.h"
#include "DAO/workbookinfodao.h"

class ConspectusChooser : public QDialog
{
    Q_OBJECT
    QListWidget *listWidget = new QListWidget;
    QLabel *lblConspectuses = new QLabel("Конспекты");
    QPushButton *pbOpen = new QPushButton("Открыть");
    QPushButton *pbCancel = new QPushButton("Отмена");
    QVector<WorkbookInfo> info = WorkbookInfoDao::getWorkbookInfoAll();
public:
    ConspectusChooser(QWidget *parent = 0);
protected slots:
    void open_pressed();
    void cancel_pressed();
};

#endif // CONSPECTUSCHOOSER_H
