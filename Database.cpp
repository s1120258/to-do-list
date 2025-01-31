#include "Database.h"

QSqlDatabase db;

bool Database::connect()
{
	if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
		qDebug() << "SQLite driver is not available";
		return false;
	}

	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("tasks.db");

	if (!db.open()) {
		qDebug() << "Failed to open database";
		return false;
	}

	// Create table if not exists
	QSqlQuery query;
	query.exec("CREATE TABLE IF NOT EXISTS tasks ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"task TEXT NOT NULL, "
		"completed INTEGER DEFAULT 0)");

	return true;
}

bool Database::addTask(const QString& task)
{
	QSqlQuery query;
	query.prepare("INSERT INTO tasks (task, completed) VALUES (:task, 0)");
	query.bindValue(":task", task);
	return query.exec();
}

bool Database::markTaskCompleted(int id)
{
	QSqlQuery query;
	query.prepare("UPDATE tasks SET completed = 1 WHERE id = :id");
	query.bindValue(":id", id);
	return query.exec();
}

bool Database::removeTask(int id)
{
	QSqlQuery query;
	query.prepare("DELETE FROM tasks WHERE id = :id");
	query.bindValue(":id", id);
	return query.exec();
}

QSqlQuery Database::getTasks()
{
	QSqlQuery query;
	query.exec("SELECT * FROM tasks");
	return query;
}
