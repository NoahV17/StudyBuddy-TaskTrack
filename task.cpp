// SelfOrganizingList is implemented within these methods to access the list,
// while ading a task it will search and find the correct spot for the insertion of the task.

#include "task.h"
#include <string>

Task::Task(int dueDate, std::string& title, int priority){
    this->dueDate = dueDate;
    this->title = title;
    this->priority = priority;
}

void addTask(Task task, std::vector<Task>& tasks, int& taskCounter) {
    tasks.push_back(task);
    taskCounter++;
    std::cout << task.getDueDate() << " " << task.getTitle() << " " << task.getPriority() << std::endl;
    // Make a new function, and call it , to output the new vector to the file, and save the file.
}

int Task::getDueDate() {
    return dueDate;
}

std::string& Task::getTitle() {
    return title;
}

int Task::getPriority() {
    return priority;
}