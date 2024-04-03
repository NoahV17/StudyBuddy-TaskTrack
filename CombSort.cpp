#include <vector>
#include <string>
#include <algorithm>

struct Task {
    int priority;
    std::string dueDate;
};

class CombSort {
public:
    CombSort(std::vector<Task>& tasks) 
        : tasks(tasks), 
          gap(tasks.size()), 
          shrink(1.3), 
          sorted(false) 
    {}

    void prioritySort() {
        sorted = false;
        gap = tasks.size();
        while (!sorted) {
            gap = static_cast<int>(gap / shrink);
            if (gap <= 1) {
                gap = 1;
                sorted = true;
            }
            for (int i = 0; i + gap < tasks.size(); i++) {
                if (tasks[i].priority < tasks[i + gap].priority) {
                    std::swap(tasks[i], tasks[i + gap]);
                    sorted = false;
                }
            }
        }
    }

    void dateSort() {
        sorted = false;
        gap = tasks.size();
        while (!sorted) {
            gap = static_cast<int>(gap / shrink);
            if (gap <= 1) {
                gap = 1;
                sorted = true;
            }
            for (int i = 0; i + gap < tasks.size(); i++) {
                if (tasks[i].dueDate > tasks[i + gap].dueDate) {
                    std::swap(tasks[i], tasks[i + gap]);
                    sorted = false;
                }
            }
        }
    }

private:
    std::vector<Task>& tasks;
    int gap;
    double shrink;
    bool sorted;
};