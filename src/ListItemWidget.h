#pragma once

#include <QWidget>

class QString;

class ListItemWidget : public QWidget {
    Q_OBJECT
public:
    ListItemWidget(QString text, QString date, QWidget* parent = nullptr);
};
