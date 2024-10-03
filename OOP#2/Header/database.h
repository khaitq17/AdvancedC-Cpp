/*
* File: database.h   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file stores shared data for management and employees.
*/

#ifndef __DATABASE_H
#define __DATABASE_H

#include <vector>
#include <list>
#include "dish.h"
#include "table.h"


using namespace std;


class Database {
private:
    list<Dish> dishes;
    vector<Table> tables;
    Database() {}   // private constructor for singleton pattern

public:
    static Database &getInstance();

    // Manager
    void addDish(const Dish& dish);
    void editDish(int id);
    void deleteDish(int id);
    void viewDishes() const;

    // Table
    void setupTables(int numberOfTables);
    Table* getTable(int tableId);
    void viewTableList();

    // Employee
    void orderDish(Table* table, int dishId);
    void cancelDish(Table* table, int dishId);
    void changeDish(Table* table, int oldId);
    void viewOrderedDishes(Table* table) const;
    void pay(Table* table);
};

#endif /* __DATABASE_H */