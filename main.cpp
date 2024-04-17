#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "task.h"
#include "combSort.h"
#include "ternarySearch.h"
//./main <utility-name> <potential-parameters>

// different utilities + parameters
//ADD <due date mmddyy> <class name task is for> <title> <priority out of 10>
//PRINT <what you want to print by, due date is default, if priority then use (pr)>
//DEL <index of assignment>
//SORT <how you want to sort, due date (dd), priority (pr)>
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
            std::string dueDateStr, classStr, title, priorityStr;
            if (!std::getline(iss, dueDateStr, ',') || !std::getline(iss, classStr, ',') || !std::getline(iss, title, ',') || !std::getline(iss, priorityStr, ',')) {
                break;
            }

            int priority = std::stoi(priorityStr);

            Task task(dueDateStr, classStr, title, priority);
            addTask(task, tasks, taskCounter);
        }
        std::cout << "Sucessfully loaded tasks from file." << std::endl;
        std::cout << std::endl;
        file.close();
    }

    //Sorts list by date if not already sorted
    CombSort combsort(tasks);
    tasks = combsort.sort_by_date(tasks);
    bool sorted_by_date = true;
    
    std::cout << "Welcome to the Task Manager!" << std::endl;
    std::cout << "Total amount of current tasks: " << taskCounter << std::endl;
    std::cout << "Current working commands:" << std::endl;
    std::cout << "ADD <Due date> <Class the task is for, or other grouping identifier> <Title or description> <priority 0-10>" << std::endl;
    std::cout << "PRINT <sorted by 'dd' or 'pr'>" << std::endl;
    std::cout << "DEL <index to delete>, starts at 1 to match how tasks are printed" << std::endl;
    std::cout << "SORT <sorted by 'dd' or 'pr'>" << std::endl;
    std::cout << std::endl;

    std::string utilityName = argv[1];
    
    //printTasksInMonth(tasks, 2, 2025);
    if (utilityName == "ADD") {
        //ADD AN ASSIGNMENT (ADD <due date mmddyy> <title> <priority out of 10>)
        // This function adds to your list of assignments, it will add to the self organizing list 

        if (argc != 6) {
            std::cerr << "Error: Invalid parameters for ADD." << std::endl;
            return 1;
        }

        std::string dueDate = argv[2];
        std::cout << "Due date entered correctly " << dueDate << std::endl;
        std::string classNum = argv[3];
        std::cout << "Class entered correctly " << classNum << std::endl;
        std::string title = argv[4];
        std::cout << "Title entered correctly " << title << std::endl;
        int priority = std::stoi(argv[5]);
        std::cout << "Priority entered correctly " << priority << std::endl;
        Task task(dueDate, classNum, title, priority);
        addTask(task, tasks, taskCounter);


    } else if (utilityName == "ONDAY") {
        // NEAREAST DUE DATE (NDD)
        // This will use ternary search to look for the assignment with the nearest due date
        // nearestDueDate();
    } else if (utilityName == "PRINT") {
        // PRINT (PRINT <what you want to print by, due date is default, if priority then use (pr)>)
        // This will print your whole list of due assignments with their respective info
        std::string sortBy = "dd";
        if (argc >= 3) {
            sortBy = argv[2];
        }
        
        if (sortBy == "pr") {
            toString(combsort.sort_by_priority(tasks));
        } else if (sortBy == "dd"){
            toString(combsort.sort_by_date(tasks));
        }
    } else if (utilityName == "DEL") {
        // DELETE (DEL <index of assignment>)
        // This will delete the assignment at the index you specify
        if (argc != 3) {
            std::cerr << "Error: Invalid parameters for DEL." << std::endl;
            return 1;
        }

        int index = std::stoi(argv[2]);
        removeTask(tasks, index);
    } else if (utilityName == "SORT") {
        // SORT (SORT <how you want to sort, due date (dd), priority (pr)>)
        // This will sort your list of assignments by due date or priority

        if (argc != 3) {
            std::cerr << "Error: Invalid parameters for SORT." << std::endl;
            return 1;
        }

        std::string sortBy = argv[2];
        if (sortBy == "pr") {
            tasks = combsort.sort_by_priority(tasks);
        } else if (sortBy == "dd"){
            tasks = combsort.sort_by_date(tasks);
        }
        std::cout << "Sorted by " << sortBy << std::endl;
    } else {
        std::cerr << "Error: Invalid utility name." << std::endl;
        return 1;
    }
    
    toFile(tasks, false);

    // updateFile, part of task class
    // first sort by due date, then loop through the vector from 
    // i = 0 to i = tasks.size(), and output in the format
    
    // 102823 Midterm 3 \n
    // aka
    //task.getDueDate << " " << task.getTitle << " " << task.getPriority

    return 0;
}