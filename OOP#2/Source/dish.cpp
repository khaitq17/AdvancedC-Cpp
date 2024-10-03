/*
* File: dish.cpp   
* Author: Tran Quang Khai
* Date: 06/09/2024
* Description: This file stores dish information.
*/

#include "dish.h"

using namespace std;

/*
* Function: Dish
* Description: This constructor initializes the initial information about a Dish object.
* Input:
*   name - dish name
*   price - dish unit price
* Output:
*   returns Dish object
*/
Dish::Dish(string name, double price) : name(name), price(price) {
    static int id = 2401;
    this->dishId = id;
    id++;
}


/*
* Function: getId
* Description: This function gets dish ID.
* Input:
*   none
* Output:
*   returns dish ID
*/
int Dish::getId() const {
    return dishId;
}

/*
* Function: getName
* Description: This function gets dish name.
* Input:
*   none
* Output:
*   returns dish name
*/
string Dish::getName() const {
    return name;
}


/*
* Function: getPrice
* Description: This function gets dish unit price
* Input:
*   none
* Output:
*   returns dish price
*/
double Dish::getPrice() const {
    return price;
}


/*
* Function: setPrice
* Description: This function sets new price of the dish.
* Input:
*   newPrice - new price that want to set for the dish
* Output:
*   returns none
*/
void Dish::setPrice(double newPrice) {
    this->price = newPrice;
}