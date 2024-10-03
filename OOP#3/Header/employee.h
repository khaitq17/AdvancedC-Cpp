/*
* File: employee.h
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file includes menu and operations of the employees.
*/

#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <string>
#include <list>

using namespace std;
    
typedef enum {
    JANITOR,
    SECURITY,
    CHEF
} Position;

typedef enum {
    MONDAY = 2,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} WorkDay;

typedef enum {
    MORNING,
    AFTERNOON,
    EVENING
} Shift;

class Employee {
private:
    string name;
    int id;
    Position position;
    string phoneNumber;
    string password;
    list<pair<WorkDay, Shift>> shifts;

public:
    Employee(); 

    void menu(int id);

    string getName() const;
    int getId() const;
    string getPhoneNumber () const;
    Position getPosition() const;  
    string getPassword() const;
    void setName(string name);
    void setPhoneNumber(string newPhoneNumber);
    void setPosition(Position newPosition); 
    void setPassword(string newPassword); 
    void displayInformation() const;
    void setShiftsFromString(const string &input);
    void displayIndividualSchedule() const;
};

#endif /* __EMPLOYEE_H */