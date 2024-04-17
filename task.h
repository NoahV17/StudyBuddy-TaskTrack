#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string dueDate;
    std::string title;
    std::string classStr;
    int priority;

public:
    Task(std::string dueDate, std::string& classStr, std::string& title, int priority);
    std::string getDueDate();
    int getDueDateInt();
    std::string print_due_date();
    std::string& getTitle();
    std::string& getClass();
    int getPriority();
};

void addTask(Task task, std::vector<Task>& tasks, int& taskCounter);
void toString(std::vector<Task> tasks);
void toFile(std::vector<Task> tasks, bool temp);
void removeTask(std::vector<Task>& tasks, int index);

#endif // TASK_H

   // void addAssignment(Task& task);
    // void nearestDueDate();
    // void showAssignments(std::string& sortBy);