#include "workbookdao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

const QString WorkbookDao::WORKBOOK_BY_TABLE = "SELECT * FROM %1";
QSharedPointer<Workbook> WorkbookDao::workbook;

void WorkbookDao::setWorkbookByWorkbookInfo(const WorkbookInfo &info)
{
    QSqlQuery qry(QSqlDatabase::database());
    qry.exec(WORKBOOK_BY_TABLE.arg(info.getTableName()));
    workbook = QSharedPointer<Workbook>(new Workbook);
    QSqlRecord record = qry.record();
    int idCol = record.indexOf("id");
    int questionCol = record.indexOf("question");
    int answerCol = record.indexOf("answer");
    QVector<Question> &questions = workbook->getQuestions();
    while(qry.next())
        questions.append(Question(qry.value(questionCol).toString(), qry.value(answerCol).toString()));
    workbook->setInfo(info);
}

QSharedPointer<Workbook> WorkbookDao::getWorkbook()
{
    return workbook;
}
