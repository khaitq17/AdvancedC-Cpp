/*
* File: manager.cpp   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file includes menu and operations of the manager.
*/

#include <iostream>
#include <string>
#include "manager.h"
#include "database.h"


using namespace std;

/*
* Function: menu
* Description: This function contains operations of the manager to set table, dish.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::menu() {
    int choice, choiceInCase;

    do
    {
        cout << "-------------------------------------------" << endl;
        cout << "\t\tMANAGER" << endl;
        cout << "1. Set up number of table" << endl;
        cout << "2. Add dish" << endl;
        cout << "3. Edit dish" << endl;
        cout << "4. Delete dish" << endl;
        cout << "5. View dishes" << endl;
        cout << "0. Return" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Set up number of table
        {   setup_table:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tSet up number of table" << endl;
            setupTables();
            cout << "-------------------------------------------" << endl;
            cout << "Set up number of table successfully." << endl;

            select_after_setup:
            cout << "1. Return" << endl;
            cout << "0. Exit" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto setup_table;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_setup;
            }
            break;
        }


        case 2: // Add dish
        {
            add_dish:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tAdd dish" << endl;
            addDish();
            select_after_add_dish:
            cout << "-------------------------------------------" << endl;
            cout << "Do you want to add other dishes?" << endl;
            cout << "1. Add other dishes" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto add_dish;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_add_dish;
            }

            break;
        }


        case 3: // Edit dish
        {
            edit_dish:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tEdit dish" << endl;
            viewDishes();
            cout << endl;
            editDish();
            select_after_edit_dish:
            cout << "-------------------------------------------" << endl;
            cout << "Do you want to edit other dishes?" << endl;
            cout << "1. Edit other dishes" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto edit_dish;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_edit_dish;
            }

            break;
        }
            

        case 4: // Delete dish
        {
            delete_dish:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tDelete dish" << endl;
            viewDishes();
            cout << endl;
            deleteDish();

            select_after_delete_dish:
            cout << "-------------------------------------------" << endl;
            cout << "Do you want to delete other dishes?" << endl;
            cout << "1. Delete other dishes" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto delete_dish;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_delete_dish;
            }
            break;
        }

        case 5: // View dishes  
        {
            cout << "-------------------------------------------" << endl;
            cout << "\t\tView dishes" << endl;
            viewDishes();

            select_after_view:
            cout << "-------------------------------------------" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_view;
            }
            break;
        }

        case 0: // Return
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    
}


/*
* Function: setupTables
* Description: This function sets number of table to serve.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::setupTables() {
    int numberOfTables;
    cout << "Enter number of table to set up: ";
    cin >> numberOfTables;

    Database::getInstance().setupTables(numberOfTables);
}


/*
* Function: addDish
* Description: This function adds new dish to the dishes list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::addDish() {
    string name;
    int price;
    cout << "Enter name of the new dish: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter unit price: ";
    cin >> price;

    Dish newDish(name, price);
    Database::getInstance().addDish(newDish);

    cout << "-------------------------------------------" << endl;
    cout << "Dish information: " << endl;
    printDishInformation(newDish);
    cout << "Add dish successfully" << endl;
}

/*
* Function: editDish
* Description: This function edits price of a dish in the dishes list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::editDish() {
    int id;
    cout << "Please enter dish ID to edit: ";
    cin >> id;

    Database::getInstance().editDish(id);
}


/*
* Function: deleteDish
* Description: This function deletes a dish from the dishes list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::deleteDish() {
    int id;
    cout << "Please enter dish ID to delete: ";
    cin >> id;

    Database::getInstance().deleteDish(id);
}


/*
* Function: viewDishes
* Description: This function prints dishes list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::viewDishes() const {
    Database::getInstance().viewDishes();
}


/*
* Function: printDishInformation
* Description: This function prints information of a dish.
* Input:
*   dish - dish that want to print information
* Output:
*   returns none
*/
void Manager::printDishInformation(Dish dish) {
    cout << "\tID\t|\tName\t\t|\tUnit price" << endl;
    cout << "\t" << dish.getId() << "\t|\t" << dish.getName() << "\t|\t" << dish.getPrice() << endl; 
}