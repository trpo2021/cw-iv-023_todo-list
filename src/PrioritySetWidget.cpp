#include "PrioritySetWidget.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

const int countButton = 5;

PrioritySetWidget::PrioritySetWidget(QWidget* parent) : QWidget(parent)
{
    QLabel* priorityLabel = new QLabel("Priority:", this);

    QVBoxLayout* vBox = new QVBoxLayout(this);
    vBox->addWidget(priorityLabel);

    for (int i = 0; i < countButton; i++) {
        QPushButton* priorityButton = new QPushButton(QString::number(i + 1), this);
        priorityMap.insert(priorityButton, i + 1);
        connect(priorityButton, SIGNAL(clicked()), this, SLOT(sendPriority()));
        vBox->addWidget(priorityButton);
    }

    QPushButton* priorityButton = new QPushButton("Show all", this);
    priorityMap.insert(priorityButton, 6);
    connect(priorityButton, SIGNAL(clicked()), this, SLOT(sendPriority()));
    vBox->addWidget(priorityButton);
}

void PrioritySetWidget::sendPriority()
{
    QPushButton* sendButton = qobject_cast<QPushButton*>(sender());

    emit priorityChangeRequested(priorityMap.value(sendButton, 1));
}
