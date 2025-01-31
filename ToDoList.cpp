#include "ToDoList.h"
#include "TaskItemWidget.h"
#include "Database.h"
#include <QListWidget>
#include <QPushButton>
#include <QFont>

ToDoList::ToDoList(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::ToDoListClass)
{
    ui->setupUi(this);

	Database::connect();
	loadTasks();

	connect(ui->addButton, &QPushButton::clicked, this, &ToDoList::addTask);
	connect(ui->exitButton, &QPushButton::clicked, this, &ToDoList::exitApplication);
}

ToDoList::~ToDoList()
{
	delete ui;
}

void ToDoList::loadTasks()
{
	ui->taskList->clear();
	QSqlQuery query = Database::getTasks();

	while (query.next()) {
		int id = query.value("id").toInt();
		QString task = query.value("task").toString();
		bool completed = query.value("completed").toBool();

		QListWidgetItem* item = new QListWidgetItem(task, ui->taskList);
		TaskItemWidget* taskWidget = new TaskItemWidget(task, completed);

		connect(taskWidget, &TaskItemWidget::completeTask, [this, id]() {
			if (Database::markTaskCompleted(id)) {
				loadTasks();
			}
		});

		connect(taskWidget, &TaskItemWidget::removeTask, [this, id]() {
			if (Database::removeTask(id)) {
				loadTasks();
			}
		});

		item->setSizeHint(taskWidget->sizeHint());
		ui->taskList->setItemWidget(item, taskWidget);
	}
}

void ToDoList::addTask()
{
	QString task = ui->taskInput->text();
	if (task.isEmpty()) return;

	if (Database::addTask(task)) {
		loadTasks();
		ui->taskInput->clear();
	}
}

void ToDoList::markTaskCompleted()
{
	QListWidgetItem* item = ui->taskList->currentItem();
	if (!item) return;

	int id = item->data(Qt::UserRole).toInt();
	if (Database::markTaskCompleted(id)) {
		loadTasks();
	}
}

void ToDoList::removeTask()
{
	QListWidgetItem* item = ui->taskList->currentItem();
	if (!item) return;

	int id = item->data(Qt::UserRole).toInt();
	if (Database::removeTask(id)) {
		loadTasks();
	}
}

void ToDoList::exitApplication()
{
	QApplication::quit();
}
