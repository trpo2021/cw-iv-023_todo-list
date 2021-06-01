#pragma once
#include "Task.h"

#include <QWidget>
#include <vector>

class QListWidget;
class TaskInputDialog;
class Task;

class ToDoListWidget : public QWidget {
    Q_OBJECT
public:
    ToDoListWidget(QWidget* parent = nullptr);

public slots:
    void createTask();
    void editTask();
    void deleteTask();
    void compliteTask();
    void setTaskPriority(int);

private slots:
    void addedTask(const Task&);
    void editingTask(const Task&);

private:
    QListWidget* tasksListWidget;
    TaskInputDialog* inputDialog;
    std::vector<Task> tasksStorage;
};
