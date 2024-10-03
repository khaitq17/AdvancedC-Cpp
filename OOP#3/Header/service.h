/*
* File: service.h
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores service information.
*/

#ifndef __SERVICE_H
#define __SERVICE_H

#include <list>
#include "food_and_drink.h"

using namespace std;

class Service {
private:
    list<pair<FoodAndDrink, int>> orderList;   // <food&drink, quantity>
    int swimmingPoolUsedTime;   // per hour
    double swimmingPoolPrice;
    int gymUsedTime;    // per hour
    double gymPrice;
    int laundryUsedTime;    // per time
    double laundryPrice;

public:
    Service();

    int getSwimmingPoolUsedTime() const;
    double getSwimmingPoolPrice() const;
    int getGymUsedTime() const;
    double getGymPrice() const;
    int getLaundryUsedTime() const;
    double getLaundryPrice() const;

    void setSwimmingPoolUsedTime(int hour);
    void setSwimmingPoolPrice(double newPrice);
    void setGymUsedTime(int hour);
    void setGymPrice(double newPrice);
    void setLaundryUsedTime(int time);
    void setLaundryPrice(double newPrice);

    double serviceCost() const;

};

#endif /* __SERVICE_H */