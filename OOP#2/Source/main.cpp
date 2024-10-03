#include <iostream>
#include "manager.h"
#include "employee.h"
#include "dish.h"
#include "table.h"
#include "database.h"

using namespace std;

int main(){
    Manager manager;
    Employee employee;
    int choice;

    do
    {
        cout << "-------------------------------------------" << endl;
        cout << "\t\tRESTAURANT MANAGEMENT" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Employee" << endl;
        cout << "0. Exit" << endl;

        cout << "Please enter your choice: "; 
        cin >> choice;

        switch (choice)
        {
        case 1: // Manager
            manager.menu();
            break;        


        case 2: // Employee
            employee.menu();
            break;
            

        case 0: // Exit  
            cout << "Exit" << endl;
            break;
        

        default:   
            cout << "Invalid choice. Please try again." << endl;
            
        }
    } while (choice != 0);

    return 0;
}