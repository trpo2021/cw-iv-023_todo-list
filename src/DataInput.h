#pragma once
#include "Task.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

enum operation { Read, Edit, Delete, Add };

void changeStringInFile(std::vector<Task>& taskVector, size_t index, operation type);
