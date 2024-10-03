/*
* File: database.cpp   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file stores shared data for manager and employees.
*/

#include "database.h"

using namespace std;

/*
* Function: getInstance
* Description: This function is responsible for ensuring that only one instance of the class is created during the lifetime of the program.
* Input:
*   none
* Output:
*   returns new object if instance is null, else returns current object
*/
Database &Database::getInstance()
{
    static Database instance;
    return instance;
}


/*
* Function: addDish
* Description: This function adds new dish to the dishes list.
* Input:
*   dish - dish that want to add to dishes list
* Output:
*   returns none
*/
void Database::addDish(const Dish &dish)
{
    dishes.push_back(dish);
}


/*
* Function: editDish
* Description: This function edits price of a dish in the dishes list.
* Input:
*   id - ID of dish that want to edit its price
* Output:
*   returns none
*/
void Database::editDish(int id)
{
    double newPrice;
    for (auto &dish : dishes) {
        if (dish.getId() == id) {
            cout << "ID\t|\tName\t\t|\tPrice" << endl;
            cout << dish.getId() << "\t|\t" << dish.getName() << "\t|\t" << dish.getPrice() << endl << endl;

            cout << "Enter new price: ";
            cin >> newPrice;

            dish.setPrice(newPrice);
            cout << "Update dish information successfully." << endl;
            return; 
        } 
    }

    cout << "Not found ID." << endl;
}


/*
* Function: deleteDish
* Description: This function deletes a dish from the dishes list.
* Input:
*   id - ID of that want to delete
* Output:
*   returns none
*/
void Database::deleteDish(int id) {
    list<Dish>::iterator it;

    for (it = dishes.begin(); it != dishes.end(); it++) {
        if ((*it).getId() == id) {
            dishes.erase(it);
            cout << "Delete dish successfully." << endl;
            return;
        }
    }

    cout << "Not found ID." << endl;
}


/*
* Function: viewDishes
* Description: This function prints dishes list.
* Input:
*   none
* Output:
*   returns none
*/
void Database::viewDishes() const {
    cout << "Dishes list" << endl;
    cout << "No.\t|\tID\t|\tName\t\t|\tPrice" << endl;

    int i = 0;
    for (const auto& dish : dishes) {
        i++;
        cout << i << "\t|\t" << dish.getId() << "\t|\t" << dish.getName() << "\t|\t" << dish.getPrice() << endl;
    }
}


/*
* Function: setupTables
* Description: This function sets number of table to serve.
* Input:
*   numberOfTables - number of table to serve
* Output:
*   returns none
*/
void Database::setupTables(int numberOfTables)
{

    for (int i = 0; i < numberOfTables; i++) {
        Table table;
        tables.push_back(table);
    }
}


/*
* Function: getTable
* Description: This function gets table based on its ID.
* Input:
*   tableId - ID of table that want to get.
* Output:
*   returns table 
*/
Table* Database::getTable(int tableId)
{
    for (auto &table: tables) {
        if (table.getTableId() == tableId) {
            return &table;
        }
    }
    return nullptr;
}


/*
* Function: viewTableList
* Description: This function prints a list of tables and its status (serving or empty).
* Input:
*   none
* Output:
*   returns none
*/
void Database::viewTableList() {
    cout << "Table: \t\t";

    vector<Table>::size_type i;
    for (i = 0; i < tables.size(); i++) {
        cout << tables[i].getTableId() << "\t";
    }
    cout << endl;

    cout << "Status:\t\t";
    for (i = 0; i < tables.size(); i++) {
        cout << (tables[i].getTableStatus() == SERVING ? "X" : "O") << "\t";
    }
    cout << endl << endl;
    cout << "X: Serving" << endl;
    cout << "O: Empty" << endl;
}


/*
* Function: orderDish
* Description: This function adds dish to the order list.
* Input:
*   table - table that want to order dish
*   dishId - ID of dish that want to order
* Output:
*   returns none
*/
void Database::orderDish(Table* table, int dishId) {
    int quantity;

    for (const auto &dish : dishes) {
        if (dish.getId() == dishId) {
            cout << "ID\t|\tName\t\t|\tPrice" << endl;
            cout << dish.getId() << "\t|\t" << dish.getName() << "\t|\t" << dish.getPrice() << endl << endl;

            cout << "-------------------------------------------" << endl;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "ID\t|\tName\t\t|\tPrice\t|\tQuantity" << endl;
            cout << dish.getId() << "\t|\t" << dish.getName() << "\t|\t" << dish.getPrice() << "\t|\t" << quantity << endl << endl;

            table->orderDish(dish, quantity);
            if (table->getTableStatus() != SERVING) {
                table->setTableStatus(SERVING);
            }

            cout << "Dish ordered successfully." << endl;
            return; 
        }
    }

    cout << "Not found dish with this ID." << endl;
}


/*
* Function: cancelDish
* Description: This function cancels dish in the order list.
* Input:
*   table - table that want to cancel dish
*   dishId - ID of dish that want to cancel   
* Output:
*   returns none
*/
void Database::cancelDish(Table* table, int dishId) {

    for (const auto &dish : dishes) {
        if (dish.getId() == dishId) {
            table->cancelDish(dishId);
            return;
        }
    }

    cout << "Not found dish with this ID." << endl;

}


/*
* Function: changeDish
* Description: This function changes dish in the order list.
* Input:
*   table - table that want to change dish
*   oldId - ID of dish that want to change
* Output:
*   returns 
*/
void Database::changeDish(Table* table, int oldId) {
    int newId;

    for (const auto &dish : dishes) {
        if (dish.getId() == oldId) {
            table->changeDish(oldId);
            cout << "-------------------------------------------" << endl;    
            viewDishes();
            cout << "-------------------------------------------" << endl;    
            cout << "Please enter new dish ID to change: ";
            cin >> newId;
            orderDish(table, newId);
            return;
        }
    }

    cout << "Not found dish with this ID." << endl;
}


/*
* Function: viewOrderedDishes
* Description: This function prints a list of ordered dishes.
* Input:
*   table - table that want to view list
* Output:
*   returns none
*/
void Database::viewOrderedDishes(Table* table) const {
    table->viewOrderedDishes(table);
}


/*
* Function: pay
* Description: This function displays payment information of a table.
* Input:
*   table - table that want to pay   
* Output:
*   returns none
*/
void Database::pay(Table* table) {
    double subTotal = table->getSubTotal();

    cout << "Sub total: " << subTotal << " VND" << endl;
    cout << "VAT: 10%" << endl;
    cout << "Total: " << subTotal * 1.1 << " VND" << endl;

}