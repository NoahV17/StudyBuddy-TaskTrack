#include <vector>
#include <algorithm>
#include <iostream>
#include "binarySearch.h"

// void nearestDueDate() {
    
// }

// Create function that prints all tasks with the passed in priority,
// POSSIBLY make temp.txt that will hold a portion of the whole list of tasks.
void printPriority(std::vector<Task>& tasks, int priority) {
    std::cout << "The following are of priority level " << priority << std::endl; 
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getPriority() == priority) {
            std::cout << tasks[i].getTitle() << " is due on " << tasks[i].getDueDate() << std::endl;
        }
    }
}