#pragma once

#include <QDialog>

class QComboBox;
class QLineEdit;
class QFormLayout;
class Task;

class TaskInputDialog : public QDialog {
    Q_OBJECT
public:
    TaskInputDialog(QWidget* parent = nullptr);
    void setTaskData(const Task& taskInfo);

signals:
    void taskInfoSended(const Task&);

public slots:
    void sendTaskData();

private:
    QLineEdit* taskLineEdit = nullptr;
    QLineEdit* dateLineEdit = nullptr;
    QComboBox* priorityComboBox = nullptr;
};
