#include <vector>
#include <string>
#include <algorithm>
#include "combSort.h"
#include "task.h"

CombSort::CombSort(std::vector<Task>& tasks) : tasks(tasks), shrink(1.3), sorted(false), gap(0) {}

std::vector<Task> CombSort::sort_by_priority(std::vector<Task>& tasks) {
    sorted = false;
    gap = tasks.size();
    while (!sorted) {
        gap = static_cast<int>(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
        for (int i = 0; i + gap < tasks.size(); i++) {
            if (tasks[i].getPriority() < tasks[i + gap].getPriority()) {
                std::swap(tasks[i], tasks[i + gap]);
                sorted = false;
            }
        }
    }
    return tasks;
}

std::vector<Task> CombSort::sort_by_date(std::vector<Task>& tasks) {
    sorted = false;
    gap = tasks.size();
    while (!sorted) {
        gap = static_cast<int>(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
        for (int i = 0; i + gap < tasks.size(); i++) {
            if (tasks[i].getDueDate() > tasks[i + gap].getDueDate()) {
                std::swap(tasks[i], tasks[i + gap]);
                sorted = false;
            }
        }
    }
    return tasks;
}