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
// This is for unsorted, PLAN TO IMPLEMENT REAL BINSEARCH AND BEFORE PERFORMING, COMBSORT
// could also pass in a bool saying if it is sorted or not in a certian way

//void printTasksInMonth(std::vector<Task>& tasks, int month, int year) {
//     for (int i = 0; i < tasks.size(); i++) {
//         int dueDate = tasks[i].getDueDate();
//         int dueMonth = dueDate / 10000;
//         int dueYear = dueDate % 10000;

//         if (dueMonth == month && dueYear == year) {
//             std::cout << tasks[i].getTitle() << " is due on " << dueDate << std::endl;
//         }
//     }
// }