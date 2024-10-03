/*
* File: employee.cpp   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file includes menu and operations of the employees. 
*/

#include "employee.h"
#include "database.h"
#include <iostream>

using namespace std;

/*
* Function: menu
* Description: This function contains operations of the employee to serve.
* Input:
*   none
* Output:
*   returns none
*/
void Employee::menu() {
    int choice, choiceInCase, tableId;

    cout << "-------------------------------------------" << endl;
    cout << "\t\tEMPLOYEE" << endl;
    
    select_table:
    Database::getInstance().viewTableList();

    cout << "-------------------------------------------" << endl;
    cout << "Select table ID: ";
    cin >> tableId;

    Table* table = Database::getInstance().getTable(tableId);
    if (!table) {
        cout << "Table is not available. Please try again." << endl;
        goto select_table;
    }

    do
    {
        cout << "-------------------------------------------" << endl;
        cout << "\tTable ID " << tableId << endl;
        cout << "1. Order dish" << endl;
        cout << "2. Cancel dish" << endl;
        cout << "3. Change dish" << endl;
        cout << "4. View ordered dishes" << endl;
        cout << "5. Pay" << endl;
        cout << "0. Return" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {    
        case 1: // Order dish
        {
            order_dish:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tOrder dish" << endl;
            Database::getInstance().viewDishes();

            cout << "-------------------------------------------" << endl;
            orderDish(table);

            select_after_order_dish:
            cout << "-------------------------------------------" << endl;
            cout << "Do you want to order other dishes?" << endl;
            cout << "1. Order other dishes" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto order_dish;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_order_dish;
            }

            break;
        }    
            
        
        case 2: // Cancel dish
        {
            cancel_dish:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tCancel dish" << endl;
            Database::getInstance().viewOrderedDishes(table);

            cout << "-------------------------------------------" << endl;
            cancelDish(table);

            select_after_cancel_dish:
            cout << "-------------------------------------------" << endl;
            cout << "Do you want to cancel other dishes?" << endl;
            cout << "1. Cancel other dishes" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto cancel_dish;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_cancel_dish;
            }

            break;
        }    
            
        
        case 3: // Change dish
        {
            change_dish:
            cout << "-------------------------------------------" << endl;
            cout << "\t\tChange dish" << endl;
            Database::getInstance().viewOrderedDishes(table);

            cout << "-------------------------------------------" << endl;
            changeDish(table);

            select_after_change_dish:
            cout << "-------------------------------------------" << endl;

            cout << "Do you want to change other dishes?" << endl;
            cout << "1. Change other dishes" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                goto change_dish;
            
            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_change_dish;
            }

            break;
        }    
            
        
        case 4: // View ordered dishes
        {
            cout << "-------------------------------------------" << endl;
            cout << "\t\tView ordered dishes" << endl;
            viewOrderedDishes(table);

            select_after_view_dishes:
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
                goto select_after_view_dishes;
            }

            break;
        }    
            
        
        case 5: // Pay
        {
            cout << "-------------------------------------------" << endl;
            cout << "\t\tPay bill" << endl;
            viewOrderedDishes(table);
            cout << "-------------------------------------------" << endl;
            pay(table);

            select_after_pay:
            cout << "-------------------------------------------" << endl;
            cout << "1. Pay" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1:
                cout << "-------------------------------------------" << endl;
                cout << "Successful payment." << endl;
                cout << "-------------------------------------------" << endl;
                table->clearOrder();
                table->setTableStatus(EMPTY);
                break;
            
            case 0:
                goto select_table;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_pay;
            }
            break;
        }    
            
        
        case 0: // Return
            break;;
            
            
        default:
            cout << "Invalid choice. Please try again." << endl;
        }


    } while (choice != 0);
           
}


/*
* Function: orderDish
* Description: This function adds dish to the order list.
* Input:
*   table - table that want to order dish
* Output:
*   returns none
*/
void Employee::orderDish(Table* table) {
    int dishId;

    cout << "Enter dish ID to order: ";
    cin >> dishId;

    Database::getInstance().orderDish(table, dishId);
}

/*
* Function: cancelDish
* Description: This function cancels dish in the order list. 
* Input:
*   table - table that want to cancel dish   
* Output:
*   returns none 
*/
void Employee::cancelDish(Table* table) {
    int dishId;

    cout << "Enter dish ID to cancel: ";
    cin >> dishId;

    Database::getInstance().cancelDish(table, dishId);
}


/*
* Function: changeDish
* Description: This function changes dish in the order list.
* Input:
*   table - table that want to change dish
* Output:
*   returns none
*/
void Employee::changeDish(Table* table) {
    int oldId;

    cout << "Enter dish ID to change: ";
    cin >> oldId;

    Database::getInstance().changeDish(table, oldId);
}


/*
* Function: viewOrderedDishes
* Description: This function prints a list of ordered dishes.
* Input:
*   table - table that want to view list
* Output:
*   returns none
*/
void Employee::viewOrderedDishes(Table* table) {
    Database::getInstance().viewOrderedDishes(table);
}


/*
* Function: pay
* Description: This function displays payment information of a table.
* Input:
*   table - table that want to pay    
* Output:
*   returns none
*/
void Employee::pay(Table* table) {
    Database::getInstance().pay(table);
}