#pragma once
#include "Task.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void UpdateTask(vector<Task>& taskVector);
void SetTaskInFile(vector<Task>& taskVector, string date, int priority, string text);
void ChangePriorityInFile(vector<Task>& taskVector, string date, int priority, string text, int newPriority);
void ChangeStringInFile(vector<Task>& taskVector, string date_p, int priority_p, string text_p, string new_string, int TypeString);
void ChangeDateInFile(vector<Task>& taskVector, string date_p, int priority_p, string text_p, string newDate);
void ChangeTextInFile(vector<Task>& taskVector, string date_p, int priority_p, string text_p, string newText);
void DeleteTaskInFile(vector<Task>& taskVector, string date_p, int priority_p, string text_p);
