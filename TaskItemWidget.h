#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class TaskItemWidget : public QWidget
{
    Q_OBJECT

public:
    TaskItemWidget(const QString& task, bool completed, QWidget* parent = nullptr);

signals:
    void completeTask();
    void removeTask();

private:
    QLabel* taskLabel;
    QPushButton* completeButton;
    QPushButton* removeButton;
};

