#include <vector>
#include "Task.h"

class SelfOrganizingList {
public:
    SelfOrganizingList(const std::string& filename);

    void addTask(const Task& task);
    void writeToFile();

private:
    std::vector<Task> tasks;
    std::string filename;
};