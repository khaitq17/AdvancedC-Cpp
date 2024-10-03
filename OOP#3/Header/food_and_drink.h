/*
* File: food_and_drink.h
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores food and drink information.
*/

#ifndef __FOOD_AND_DRINK_H
#define __FOOD_AND_DRINK_H

#include <string>

using namespace std;

class FoodAndDrink {
private:
    string name;
    int id;
    double price;

public:
    FoodAndDrink(string name, double price);

    string getName() const;
    int getId() const;
    double getPrice() const;
    void setPrice(double newPrice); 

};

#endif /* __FOOD_AND_DRINK_H */