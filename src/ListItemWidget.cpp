#include "ListItemWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QTextEdit>

ListItemWidget::ListItemWidget(QString text, QString date, QWidget* parent) : QWidget(parent)
{
    QTextEdit* taskTextEdit = new QTextEdit(text, this);
    taskTextEdit->setReadOnly(true);
    QLabel* dateLabel = new QLabel(date, this);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(taskTextEdit, 3);
    mainLayout->addWidget(dateLabel, 1);

    setLayout(mainLayout);
}
