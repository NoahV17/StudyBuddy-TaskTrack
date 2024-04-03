#include <fstream>
#include <algorithm>
#include "SelfOrganizingList.h"

//make a self organizing list file that will read from a file formatted task-name, duedate, priority and overwrite the file when the add function is called with the new order of tasks in order of nearest due date to furthest

SelfOrganizingList::SelfOrganizingList(const std::string& filename)
    : filename(filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open tasks file.");
    }

    std::string dueDate, title;
    int priority;
    while (std::getline(file, title, ',') && file >> dueDate >> priority) {
        tasks.push_back(Task(dueDate, title, priority));
    }

    // Sort tasks by due date
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getDueDate() < b.getDueDate();
    });
}

void SelfOrganizingList::addTask(const Task& task) {
    tasks.push_back(task);

    // Sort tasks by due date
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.getDueDate() < b.getDueDate();
    });

    writeToFile();
}

void SelfOrganizingList::writeToFile() {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open tasks file.");
    }

    for (const Task& task : tasks) {
        file << task.getTitle() << ',' << task.getDueDate() << ' ' << task.getPriority() << '\n';
    }
}