#include "ToDoList.h"
#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    if (QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qDebug() << "SQLite driver is available";

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("todo.db");
        if (!db.open()) {
            qDebug() << "Failed to open database:" << db.lastError().text();
            return 1;
        }
    }
    else {
        qDebug() << "SQLite driver is not available";
        return 1;
    }

    ToDoList w;
    w.show();
    return a.exec();
}