/*
* File: food_and_drink.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores food and drink information.
*/

#include "food_and_drink.h"

using namespace std;

/*
* Function: FoodAndDrink
* Description: This function initializes the initial information of an item.
* Input:
*   name - item name
*   price - item unit price
* Output:
*   returns a new item
*/
FoodAndDrink::FoodAndDrink(string name, double price) : name(name), price(price) {
    static int itemID = 2401;
    this->id = itemID;
    itemID++;
}


/*
* Function: getName
* Description: This function gets item name.
* Input:
*   none
* Output:
*   returns item name
*/
string FoodAndDrink::getName() const {
    return name;
}


/*
* Function: getId
* Description: This function gets item ID.
* Input:
*   none
* Output:
*   returns item ID
*/
int FoodAndDrink::getId() const {
    return id;
}


/*
* Function: getPrice
* Description: This function gets item price.
* Input:
*   none
* Output:
*   returns item price
*/
double FoodAndDrink::getPrice() const {
    return price;
}


/*
* Function: setPrice
* Description: This function sets item price.
* Input:
*   newPrice - item price 
* Output:
*   returns none
*/
void FoodAndDrink::setPrice(double newPrice) {
    this->price = newPrice;
}