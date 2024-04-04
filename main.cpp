#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "task.cpp"
// #include "SelfOrganizingList.cpp"
// #include "CombSort.cpp"
// #include "BinarySearch.cpp"

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

    // Hard coded tester for add
    dueDate = 120325;
    title = "finalProject";
    priority = 10;

    //std::string utilityName = argv[1];
    Task task(dueDate, title, priority);
    addTask(task, tasks, taskCounter);
    std::cout << "Total tasks: " << taskCounter << std::endl;
    
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

    //     showAssignments(sortBy);
    // } else {
    //     std::cerr << "Error: Unknown utility name." << std::endl;
    //     return 1;
    // }

    return 0;
}

// finalProject 212 10 302722
// finalProject 212 10 302722
// finalProject 212 10 302722
// finalProject 212 10 302722