#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ToDoList.h"

class ToDoList : public QMainWindow
{
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr);
    ~ToDoList();

private:
    Ui::ToDoListClass ui;
};
