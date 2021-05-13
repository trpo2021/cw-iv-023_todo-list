#pragma once
#include "Node.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void UpdateTask(vector<Node>& node_vector);
void SetTaskInFile(vector<Node>& node_vector, string date, int priority, string text);
void ChangePriorityInFile(vector<Node>& node_vector, string date, int priority, string text, int newPriority);
void ChangeStringInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string new_string, int TypeString);
void ChangeDateInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string newDate);
void ChangeTextInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string newText);
void DeleteTaskInFile(vector<Node>& vector, string date_p, int priority_p, string text_p);

