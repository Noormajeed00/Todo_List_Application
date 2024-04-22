#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Function to print tasks
void print_tasks(string tasks[], int task_count)
{
    // Print header for the tasks
    cout << "Tasks To Do: " << endl;
    cout << "--------------------" << endl;
    
    // Loop through tasks and print them with their indices
    for (int i = 0; i < task_count; i++)
    {
        cout << "Task " << i << " : " << tasks[i] << endl;
    }
    
    // Print footer for the tasks
    cout << "--------------------" << endl;
}

int main()
{
    // Array to store tasks, initialized with empty strings
    string tasks[10] = {""};
    // Variable to keep track of the number of tasks
    int task_count = 0;

    // Variable to store user's choice
    int option = -1;
    
    // Main loop for the task management system
    while (option != 0)
    {
        // Display menu options
        cout << "--- TO DO LIST ---" << endl;
        cout << "1 - To Add New Task" << endl;
        cout << "2 - To View Task" << endl;
        cout << "3 - Delete The Tasks" << endl;
        cout << "0 - Terminate The Program" << endl;
        
        // Input the user's choice
        cin >> option;

        switch (option)
        {
            // Option 1: Add a new task
            case 1:
            {
                // Check if the task list is full
                if (task_count > 9)
                {
                    cout << "```TASK LIST IS FULL```" << endl;
                }
                else
                {
                    // Prompt the user to input a new task
                    cout << "ENTER A NEW TASK: ";
                    cin.ignore(); // Ignore any leftover newline character
                    getline(cin, tasks[task_count]); // Input the task
                    task_count++; // Increment the task count
                }
                break;
            }
            // Option 2: View tasks
            case 2:
                // Clear the console screen
                system("cls");
                // Print the tasks
                print_tasks(tasks, task_count);
                break;
            // Option 3: Delete a task
            case 3:
            {
                // Clear the console screen
                system("cls");
                // Print the tasks
                print_tasks(tasks, task_count);
                // Variable to store the task index to delete
                int del_task = 0;
                // Prompt the user to enter the task index to delete
                cout << "Enter A Task To Delete: ";
                cin >> del_task;

                // Check if the entered task index is valid
                if (del_task < 0 || del_task >= task_count)
                {
                    cout << "You Entered Invalid Task No." << endl;
                    break;
                }

                // Shift tasks to the left to overwrite the deleted task
                for (int i = del_task; i < task_count - 1; i++)
                {
                    tasks[i] = tasks[i + 1];
                }
                task_count--; // Decrement the task count
                break;
            }
            // Option 0: Terminate the program
            case 0:
                cout << "Terminating the Program" << endl;
                break;
            // Default case: Invalid input
            default:
                cout << "You Entered Invalid Value!" << endl;
        }
    }
    return 0; // End of the program
}

