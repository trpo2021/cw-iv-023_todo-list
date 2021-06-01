#include "TodoListWidget.h"
#include "DataInput.h"
#include "ListItemWidget.h"
#include "Task.h"
#include "TaskInputWindow.h"

#include <QDebug>
#include <QListWidget>
#include <QVBoxLayout>
#include <QVariant>
#include <vector>

enum TaskRoles {
    TaskText = Qt::UserRole + 1,
    TaskDate = Qt::UserRole + 2,
    TaskPriority = Qt::UserRole + 3,
    TaskStatus = Qt::UserRole + 4
};

ToDoListWidget::ToDoListWidget(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* vBox = new QVBoxLayout(this);
    tasksListWidget = new QListWidget(this);

    vBox->addWidget(tasksListWidget);

    changeStringInFile(tasksStorage, 0, Read);

    for (int i = 0; i < tasksStorage.size(); i++) {
        QListWidgetItem* taskItem = new QListWidgetItem(tasksListWidget);
        tasksListWidget->addItem(taskItem);
        QString taskText = QString::fromStdString(tasksStorage[i].getText());
        QString dateText = QString::fromStdString(tasksStorage[i].getDate());

        taskItem->setData(TaskText, taskText);
        taskItem->setData(TaskDate, dateText);
        taskItem->setData(TaskPriority, tasksStorage[i].getPriority());
        taskItem->setData(TaskStatus, false);

        ListItemWidget* listItemWidget = new ListItemWidget(taskText, dateText, tasksListWidget);
        taskItem->setSizeHint(listItemWidget->sizeHint());
        tasksListWidget->setItemWidget(taskItem, listItemWidget);
    }
    qDebug() << "Create task" << tasksStorage.size();
}

void ToDoListWidget::createTask()
{
    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Task&)), this, SLOT(addedTask(const Task&)));
    inputDialog->open();
}

void ToDoListWidget::editTask()
{
    if (!tasksListWidget->currentItem() || tasksListWidget->currentItem()->data(TaskStatus) == true) {
        return;
    }

    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Task&)), this, SLOT(editingTask(const Task&)));

    QString taskText = tasksListWidget->currentItem()->data(TaskText).toString();
    QString taskDate = tasksListWidget->currentItem()->data(TaskDate).toString();
    int taskPriority = tasksListWidget->currentItem()->data(TaskPriority).toInt();
    Task editableTask(taskDate.toStdString(), taskText.toStdString(), taskPriority);

    inputDialog->setTaskData(editableTask);

    qDebug() << "Edit task";

    inputDialog->open();
}

void ToDoListWidget::editingTask(const Task& node)
{
    QString taskText = QString::fromStdString(node.getText());
    QString dateText = QString::fromStdString(node.getDate());
    int priority = node.getPriority();

    auto taskItem = tasksListWidget->currentItem();

    QVariant task[3] = {taskItem->data(TaskText), taskItem->data(TaskDate), taskItem->data(TaskPriority)};
    QString oldTaskText = task[0].toString();
    QString oldTaskDate = task[1].toString();
    int oldTaskPriority = task[2].toInt();

    Task editableTask(oldTaskDate.toStdString(), oldTaskText.toStdString(), oldTaskPriority);

    int editableTaskIndex = findIndex(tasksStorage, oldTaskDate.toStdString(), oldTaskPriority, oldTaskText.toStdString());

    changeTaskDate(tasksStorage, oldTaskDate.toStdString(), oldTaskPriority, oldTaskText.toStdString(), dateText.toStdString());
    changeTaskText(tasksStorage, dateText.toStdString(), oldTaskPriority, oldTaskText.toStdString(), taskText.toStdString());
    changeTaskPriority(tasksStorage, dateText.toStdString(), oldTaskPriority, taskText.toStdString(), priority);

    changeStringInFile(tasksStorage, editableTaskIndex, Edit);

    taskItem->setData(TaskText, taskText);
    taskItem->setData(TaskDate, dateText);
    taskItem->setData(TaskPriority, priority);

    tasksListWidget->removeItemWidget(tasksListWidget->currentItem());
    tasksListWidget->setItemWidget(taskItem, new ListItemWidget(taskText, dateText, tasksListWidget));
}

