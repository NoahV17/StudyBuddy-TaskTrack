#include <vector>
#include <algorithm>
#include <iostream>
#include "Task.h"
// Global list of tasks, sorted by priority
std::vector<Task> tasks;

void nearestDueDate() {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
        return;
    }

    int highestPriority = tasks[0].getPriority();

    // Use binary search to find the first task with the highest priority
    auto it = std::lower_bound(tasks.begin(), tasks.end(), highestPriority, [](const Task& task, int priority) {
        return task.getPriority() > priority;
    });

    // Print all tasks with the highest priority
    for (; it != tasks.end() && it->getPriority() == highestPriority; ++it) {
        std::cout << it->getTitle() << " is due on " << it->getDueDate() << " with priority " << it->getPriority() << std::endl;
    }
}