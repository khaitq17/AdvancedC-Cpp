/*
* File: manager.h   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file includes menu and operations of the manager.
*/

#ifndef __MANAGER_H
#define __MANAGER_H

#include <list>
#include "table.h"
#include "dish.h"

using namespace std;

class Manager {  
private:
    void setupTables();
    void addDish();
    void editDish();
    void deleteDish();
    void viewDishes() const;
    void printDishInformation(Dish dish);

public:
    void menu();
    
};

#endif /* __MANAGER_H */