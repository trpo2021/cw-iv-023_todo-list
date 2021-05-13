#include "Task.h"

Task::Task(string newDate, string newText, int newPriority)
{
    date = newDate;
    text = newText;
    priority = newPriority;
}

Task::Task()
{
	date = "";
	text = "";
	priority = 0;
}

bool Task::operator == (const Task &b){
	if(this->date == b.date && this->text == b.text && this->priority == b.priority){
		return true;
	}else{
		return false;
	}
}

bool Task::operator != (const Task &b){
	if(this->date == b.date && this->text == b.text && this->priority == b.priority){
		return false;
	}else{
		return true;
	}
}	

void SetTaskForDate(vector<Task>& taskVector, string newDate, int newPriority, string newText)
{
    Task task(newDate, newText, newPriority);
    taskVector.push_back(task);
}

void GetTaskForDate(vector<Task> taskVector, string date)
{
    vector<Task> helpVector;
    for (int i = 0; i < taskVector.size(); i++) {
        if (taskVector[i].GetDate() == date) {
            helpVector.push_back(taskVector[i]);
        }
    }
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < helpVector.size(); j++) {
            if (helpVector[j].GetPriority() == i) {
                cout << helpVector[j].GetDate() << " " << helpVector[j].GetPriority() << " " << helpVector[j].GetText() << endl;
            }
        }
    }
    helpVector.clear();
}

void DeleteTask(vector<Task>& vector, string date, int priority, string text)
{
    for (int i = 0; i < vector.size(); i++) {
        if ((vector[i].GetDate() == date) && (vector[i].GetText() == text) && (vector[i].GetPriority() == priority)) {
            vector.erase(vector.begin() + i);
            break;
        }
    }
}

void Task::SetDate(string newDate)
{
    date = newDate;
}
void Task::SetText(string newText)
{
    text = newText;
}
void Task::SetPriority(int newPriority)
{
    priority = newPriority;
}

string Task::GetDate()const
{
    return date;
}
string Task::GetText()const
{
    return text;
}
int Task::GetPriority()const
{
    return priority;
}

int FindIndex(vector<Task>& taskVector, string date, int priority, string text){
	for (int i = 0; i < taskVector.size(); i++) {
        if ((taskVector[i].GetDate() == date) && (taskVector[i].GetText() == text) && (taskVector[i].GetPriority() == priority)) {
            return i;
        }
    }
    return 1;
}

void ChangeTaskDate(vector<Task>& taskVector, string date, int priority, string text, string newDate)
{
	int number = FindIndex(taskVector,date,priority,text);
    taskVector[number].SetDate(newDate);
}

void ChangeTaskText(vector<Task>& taskVector, string date, int priority, string text, string newText)
{
    int number = FindIndex(taskVector,date,priority,text);
    taskVector[number].SetText(newText);
}

void ChangeTaskPriority(vector<Task>& taskVector, string date, int priority, string text, int newPriority)
{
    int number = FindIndex(taskVector,date,priority,text);
    taskVector[number].SetPriority(newPriority);
}

