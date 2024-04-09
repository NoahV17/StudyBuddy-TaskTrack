#ifndef COMBSORT_H
#define COMBSORT_H

// CombSort.h
#include <vector>
#include "task.h"

class CombSort {
public:
    CombSort(std::vector<Task>& tasks);

    std::vector<Task>& tasks;
    int gap;
    double shrink = 1.3;
    bool sorted = false;
    std::vector<Task> sort_by_priority(std::vector<Task>& tasks);
    std::vector<Task> sort_by_date(std::vector<Task>& tasks);

};

std::vector<Task> sort_by_priority(std::vector<Task>& tasks);
std::vector<Task> sort_by_date(std::vector<Task>& tasks);



#endif // COMBSORT_H