#include <vector>
#include <algorithm>
#include <iostream>
#include "ternarySearch.h"

// Function that prints all tasks with the passed in priority,
void printPriority(std::vector<Task>& tasks, int priority) {
    std::cout << "The following are of priority level " << priority << std::endl; 
    for (int i = 0; i < tasks.size(); i++) {
        int num_with_priority = 0;
        if (tasks[i].getPriority() == priority) {
            num_with_priority++;
            std::cout << num_with_priority << ". " << tasks[i].getTitle() << ": due on " << tasks[i].getDueDate() << std::endl;
        }
    }
}

//Make sure its sorted before hand
void printTasksInMonth(std::vector<Task>& tasks, int month, int year) {
    int left = 0, right = tasks.size() - 1;
    int target = month * 10000 + year; // Convert target month and year to mmyy format

    // Ternary search to find the first task in the target month and year
    while (right - left > 2) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (tasks[mid1].getDueDate() < target) {
            left = mid1 + 1;
        } else if (tasks[mid2].getDueDate() > target) {
            right = mid2 - 1;
        } else {
            left = mid1;
            right = mid2;
        }
    }

    // If the first task in the target month and year is found, print all tasks in that month and year
    for (int i = left; i <= right; i++) {
        if (tasks[i].getDueDate() / 10000 == month && tasks[i].getDueDate() % 10000 == year) {
            for (int j = i; j < tasks.size() && tasks[j].getDueDate() / 10000 == month && tasks[j].getDueDate() % 10000 == year; j++) {
                std::cout << tasks[j].getTitle() << " is due on " << tasks[j].getDueDate() << std::endl;
            }
            return;
        }
    }
    std::cout << "No tasks due in " << month << "/" << year << std::endl;
}