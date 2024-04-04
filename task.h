#include <string>

class Task {
public:
    Task(int dueDate, std::string& title, int priority);

    int getDueDate();
    std::string& getTitle();
    int getPriority();
    // void addTask(Task task, std::vector<Task>& tasks);
    void addTask(Task task, std::vector<Task>& tasks, int& taskCounter);

private:
    int dueDate;
    std::string title;
    int priority;
};

   // void addAssignment(Task& task);
    // void nearestDueDate();
    // void showAssignments(std::string& sortBy);