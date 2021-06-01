#pragma once

#include <QWidget>

class ControlWidget : public QWidget {
    Q_OBJECT

public:
    ControlWidget(QWidget* parent = nullptr);

signals:
    void createTaskRequested();
    void deleteTaskRequested();
    void compliteTaskRequested();
    void editTaskRequested();
};
