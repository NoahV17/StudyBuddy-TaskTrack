#include <vector>
#include <algorithm>
#include <iostream>
#include "Task.h"

void nearestDueDate() {
    
}

// Create function that prints all tasks with the passed in priority,
// POSSIBLY make temp.txt that will hold a portion of the whole list of tasks.
void printPriority(std::vector<Task>& tasks, int priority) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getPriority() == priority) {
            std::cout << tasks[i].getDueDate() << " " << tasks[i].getTitle() << " " << tasks[i].getPriority() << std::endl;
        }
    }
}