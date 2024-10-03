/*
* File: manager.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file includes menu and operations of the manager.
*/

#include <iostream>
#include <string>
#include "manager.h"
#include "database.h"

using namespace std;

/*
* Function: Manager
* Description: This function initializes the initial information of the manager.
* Input:
*   none
* Output:
*   returns the manager 
*/
Manager::Manager() : username("ADMIN"), password("123456") {}


/*
* Function: menu
* Description: This function includes menu and operations of the manager.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::menu() {
    int choice, choiceInCase, select;

    do
    {   
        manager_menu:
        cout << "------------------------------------------------" << endl;
        cout << "\t\tMANAGER" << endl;
        cout << "1. Manage employees" << endl;
        cout << "2. Manage rooms" << endl;
        cout << "3. Service" << endl;
        cout << "0. Return" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Manage employees
        {
            manage_employee:
            cout << "------------------------------------------------" << endl;
            cout << "\t\tManage employees" << endl;
            cout << "1. Add employee" << endl;
            cout << "2. Edit employee information" << endl;
            cout << "3. Delete employee" << endl;
            cout << "4. Set employee shifts" << endl;
            cout << "5. List employee information" << endl;
            cout << "6. Employee working time" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Add employee
            {
                add_employee:
                cout << "------------------------------------------------" << endl;
                cout << "\t\tAdd employee" << endl;
                addEmployee();
                cout << "------------------------------------------------" << endl;
                cout << "Add employee successfully." << endl;

                select_after_add_employee:
                cout << "1. Add other employees" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1: 
                    goto add_employee;
                
                case 0:
                    goto manage_employee;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_add_employee;
                }

                break;
            }


            case 2: // Edit employee information
            {
                cout << "------------------------------------------------" << endl;
                cout << "\t\tEdit employee information" << endl;
                viewEmployeeList();
                cout << "------------------------------------------------" << endl;
                editEmployeeInformation();

                select_after_edit_employee:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto manage_employee;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_edit_employee;
                }

                break;
            }


            case 3: // Delete employee
            {
                cout << "------------------------------------------------" << endl;
                cout << "\t\tDelete employee" << endl;
                viewEmployeeList();
                cout << "------------------------------------------------" << endl;
                deleteEmployee();

                select_after_delete_employee:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto manage_employee;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_delete_employee;
                }

                break;
            }

            
            case 4: // Set employee shifts
            {   
                set_shifts:
                cout << "------------------------------------------------" << endl;
                cout << "\t\tSet employee shifts" << endl;
                viewEmployeeList();
                cout << "------------------------------------------------" << endl;
                setEmployeeShifts();

                select_after_set_shifts:
                cout << "1. Set other shifts" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1:
                    goto set_shifts;

                case 0:
                    goto manage_employee;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_set_shifts;
                }

                break;
            }


            case 5: // List employee information
            {   
                cout << "------------------------------------------------" << endl;
                cout << "\t\tList employee information" << endl;
                viewEmployeeList();
                cout << "------------------------------------------------" << endl;
                select_after_print_information:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto manage_employee;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_print_information;
                }

                break;
            }


            case 6: // Employee working time
            {
                cout << "------------------------------------------------" << endl;
                viewEmployeeSchedule();

                select_after_print_schedule:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto manage_employee;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_print_schedule;
                }

                break;
            }


            case 0: // Return                
                break;
            
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto manage_employee;          

            }

            break;
        }


        case 2: // Manage rooms
        {
            manage_room:
            cout << "------------------------------------------------" << endl;
            cout << "\t\tManage rooms" << endl;
            cout << "1. Add room" << endl;
            cout << "2. Delete room" << endl;
            cout << "3. View room status" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Add room
            {   
                add_room:
                cout << "------------------------------------------------" << endl;
                cout << "\t\tAdd room" << endl;
                addRoom();
                cout << "------------------------------------------------" << endl;
                cout << "Add room successfully." << endl;

                select_after_add_room:
                cout << "1. Add other rooms" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1:
                    goto add_room;

                case 0:
                    goto manage_room;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_add_room;
                }

                break;
            }


            case 2: // Delete room
            {  
                delete_room: 
                cout << "------------------------------------------------" << endl;
                cout << "\t\tDelete room" << endl;
                viewRoomList();
                cout << "------------------------------------------------" << endl;
                deleteRoom();
                cout << "------------------------------------------------" << endl;
                select_after_delete_room:
                cout << "1. Delete other rooms" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1:
                    goto delete_room;

                case 0:
                    goto manage_room;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_delete_room;
                }

                break;
            }


            case 3: // View room status
            {   
                cout << "------------------------------------------------" << endl;
                cout << "\t\tView room status" << endl;
                viewRoomList();
                cout << "------------------------------------------------" << endl;
                select_after_view_room:
                cout << "1. View room information" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1:
                    cout << "------------------------------------------------" << endl;
                    cout << "\t\tView room information" << endl;
                    viewRoomInformation();
                    cout << "------------------------------------------------" << endl;
                    select_after_view_room_info:
                    cout << "0. Return" << endl;
                    cout << "Please enter your choice: ";
                    int _select; cin >> _select;

                    switch (_select)
                    {
                    case 0:
                        break;
                
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        goto select_after_view_room_info;
                    }
                    
                case 0:
                    goto manage_room;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_view_room;
                }
                break;
            }


            case 0: // Return
                break;


            default:
                cout << "Invalid choice. Please try again." << endl;
                goto manage_room;   
            }

            break;
        }
        
        case 3: // Service
        {
            service:
            cout << "------------------------------------------------" << endl;
            cout << "\t\tService" << endl;    
            cout << "1. Food & Drink" << endl;
            cout << "2. Swimming Pool" << endl;
            cout << "3. Gym" << endl;
            cout << "4. Laundry" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Food & Drink
            {
                food_and_drink:
                cout << "------------------------------------------------" << endl;
                cout << "\t\tFood & Drink" << endl;  
                cout << "1. Add item" << endl;
                cout << "2. Delete item" << endl;
                cout << "3. View menu" << endl;
                cout << "4. Update item price" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                int itemSelection;
                cin >> itemSelection;

                switch (itemSelection)
                {
                case 1: // Add item
                {
                    add_item:    
                    cout << "------------------------------------------------" << endl;
                    cout << "\t\tAdd item" << endl;
                    addItem();
                    cout << "------------------------------------------------" << endl;
                    cout << "Add item successfully." << endl;

                    select_after_add_item:
                    cout << "1. Add other item" << endl;
                    cout << "0. Return" << endl;
                    cout << "Please enter your choice: ";
                    cin >> select;

                    switch (select)
                    {
                    case 1:
                        goto add_item;
                    
                    case 0:
                        goto food_and_drink;

                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        goto select_after_add_item;
                    }

                    break;
                }


                case 2: // Delete item
                {   
                    delete_item:
                    cout << "------------------------------------------------" << endl;
                    cout << "\t\tDelete item" << endl;
                    viewMenu();
                    cout << "------------------------------------------------" << endl;
                    deleteItem();
                    cout << "------------------------------------------------" << endl;
                    select_after_delete_item:
                    cout << "1. Delete other item" << endl;
                    cout << "0. Return" << endl;
                    cout << "Please enter your choice: ";
                    cin >> select;

                    switch (select)
                    {
                    case 1:
                        goto delete_item;
                    
                    case 0:
                        goto food_and_drink;

                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        goto select_after_delete_item;
                    }

                    break;
                }
                

                case 3: // View menu
                {
                    cout << "------------------------------------------------" << endl;
                    cout << "\t\tView menu" << endl;
                    viewMenu();
                    cout << "------------------------------------------------" << endl;
                    select_after_view_menu:
                    cout << "0. Return" << endl;
                    cout << "Please enter your choice: ";
                    cin >> select;

                    switch (select)
                    {
                    case 0:
                        goto food_and_drink;

                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        goto select_after_view_menu;
                    }

                    break;
                }


                case 4: // Update item price
                {
                    update_item_price:
                    cout << "------------------------------------------------" << endl;
                    cout << "\t\tUpdate item price" << endl;
                    viewMenu();
                    cout << "------------------------------------------------" << endl;
                    updateItemPrice();
                    cout << "------------------------------------------------" << endl;
                    select_after_update_item:
                    cout << "1. Update other item price" << endl;
                    cout << "0. Return" << endl;
                    cout << "Please enter your choice: ";
                    cin >> select;

                    switch (select)
                    {
                    case 1:
                        goto update_item_price;
                    
                    case 0:
                        goto food_and_drink;

                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        goto select_after_update_item;
                    }

                    break;
                }


                case 0:
                    goto service;


                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto food_and_drink;
                }

                break;
            }   


            case 2: // Swimming Pool
            {
                cout << "------------------------------------------------" << endl;
                cout << "\t\tSwimming pool" << endl;
                setSwimmingPoolPrice();
                cout << "------------------------------------------------" << endl;
                cout << "Set price successfully." << endl;
                select_after_set_swimming_pool:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto service;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_set_swimming_pool;
                }

                break;
            }


            case 3: // Gym
            {
                cout << "------------------------------------------------" << endl;
                cout << "\t\tGym" << endl;
                setGymPrice();
                cout << "------------------------------------------------" << endl;
                cout << "Set price successfully." << endl;
                select_after_set_laundry:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto service;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_set_laundry;
                }

                break;
            }


            case 4: // Laundry
            {
                cout << "------------------------------------------------" << endl;
                cout << "\t\tLaundry" << endl;
                setLaundryPrice();
                cout << "------------------------------------------------" << endl;
                cout << "Set price successfully." << endl;
                select_after_set_gym:
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 0:
                    goto service;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_set_gym;
                }

                break;
            }


            case 0: // Return
                goto manager_menu;
            

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto service;
            }

            break;
        }
        
        case 0: // Return
            break;


        default:
            cout << "Invalid choice. Please try again." << endl;
            goto manager_menu;
            break;

        }

    } while (choice != 0);
 
}


/*
* Function: getUsername
* Description: This function gets the manager username.
* Input:
*   none
* Output:
*   returns manager username
*/
string Manager::getUsername() const {
    return username;
}


