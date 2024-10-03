#include <iostream>
#include <string>
#include "manager.h"
#include "employee.h"
#include "database.h"

using namespace std;

int main(){
    Manager manager;
    string account, password;

    while(1) {
        list<Employee> employeeList = Database::getInstance().getEmployeeList();

        cout << "------------------------------------------------" << endl;
        cout << "\t\tLogin information" << endl;
        cout << "Account (Username/Phone number): ";
        cin >> account;
        cout << "Password: ";
        cin >> password;

        bool found = false;
        if ((account == manager.getUsername() || account == manager.getPhoneNumber()) 
            && password == manager.getPassword()) {
            manager.menu();
            found = true;
        } else {
            for (auto &employee : employeeList) {
                if (account == employee.getPhoneNumber() && password == employee.getPassword()) {
                    employee.menu(employee.getId());
                    found = true;
                    break;
                }
            }
        }
        
        if (!found) {
            cout << "Account or password is not correct. Please try again." << endl;
        }
    }

    return 0;
}