/*
* File: table.cpp   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file stores table information.
*/

#include <iostream>
#include "table.h"

using namespace std;

/*
* Function: Table
* Description: This constructor initializes the initial information about a Table object.
* Input:
*   none
* Output:
*   returns Table object
*/
Table::Table() : status(EMPTY) {
    static int id = 1;
    this->tableId = id;
    id++;
}


/*
* Function: getTableId
* Description: This function gets table ID.
* Input:
*   none
* Output:
*   returns table ID
*/
int Table::getTableId() const {
    return tableId;
}


/*
* Function: getTableStatus
* Description: This function gets table status (serving or empty).
* Input:
*   none
* Output:
*   returns table status
*/
TableStatus Table::getTableStatus() const {
    return status;
}


/*
* Function: setTableStatus
* Description: This function sets status of a table.
* Input:
*   status - status of table that want to set
* Output:
*   returns none
*/
void Table::setTableStatus(TableStatus status) {
    this->status = status;
}


/*
* Function: orderDish
* Description: This function adds dish to the order list.
* Input:
*   dish - dish that want to add to order dish
*   quantity - quantity of this dish 
* Output:
*   returns none
*/
void Table::orderDish(const Dish &dish, int quantity) {
    bool dishStatus = false;    

    for (auto &orderDish : orderList) {
        if (orderDish.first.getId() == dish.getId()) {
            orderDish.second += quantity;
            dishStatus = true;
            break;
        } 
    }

    if (!dishStatus) {
        orderList.push_back({dish, quantity});
    }

}


/*
* Function: cancelDish
* Description: This function cancels dish in the order list. 
* Input:
*   dishId - ID of dish that want to cancel 
* Output:
*   returns 
*/
void Table::cancelDish(int dishId) {
    int cancelQuantity;

    for (auto &orderDish : orderList) {
        if (orderDish.first.getId() == dishId) {
            cout << "\t|\t" << orderDish.first.getId() << "\t|\t" << orderDish.first.getName() << "\t|\t" 
                << orderDish.first.getPrice() << "\t|\t" << orderDish.second << endl;

            cout << "-------------------------------------------" << endl;

            enter_quantity_to_cancel:
            cout << "Enter quantity to cancel: ";
            cin >> cancelQuantity;  

            if (orderDish.second >= cancelQuantity) {
                orderDish.second -= cancelQuantity;
                cout << "Dish cancelled successfully." << endl;
            } else {
                cout << "Invalid cancel quantity. Please try again." << endl;
                goto enter_quantity_to_cancel;
            }
            break;
        } 
    }

    
}


/*
* Function: viewOrderedDishes
* Description: This function prints a list of ordered dishes.
* Input:
*   table - table that want to view list
* Output:
*   returns none
*/
void Table::viewOrderedDishes(Table* table) const {
    if (orderList.empty()) {
        cout << "No dishes ordered for table " << table->getTableId() << "." << endl;
        return;
    }

    cout << "Ordered dishes for table " << table->getTableId() << ":" << endl;
    cout << "No\t|\tID\t|\tName\t\t|\tPrice\t|\tQuantity" << endl;

    int i = 0;
    for (const auto &orderDish : orderList) {
        i++;
        cout << i << "\t|\t" << orderDish.first.getId() << "\t|\t" << orderDish.first.getName() 
             << "\t|\t" << orderDish.first.getPrice() << "\t|\t" << orderDish.second << endl;
    }
}


/*
* Function: changeDish
* Description: This function changes dish in the order list.
* Input:
*   oldId - ID of dish that want to change
* Output:
*   returns 
*/
void Table::changeDish(int oldId) {
    list<pair<Dish, int>>::iterator it;

    for (it = orderList.begin(); it != orderList.end(); it++) {
        if ((*it).first.getId() == oldId) {
            cout << "\t|\t" << (*it).first.getId() << "\t|\t" << (*it).first.getName() << "\t|\t" 
                << (*it).first.getPrice() << "\t|\t" << (*it).second << endl;
            
            orderList.erase(it);

            break;
        }
    }
}


/*
* Function: clearOrder
* Description: This function clears order list of a table after pay bill.
* Input:
*   none
* Output:
*   returns none
*/
void Table::clearOrder() {
    orderList.clear();
}


/*
* Function: getSubTotal
* Description: This function get subtotal of a bill (not include VAT).
* Input:
*   none
* Output:
*   returns subtotal of the order list 
*/
double Table::getSubTotal() const {
    double subTotal = 0;

    for (const auto &order : orderList) {
        subTotal += order.first.getPrice() * order.second;
    }

    return subTotal;
}