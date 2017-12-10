#ifndef HINTSBROWSER_H
#define HINTSBROWSER_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>

class HintsBrowser : public QWidget
{
    Q_OBJECT
    QLabel *lblHints = new QLabel("Подсказки");
    QListWidget *listWidget = new QListWidget;
    QLineEdit *lineEdit = new QLineEdit;
    QPushButton *btnAddHint = new QPushButton("Добавить подсказку");
    QVector<QString> *hints;
public:
    HintsBrowser();
    void setHints(QVector<QString> *hints);
protected slots:
    void addHint();
};

#endif // HINTSBROWSER_H