void ToDoListWidget::compliteTask()
{
    if (tasksListWidget->currentItem() == nullptr || tasksListWidget->currentItem()->data(TaskStatus) == true) {
        return;
    }

    qDebug() << "complite task";
    tasksListWidget->currentItem()->setBackgroundColor(QColor(0, 250, 0));

    auto taskItem = tasksListWidget->currentItem();
    taskItem->setData(TaskStatus, true);
    QVariant task[3] = {taskItem->data(TaskText), taskItem->data(TaskDate), taskItem->data(TaskPriority)};
    QString taskText = task[0].toString();
    QString taskDate = task[1].toString();
    int taskPriority = task[2].toInt();
    Task complitedTask(taskDate.toStdString(), taskText.toStdString(), taskPriority);

    changeStringInFile(tasksStorage, findIndex(tasksStorage, taskDate.toStdString(), taskPriority, taskText.toStdString()), Delete);
    deleteTaskFromVector(tasksStorage, taskDate.toStdString(), taskPriority, taskText.toStdString());
}

void ToDoListWidget::deleteTask()
{
    if (tasksListWidget->currentItem() == nullptr) {
        return;
    }

    auto taskItem = tasksListWidget->currentItem();

    if (taskItem->data(TaskStatus) == true) {
        tasksListWidget->removeItemWidget(tasksListWidget->currentItem());
        delete tasksListWidget->takeItem(tasksListWidget->currentRow());
        return;
    }

    taskItem->setData(TaskStatus, true);
    QVariant task[3] = {taskItem->data(TaskText), taskItem->data(TaskDate), taskItem->data(TaskPriority)};
    QString taskText = task[0].toString();
    QString taskDate = task[1].toString();
    int taskPriority = task[2].toInt();

    changeStringInFile(tasksStorage, findIndex(tasksStorage, taskDate.toStdString(), taskPriority, taskText.toStdString()), Delete);
    deleteTaskFromVector(tasksStorage, taskDate.toStdString(), taskPriority, taskText.toStdString());

    tasksListWidget->removeItemWidget(tasksListWidget->currentItem());
    delete tasksListWidget->takeItem(tasksListWidget->currentRow());

    qDebug() << "Delete task";
}

void ToDoListWidget::setTaskPriority(int priority)
{
    for (int i = 0; i < tasksListWidget->count(); i++) {
        auto item = tasksListWidget->item(i);
        if (item->data(TaskPriority) != priority) {
            item->setHidden(true);
        } else {
            item->setHidden(false);
        }

        if (priority == 6) {
            item->setHidden(false);
        }
    }

    qDebug() << "Set priority:" << priority;
}

void ToDoListWidget::addedTask(const Task& newTask)
{
    inputDialog = new TaskInputDialog(this);
    connect(inputDialog, SIGNAL(taskInfoSended(const Task&)), this, SLOT(addedTask(const Task&)));

    QListWidgetItem* taskItem = new QListWidgetItem(tasksListWidget);
    tasksListWidget->addItem(taskItem);
    QString taskText = QString::fromStdString(newTask.getText());
    QString dateText = QString::fromStdString(newTask.getDate());

    taskItem->setData(TaskText, taskText);
    taskItem->setData(TaskDate, dateText);
    taskItem->setData(TaskPriority, newTask.getPriority());
    taskItem->setData(TaskStatus, false);

    ListItemWidget* listItemWidget = new ListItemWidget(taskText, dateText, tasksListWidget);
    taskItem->setSizeHint(listItemWidget->sizeHint());
    tasksListWidget->setItemWidget(taskItem, listItemWidget);
    tasksStorage.push_back(newTask);
    changeStringInFile(tasksStorage, tasksStorage.size() - 1, Add);
}
