/*
* File: service.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores service information.
*/

#include <iostream>
#include "service.h"

using namespace std;

/*
* Function: Service
* Description: This function initializes the initial information of the services.
* Input:
*   none
* Output:
*   returns service information
*/
Service::Service() {
    this->swimmingPoolUsedTime = 0;
    this->gymUsedTime = 0;
    this->laundryUsedTime = 0;
}


/*
* Function: getSwimmingPoolUsedTime
* Description: This function gets the hours that the guest used swimming pool.
* Input:
*   none
* Output:
*   returns hours used swimming pool
*/
int Service::getSwimmingPoolUsedTime() const {
    return swimmingPoolUsedTime;
}


/*
* Function: getSwimmingPoolPrice
* Description: This function gets price use swimming pool per an hour.
* Input:
*   none
* Output:
*   returns price use swimming pool per an hour
*/
double Service::getSwimmingPoolPrice() const {
    return swimmingPoolPrice;
}


/*
* Function: getGymUsedTime
* Description: This function gets the hours that the guest used gym.
* Input:
*   none
* Output:
*   returns hours used gym
*/
int Service::getGymUsedTime() const {
    return gymUsedTime;
}


/*
* Function: getGymPrice
* Description: This function gets price use gym per an hour.
* Input:
*   none
* Output:
*   returns price use gym per an hour 
*/
double Service::getGymPrice() const {
    return gymPrice;
}


/*
* Function: getLaundryUsedTime
* Description: This function gets the times that the guest used laundry.
* Input:
*   none
* Output:
*   returns times that the guest used laundry
*/
int Service::getLaundryUsedTime() const {
    return laundryUsedTime; 
}


/*
* Function: getLaundryPrice
* Description: This function gets price use laundry per one time.
* Input:
*   none
* Output:
*   returns price use laundry per one time
*/
double Service::getLaundryPrice() const {
    return laundryPrice;
}



/*
* Function: setSwimmingPoolUsedTime
* Description: This function sets the hours that the guest used swimming pool.
* Input:
*   hour - hours that the guest used swimming pool
* Output:
*   returns none
*/
void Service::setSwimmingPoolUsedTime(int hour) {
    this->swimmingPoolUsedTime = hour;
}


/*
* Function: setSwimmingPoolPrice
* Description: This function sets price use swimming pool per an hour.
* Input:
*   newPrice - price use swimming pool per an hour
* Output:
*   returns none
*/
void Service::setSwimmingPoolPrice(double newPrice) {
    this->swimmingPoolPrice = newPrice;
}


/*
* Function: setGymUsedTime
* Description: This function sets the hours that the guest used gym.
* Input:
*   hour - hours that the guest used gym
* Output:
*   returns none
*/
void Service::setGymUsedTime(int hour) {
    this->gymUsedTime = hour;
}


/*
* Function: setGymPrice
* Description: This function sets price use gym per an hour.
* Input:
*   newPrice - price use gym per an hour
* Output:
*   returns none
*/
void Service::setGymPrice(double newPrice) {
    this->gymPrice = newPrice;
}


/*
* Function: setLaundryUsedTime
* Description: This function sets the times that the guest used laundry.
* Input:
*   time - times that the guest used laundry
* Output:
*   returns none
*/
void Service::setLaundryUsedTime(int time) {
    this->laundryUsedTime = time;
}


/*
* Function: setLaundryPrice
* Description: This function sets price use laundry per one time.
* Input:
*   newPrice - price use laundry per one time
* Output:
*   returns none
*/
void Service::setLaundryPrice(double newPrice) {
    this->laundryPrice = newPrice;
}


/*
* Function: serviceCost
* Description: This function calculates cost of the service that the guest used.
* Input:
*   none
* Output:
*   returns none
*/
double Service::serviceCost() const {
    double cost = 0;

    cost += swimmingPoolUsedTime * swimmingPoolPrice;
    cost += gymUsedTime * gymPrice;
    cost += laundryUsedTime * laundryPrice;

    return cost;
}