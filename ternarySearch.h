#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include "task.h"

void printPriority(std::vector<Task>& tasks, int priority);
void printTasksInMonth(std::vector<Task>& tasks, int month, int year);
std::vector<Task> onDay(std::vector<Task> tasks, std::string date);
#endif // BINARY_SEARCH_H