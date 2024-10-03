/*
* File: manager.h
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file includes menu and operations of the manager.
*/

#ifndef __MANAGER_H
#define __MANAGER_H

#include <string>

using namespace std;

class Manager {
private:
    string username;
    string phoneNumber;
    string password;

public:
    Manager();

    void menu();

    string getUsername() const;
    string getPhoneNumber() const;
    string getPassword() const;
    void setUsername(string newUsername);
    void setPhoneNumber(string newPhoneNumber);
    void setPassword(string newPassword); 

    void addEmployee();
    void editEmployeeInformation();
    void deleteEmployee();
    void setEmployeeShifts();
    void viewEmployeeList();
    void viewEmployeeSchedule();

    void addRoom();
    void deleteRoom();
    void viewRoomList() const;
    void viewRoomInformation();

    void addItem();
    void deleteItem();
    void viewMenu();
    void updateItemPrice();
    void setSwimmingPoolPrice();
    void setGymPrice();
    void setLaundryPrice();
};

#endif /* __MANAGER_H */