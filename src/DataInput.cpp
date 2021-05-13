#include "DataInput.h"
#include "Node.h"

void SetTaskInFile(vector<Node>& node_vector, string date, int priority, string text)
{
    fstream Task;
    Task.open("task.txt", ios::app);

    Task << date << " " << priority << " " << text << endl;
    SetTaskForDate(node_vector, date, priority, text);
    cout << "Заметка добавлена" << endl;
    Task.close();
}

void ChangeStringInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string new_string, int TypeString)
{
    int readchar  = 0;
    int charcount = 0;
    string date;
    string prior;
    string text;
    int priority;
    fstream Cache;
    fstream Task;

    Task.open("task.txt", ios::in);
    Cache.open("cache.txt", ios::out);

    while ((readchar = Task.get()) != EOF) {
        if (char(readchar) != '\n') {
            if (charcount < 10) {
                date = date + char(readchar);
                charcount++;
            } else {
                if (charcount < 13) {
                    if (char(readchar) != ' ') {
                        prior = prior + char(readchar);
                        priority = stoi(prior);
                    }
                    charcount++;
                } else {
                    text = text + char(readchar);
                }
            }
        } else {
            if ((date == date_p) && (priority == priority_p) && (text == text_p)) {
                if (TypeString == 1) {
                    ChangeTaskDate(node_vector, date_p, priority_p, text_p, new_string);
                    Cache << new_string << " " << priority_p << " " << text_p << endl;
                }
                if (TypeString == 2) {
                    ChangeTaskText(node_vector, date_p, priority_p, text_p, new_string);
                    Cache << date_p << " " << priority_p << " " << new_string << endl;
                }
                if (TypeString == 3) {
                    int newPriority = stoi(new_string);
                    ChangeTaskPriority(node_vector, date_p, priority_p, text_p, newPriority);
                    Cache << date_p << " " << newPriority << " " << text_p << endl;
                }
                if (TypeString == 4) {
                    DeleteTask(node_vector, date_p, priority_p, text_p);
                }

            } else {
                Cache << date << " " << priority << " " << text << endl;
                if (TypeString == 0) {
                    SetTaskForDate(node_vector, date, priority, text);
                }
            }
            charcount = 0;
            date.clear();
            prior.clear();
            text.clear();
        }
    }

    Task.close();
    Cache.close();

    Cache.open("cache.txt", ios::in);
    Task.open("task.txt", ios::out);

    while ((readchar = Cache.get()) != EOF) {
        if (char(readchar) != '\n') {
            if (charcount < 10) {
                date = date + char(readchar);
                charcount++;
            } else {
                if (charcount < 13) {
                    if (char(readchar) != ' ') {
                        prior = prior + char(readchar);
                        priority = stoi(prior);
                    }
                    charcount++;
                } else {
                    text = text + char(readchar);
                }
            }
        } else {
            Task << date << " " << priority << " " << text << endl;
            charcount = 0;
            date.clear();
            prior.clear();
            text.clear();
        }
    }

    Task.close();
    Cache.close();
}

void UpdateTask(vector<Node>& node_vector){
    int TypeString = 0;
    ChangeStringInFile(node_vector, "", 0, "", "", TypeString);
}

void ChangeDateInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string newDate)
{
    int TypeString = 1;
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, newDate, TypeString);
}
void ChangeTextInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string newText)
{
    int TypeString = 2;
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, newText, TypeString);
}
void ChangePriorityInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, int newPriority)
{
    int TypeString = 3;
    string prior = to_string(newPriority);
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, prior, TypeString);
}
void DeleteTaskInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p)
{
    int TypeString = 4;
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, "", TypeString);
}
