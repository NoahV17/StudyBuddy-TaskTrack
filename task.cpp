// SelfOrganizingList is implemented within these methods to access the list,
// while ading a task it will search and find the correct spot for the insertion of the task.

#include "task.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Task::Task(std::string dueDate, std::string& classStr, std::string& title, int priority){
    this->dueDate = dueDate;
    this->classStr = classStr;
    this->title = title;
    this->priority = priority;
}

void addTask(Task task, std::vector<Task>& tasks, int& taskCounter) {
    
    tasks.push_back(task);
    taskCounter++;
    std::cout << "Added -> " << task.getClass() << " " << task.getTitle() << ", which is due on " << task.print_due_date() << std::endl;
    // Make a new function, and call it , to output the new vector to the file, and save the file.
}

void removeTask(std::vector<Task>& tasks, int index) {
    tasks.erase(tasks.begin() + index - 1);
}

std::string Task::getDueDate() {
    std::ostringstream oss;
    oss << std::setw(6) << std::setfill('0') << dueDate;
    return oss.str();
}

int Task::getDueDateInt() {
    return std::stoi(dueDate);
}

std::string Task::print_due_date() {
    //Parse due date int to mm/dd/yy
    std::string str;
    str += std::to_string(stoi(dueDate) / 10000) + "/" + std::to_string(stoi(dueDate) / 100 % 100) + "/" + std::to_string(stoi(dueDate) % 100);
    return str;
}

std::string& Task::getTitle() {
    return title;
}

int Task::getPriority() {
    return priority;
}

std::string& Task::getClass() {
    return classStr;
}

void toString(std::vector<Task> tasks) {
    int counter = 0;
    std::cout << "The following is a list of all stored tasks..." << std::endl;
    for (Task& task : tasks) {
        counter++;
        std::cout << counter << ". " << task.getClass() << " " << task.getTitle() << " Priority: " << task.getPriority() << ", Due on " << task.print_due_date() << std::endl;
    }
}

void toFile(std::vector<Task> tasks, bool temp) {
    std::ofstream file;
    if (temp) {
        file.open("temp.txt");
    } else {
        file.open("tasks.txt");
    }

    for (Task& task : tasks) {
        file << task.getDueDate() << "," << task.getClass() << "," << task.getTitle() << "," << task.getPriority() << std::endl;
    }

    file.close();
}