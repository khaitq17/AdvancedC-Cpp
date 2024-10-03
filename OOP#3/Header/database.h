/*
* File: database.h
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores shared data for management and employees.
*/

#ifndef __DATABASE_H
#define __DATABASE_H

#include <list>
#include <vector>
#include "employee.h"
#include "room.h"
#include "service.h"
#include "food_and_drink.h"

using namespace std;

#define MAX_FLOOR 3 

class Database {
private:
    list<Employee> employeeList;
    vector<pair<Room, Service>> roomList;
    list<FoodAndDrink> foodAndDrinkMenu;
    Database() {}

public:
    static Database &getInstance();
    
    list<Employee> getEmployeeList() const; 

    // Manage employee
    void addEmployee(string name, Position position, string phoneNumber);
    void editEmployeeInformation(int id);
    void deleteEmployee(int id);
    void setEmployeeShifts(int id);
    void printEmployeeList() const;
    void displayEmployee(Employee employee) const;
    void printWorkSchedule() const;

    // Manage room 
    void addRoom(int id);
    void deleteRoom(int id);
    void sortRoomById();
    void printRoomList();
    void viewRoomInformation(int id);

    // Service
    void addItem(string name, double price);
    void deleteItem(int id);
    void viewMenu() const;
    void updatePrice(int id);
    void setSwimmingPoolPrice(double newPrice);
    void setGymPrice(double newPrice);
    void setLaundryPrice(double newPrice);
    double serviceCost(int roomId);
    tm parseDate(const string& date);
    int calculateDays(const string& checkIn, const string& checkOut);

    // Employee
    void viewIndividualSchedule(int id) const;
    void editPassword(int id);
    void editPhoneNumber(int id);
    void viewRoomStatus();
    void bookRoom();
    void checkOutRoom();
    
};

#endif /* __DATABASE_H */