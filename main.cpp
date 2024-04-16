#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "task.h"
#include "combSort.h"
#include "ternarySearch.h"

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
    
    std::cout << "Welcome to the Task Manager!" << std::endl;
    std::cout << "Total amount of current tasks: " << taskCounter << std::endl;
    std::cout << std::endl;

    std::string utilityName = argv[1];
    
    printTasksInMonth(tasks, 2, 2025);
    if (utilityName == "ADD") {
        //ADD AN ASSIGNMENT (ADD <due date mmddyy> <title> <priority out of 10>)
        // This function adds to your list of assignments, it will add to the self organizing list 

        if (argc != 5) {
            std::cerr << "Error: Invalid parameters for ADD." << std::endl;
            return 1;
        }

        int dueDate = std::stoi(argv[2]);
        std::string title = argv[3];
        int priority = std::stoi(argv[4]);
        Task task(dueDate, title, priority);
        addTask(task, tasks, taskCounter);


    } else if (utilityName == "DIM") {
        // NEAREAST DUE DATE (NDD)
        // This will use binary search to look for the assignment with the nearest due date
        //nearestDueDate();
    } else if (utilityName == "PRINT") {
        // OUTPUT (PRINT <what you want to print by, due date is default, if priority then use (pr)>)
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

    } else {
        std::cerr << "Error: Invalid utility name." << std::endl;
        return 1;
    }


    // updateFile, part of task class
    // first sort by due date, then loop through the vector from 
    // i = 0 to i = tasks.size(), and output in the format
    
    // 102823 Midterm 3 \n
    // aka
    //task.getDueDate << " " << task.getTitle << " " << task.getPriority

    return 0;
}