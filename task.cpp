#include "Task.h"

Task::Task(std::string& dueDate, std::string& title, int priority)
    : dueDate(dueDate), title(title), priority(priority) {}

std::string& Task::getDueDate() {
    return dueDate;
}

std::string& Task::getTitle() {
    return title;
}

int Task::getPriority() {
    return priority;
}