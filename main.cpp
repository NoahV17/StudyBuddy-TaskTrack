#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "task.h"
#include "combSort.h"
#include "binarySearch.h"

int main(int argc, char* argv[]) {
    // Read command line input for
    // ./main <utility-name> <potential-parameters>
    std::vector<Task> tasks;
    std::ifstream file("tasks.txt");
    std::string filename = "tasks.txt";
    std::string title;
    int taskCounter = 0;
    int dueDate, priority;
    
    
    //Load list from file
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int dueDate;
            std::string title;
            int priority;
            if (!(iss >> dueDate >> title >> priority)) {
                break;
            }

            Task task(dueDate, title, priority);
            addTask(task, tasks, taskCounter);
        }
        file.close();
    }

    //Sorts list by date if not already sorted
    CombSort combsort(tasks);
    tasks = combsort.sort_by_date(tasks);
    bool sorted_by_date = true;

    // Hard coded tester for add
    dueDate = 122325;
    title = "finalProject";
    priority = 10;

    //std::string utilityName = argv[1];
    Task task(dueDate, title, priority);
    addTask(task, tasks, taskCounter);
    std::cout << "Total amount of tasks: " << taskCounter << std::endl;
    std::cout << std::endl;

    printPriority(tasks, 10);
    std::cout << std::endl;
    toString(tasks);

    //Initialize combSort object
    CombSort combsort(tasks);

    //Soft a certain way, then pass that vector as parameter to print out
    toString(combsort.sort_by_priority(tasks));
    toString(combsort.sort_by_date(tasks));
    
    //printTasksInMonth(tasks, 2, 2025);
    // if (utilityName == "ADD") {
    //     //ADD AN ASSIGNMENT (ADD <due date mmddyy> <title> <priority out of 10>)
    //     // This function adds to your list of assignments, it will add to the self organizing list 

    //     if (argc != 5) {
    //         std::cerr << "Error: Invalid parameters for ADD." << std::endl;
    //         return 1;
    //     }

    //     std::string dueDate = argv[2];
    //     std::string title = argv[3];
    //     int priority = std::stoi(argv[4]);
    //     Task task(dueDate, title, priority);
    //     addTask(task);
    // } else if (utilityName == "NDD") {
    //     // NEAREAST DUE DATE (NDD)
    //     // This will use binary search to look for the assignment with the nearest due date

    //     nearestDueDate();
    // } else if (utilityName == "SHOW") {
    //     // OUTPUT (SHOW <what you want to sort by, due date (dd), priority (pr)>)
    //     // This will print your whole list of due assignments with their respective info

    //     if (argc != 3) {
    //         std::cerr << "Error: Invalid parameters for SHOW." << std::endl;
    //         return 1;
    //     }

    //     std::string sortBy = argv[2];



    //updateFile, part of task class
    //first sort by due date, then loop through the vector from 
    //i = 0 to i = tasks.size(), and output in the format
    //
    //102823 Midterm 3 \n
    //aka
    //task.getDueDate << " " << task.getTitle << " " << task.getPriority

    return 0;
}