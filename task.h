#include <string>

class Task {
public:
    Task::Task(std::string& dueDate, std::string& title, int priority);

    std::string& getDueDate();
    std::string& getTitle();
    int getPriority();
    void addAssignment(Task& task);
    void nearestDueDate();
    void showAssignments(std::string& sortBy);

private:
    std::string dueDate;
    std::string title;
    int priority;
};