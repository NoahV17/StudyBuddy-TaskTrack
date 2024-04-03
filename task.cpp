#include "Task.h"

Task::Task(const std::string& dueDate, const std::string& title, int priority)
    : dueDate(dueDate), title(title), priority(priority) {}

const std::string& Task::getDueDate() const {
    return dueDate;
}

const std::string& Task::getTitle() const {
    return title;
}

int Task::getPriority() const {
    return priority;
}