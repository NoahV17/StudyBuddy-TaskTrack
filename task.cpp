// SelfOrganizingList is implemented within these methods to access the list,
// while ading a task it will search and find the correct spot for the insertion of the task.

#include "task.h"
#include <string>
#include <vector>
#include <iostream>

Task::Task(int dueDate, std::string& title, int priority){
    this->dueDate = dueDate;
    this->title = title;
    this->priority = priority;
}

void addTask(Task task, std::vector<Task>& tasks, int& taskCounter) {
    tasks.push_back(task);
    taskCounter++;
    std::cout << "Added -> " << task.getTitle() << ", which is due on " << task.print_due_date() << std::endl;
    // Make a new function, and call it , to output the new vector to the file, and save the file.
}

int Task::getDueDate() {
    return dueDate;
}

std::string Task::print_due_date() {
    //Parse due date int
    std::string str;
    str += std::to_string(dueDate / 10000) + "/" + std::to_string(dueDate / 100 % 100) + "/" + std::to_string(dueDate % 100);
    return str;
}

std::string& Task::getTitle() {
    return title;
}

int Task::getPriority() {
    return priority;
}

void toString(std::vector<Task> tasks) {
    int counter = 0;
    std::cout << "The following is a list of all stored tasks..." << std::endl;
    for (Task& task : tasks) {
        counter++;
        std::cout << counter << ". " << task.print_due_date() << " " << task.getTitle() << " " << task.getPriority() << std::endl;
    }
}