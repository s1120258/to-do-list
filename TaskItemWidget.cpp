#include "TaskItemWidget.h"
#include <QHBoxLayout>
#include <QPalette>

TaskItemWidget::TaskItemWidget(const QString& task, bool completed, QWidget* parent)
	: QWidget(parent)
{
	QHBoxLayout* layout = new QHBoxLayout(this);

	QLabel* taskLabel = new QLabel(task, this);
	if (completed) {
		QPalette palette = taskLabel->palette();
		palette.setColor(QPalette::WindowText, Qt::gray);
		taskLabel->setPalette(palette);
		QFont font = taskLabel->font();
		font.setStrikeOut(true);
		taskLabel->setFont(font);
	}
	layout->addWidget(taskLabel);

	QPushButton* completeButton = new QPushButton("Complete", this);
	if (completed) {
		completeButton->setEnabled(false);
	}
	layout->addWidget(completeButton);

	QPushButton* removeButton = new QPushButton("Remove", this);
	layout->addWidget(removeButton);

	connect(completeButton, &QPushButton::clicked, this, &TaskItemWidget::completeTask);
	connect(removeButton, &QPushButton::clicked, this, &TaskItemWidget::removeTask);

	setLayout(layout);
}
