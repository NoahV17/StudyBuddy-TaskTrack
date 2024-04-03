#include <string>

class Task {
public:
    Task(const std::string& dueDate, const std::string& title, int priority);

    const std::string& getDueDate() const;
    const std::string& getTitle() const;
    int getPriority() const;
    void addAssignment(const Task& task);
    void nearestDueDate();
    void showAssignments(const std::string& sortBy);

private:
    std::string dueDate;
    std::string title;
    int priority;
};