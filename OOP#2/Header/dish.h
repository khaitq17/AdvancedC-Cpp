/*
* File: dish.h   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file stores dish's information.
*/

#ifndef __DISH_H
#define __DISH_H

#include <iostream>
#include <string>

using namespace std;

class Dish {
private:
    int dishId;
    string name;
    double price;

public:
    Dish(string name, double price); 

    int getId() const;
    string getName() const;
    double getPrice() const;
    void setPrice(double newPrice);
};

#endif /* __DISH_H */