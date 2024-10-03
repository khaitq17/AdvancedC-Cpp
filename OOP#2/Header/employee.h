/*
* File: employee.h   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file includes menu and operations of the employees. 
*/

#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "dish.h"
#include "table.h"
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    void orderDish(Table* table);
    void cancelDish(Table* table);
    void changeDish(Table* table);
    void viewOrderedDishes(Table* table);
    void pay(Table* table);

public:
    void menu();

};

#endif /* __EMPLOYEE_H */