/*
* Function: getPhoneNumber
* Description: This function gets manager phone number.
* Input:
*   none
* Output:
*   returns manager phone number
*/
string Manager::getPhoneNumber() const {
    return phoneNumber;
}


/*
* Function: getPassword
* Description: This function gets manager password.
* Input:
*   none
* Output:
*   returns manager password
*/
string Manager::getPassword() const {
    return password;
}


/*
* Function: setUsername
* Description: This function sets manager username.
* Input:
*   newUsername - manager username
* Output:
*   returns none
*/
void Manager::setUsername(string newUsername) {
    this->username = newUsername;
}


/*
* Function: setPhoneNumber
* Description: This function sets manager phone number.
* Input:
*   newPhoneNumber - manager phone number
* Output:
*   returns none
*/
void Manager::setPhoneNumber(string newPhoneNumber) {
    this->phoneNumber = newPhoneNumber;
}


/*
* Function: setPassword
* Description: This function sets manager password.
* Input:
*   newPassword - manager password
* Output:
*   returns none 
*/
void Manager::setPassword(string newPassword) {
    this->password = newPassword;
}


/*
* Function: addEmployee
* Description: This function adds an employee to the employee list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::addEmployee() {
    cout << "Enter employee name: ";
    string name; 
    cin.ignore();
    getline(cin, name);

    cout << "Enter employee phone number: ";
    string phoneNumber; cin >> phoneNumber;

    select_position:
    cout << "Enter employee position (1 - Janitor, 2 - Security, 3 - Chef): ";
    int positionSelect; cin >> positionSelect;
    Position position;

    switch (positionSelect)
    {
    case 1:
        position = JANITOR;
        break;    

    case 2: 
        position = SECURITY;
        break;

    case 3: 
        position = CHEF;
        break;

    default:
        cout << "Invalid choice. Please try again." << endl;
        goto select_position;
    }

    Database::getInstance().addEmployee(name, position, phoneNumber);
}


/*
* Function: editEmployeeInformation
* Description: This function edits information of an employee.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::editEmployeeInformation() {
    int id;
    cout << "Please enter Id of employee that you want to edit information: ";
    cin >> id;

    Database::getInstance().editEmployeeInformation(id);
}


/*
* Function: deleteEmployee
* Description: This function deletes an employee from the employee list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::deleteEmployee() {
    int id;
    cout << "Please enter Id of employee that you want to delete: ";
    cin >> id;

    Database::getInstance().deleteEmployee(id);
}


/*
* Function: setEmployeeShifts
* Description: This function sets shifts for an employee.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::setEmployeeShifts() {
    int id;
    cout << "Please enter Id of employee that you want to set shift: ";
    cin >> id;

    Database::getInstance().setEmployeeShifts(id);
}


/*
* Function: viewEmployeeList
* Description: This function displays the list of employees.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::viewEmployeeList() {
    Database::getInstance().printEmployeeList();
}


/*
* Function: viewEmployeeSchedule
* Description: This function displays work schedule of all employees.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::viewEmployeeSchedule() {
    Database::getInstance().printWorkSchedule();
}


/*
* Function: addRoom
* Description: This function adds room to the room list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::addRoom() {
    int id;
    cout << "Please enter room ID: ";
    cin >> id;

    Database::getInstance().addRoom(id);
}


/*
* Function: deleteRoom
* Description: This function deletes room from the room list.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::deleteRoom() {
    int id;
    cout << "Please enter ID of room that you want to delete: ";
    cin >> id;

    Database::getInstance().deleteRoom(id);
}


/*
* Function: viewRoomList
* Description: This function displays the list of rooms.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::viewRoomList() const {
    Database::getInstance().printRoomList();
}


/*
* Function: viewRoomInformation
* Description: This function displays information of a room.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::viewRoomInformation() {
    int id;
    cout << "Please enter room ID: ";
    cin >> id;

    Database::getInstance().viewRoomInformation(id);
}


/*
* Function: addItem
* Description: This function adds an item to the food and drink menu.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::addItem() {
    string name; double price;

    cout << "Enter item name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter price: ";
    cin >> price;

    Database::getInstance().addItem(name, price);
}


/*
* Function: deleteItem
* Description: This function deletes an item from the food and drink menu.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::deleteItem() {
    int id;
    cout << "Please enter ID of item that you want to delete: ";
    cin >> id;

    Database::getInstance().deleteItem(id);
}


/*
* Function: viewMenu
* Description: This function displays the menu of food and drink.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::viewMenu() {
    cout << "Menu Food and Drink" << endl;
    Database::getInstance().viewMenu();
}


/*
* Function: updateItemPrice
* Description: This function updates new price for an item.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::updateItemPrice() {
    int id;
    cout << "Please enter ID of item that you want to update price: ";
    cin >> id;

    Database::getInstance().updatePrice(id);
}


/*
* Function: setSwimmingPoolPrice
* Description: This function sets price use swimming pool per an hour.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::setSwimmingPoolPrice() {
    int price;
    cout << "Enter the price to use the swimming pool per an hour: ";
    cin >> price;

    Database::getInstance().setSwimmingPoolPrice(price);
}


/*
* Function: setGymPrice
* Description: This function sets price use gym per an hour.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::setGymPrice() {
     int price;
    cout << "Enter the price to use the gym per an hour: ";
    cin >> price; 

    Database::getInstance().setGymPrice(price);
}


/*
* Function: setLaundryPrice
* Description: This function sets price use laundry per one time.
* Input:
*   none
* Output:
*   returns none
*/
void Manager::setLaundryPrice() {
    int price;
    cout << "Enter the price to use laundry per one time: ";
    cin >> price;

    Database::getInstance().setLaundryPrice(price);
}