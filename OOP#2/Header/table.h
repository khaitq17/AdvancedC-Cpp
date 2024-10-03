/*
* File: table.h   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file stores table information.
*/

#ifndef __TABLE_H
#define __TABLE_H

#include <vector>
#include <list>
#include "dish.h"

using namespace std;

typedef enum { 
    EMPTY,
    SERVING
} TableStatus;

class Table {
private:
    int tableId;
    TableStatus status;
    list<pair<Dish, int>> orderList;    // <Dish, quantity>

public:

    Table();

    int getTableId() const;
    TableStatus getTableStatus() const;
    void setTableStatus(TableStatus status);
    void orderDish(const Dish& dish, int quantity);
    void cancelDish(int dishId);
    void viewOrderedDishes(Table* table) const;
    void changeDish(int oldId);
    void clearOrder();
    double getSubTotal() const;
};

#endif /* __TABLE_H */