#pragma once

#include <QMainWindow>
#include "ui_ToDoList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ToDoListClass; }
QT_END_NAMESPACE

class ToDoList : public QMainWindow
{
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr);
    ~ToDoList();

private slots:
    void addTask();
    void markTaskCompleted();
    void removeTask();
    void exitApplication();

private:
    Ui::ToDoListClass* ui;

    void loadTasks();
};
