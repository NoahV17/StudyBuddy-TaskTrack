#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(int dueDate, std::string& title, int priority);

    int getDueDate();
    std::string& getTitle();
    int getPriority();
    std::string print_due_date();
    
private:
    int dueDate;
    std::string title;
    int priority;
};

void addTask(Task task, std::vector<Task>& tasks, int& taskCounter);
void toString(std::vector<Task> tasks);

#endif // TASK_H

   // void addAssignment(Task& task);
    // void nearestDueDate();
    // void showAssignments(std::string& sortBy);