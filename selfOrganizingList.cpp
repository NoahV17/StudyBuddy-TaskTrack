#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include "SelfOrganizingList.h"

//make a self organizing list file that will read from a file formatted task-name, duedate, priority and overwrite the file when the add function is called with the new order of tasks in order of nearest due date to furthest

SelfOrganizingList::SelfOrganizingList() {
    std::ifstream file(filename);
    std::string dueDate, title;
    int priority;

    //Fills the list
    while (std::getline(file, title, ',') && file >> dueDate >> priority) {
        Task new_task(dueDate, title, priority);
        addTask(new_task);
    }

    // Sort tasks by due date
    std::sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        return a.getDueDate() < b.getDueDate();
    });
}

void addTask(Task& task) {
    tasks.push_back(task);

    // Sort tasks by due date
    std::sort(tasks.begin(), tasks.end(), [](Task& a, Task& b) {
        return a.getDueDate() < b.getDueDate();
    });

    writeToFile();
}

void writeToFile() {
    std::string filename = "tasks.txt";
    std::ofstream file(filename);

    for (Task& task : tasks) {
        file << task.getTitle() << ',' << task.getDueDate() << ' ' << task.getPriority() << '\n';
    }
}