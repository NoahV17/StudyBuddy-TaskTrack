#include <vector>
#include <string>
#include <algorithm>
#include "combSort.h"
#include "task.h"
#include "ternarySearch.h"

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
            int date1 = tasks[i].getDueDateInt();
            int date2 = tasks[i + gap].getDueDateInt();

            // Convert dates to yyyymmdd format
            std::string convertedDate1 = "20" + std::to_string(date1 % 100) + std::to_string(date1 / 100 % 100) + std::to_string(date1 / 10000);
            std::string convertedDate2 = "20" + std::to_string(date2 % 100) + std::to_string(date2 / 100 % 100) + std::to_string(date2 / 10000);

            if (convertedDate1 > convertedDate2) {
                std::swap(tasks[i], tasks[i + gap]);
                sorted = false;
            } else if (convertedDate1 == convertedDate2) {
                if (tasks[i].getPriority() < tasks[i + gap].getPriority()) {
                    std::swap(tasks[i], tasks[i + gap]);
                    sorted = false;
                }
            }
        }
    }
    return tasks;
}