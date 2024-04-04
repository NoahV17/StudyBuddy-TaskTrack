#include <vector>
#include "Task.h"

class SelfOrganizingList {
public:
    SelfOrganizingList();

    void addTask(Task& task);
    
    void writeToFile();

private:
    std::vector<Task> tasks;
    std::string filename;
};