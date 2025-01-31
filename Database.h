#pragma once

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

class Database {
public:
    static bool connect();
    static bool addTask(const QString& task);
    static bool markTaskCompleted(int id);
    static bool removeTask(int id);
    static QSqlQuery getTasks();
};
