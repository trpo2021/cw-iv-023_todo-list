#pragma once
#include <climits>
#include <iostream>
#include <string>
#include <vector>

class Task {
private:
    std::string date;
    std::string text;
    int priority; //Приоритет задачи от 1 до 5
public:
    // Конструктор:
    Task(std::string date, std::string text, int priority);
    Task();
    // Установить дату:
    void setDate(std::string newDate);
    // Установить текст:
    void setText(std::string newText);
    // Установить приоритет:
    void setPriority(int newPriority);
    // Вернуть значение даты:
    std::string getDate() const;
    // Вернуть значение текста:
    std::string getText() const;
    // Вернуть значение приоритета:
    int getPriority() const;
    bool operator==(const Task& b);
    bool operator!=(const Task& b);
};

int findIndex(std::vector<Task>& taskVector, std::string date, int priority, std::string text);
int deleteTaskFromVector(std::vector<Task>& vector, std::string date, int priority, std::string text);
// добавление заметки:
void setTaskForDate(std::vector<Task>& taskVector, std::string newDate, int newPriority, std::string newText);
// вывод заметок на данную дату в консоль(временно):
void getTaskForDate(std::vector<Task> taskVector, std::string date);
// изменение даты:
int changeTaskDate(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newDate);
// изменение текста заметки:
int changeTaskText(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newText);
// изменение приоритета заметки:
int changeTaskPriority(std::vector<Task>& taskVector, std::string date, int priority, std::string text, int newPriority);
