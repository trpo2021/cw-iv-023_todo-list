#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string date;
    string text;
    int priority; //Приоритет задачи от 1 до 5
public:
    // Конструктор:
    Task(string date, string text, int priority);
    Task();
    // Установить дату:
    void SetDate(string newDate);
    // Установить текст:
    void SetText(string newText);
    // Установить приоритет:
    void SetPriority(int newPriority);
    // Вернуть значение даты:
    string GetDate() const;
    // Вернуть значение текста:
    string GetText() const;
    // Вернуть значение приоритета:
    int GetPriority() const;
    bool operator==(const Node& b);
    bool operator!=(const Node& b);
};

void DeleteTask(vector<Task>& vector, string date, int priority, string text);
// добавление заметки:
void SetTaskForDate(vector<Task>& taskVector, string newDate, int newPriority, string newText);
// вывод заметок на данную дату в консоль(временно):
void GetTaskForDate(vector<Task> taskVector, string date);
// изменение даты:
void ChangeTaskDate(vector<Task>& taskVector, string date, int priority, string text, string newDate);
// изменение текста заметки:
void ChangeTaskText(vector<Task>& taskVector, string date, int priority, string text, string newText);
// изменение приоритета заметки:
void ChangeTaskPriority(vector<Task>& taskVector, string date, int priority, string text, int newPriority);
