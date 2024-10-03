/*
* File: database.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores shared data for management and employees.
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "database.h"
#include "table.h"

using namespace std;

/*
* Function: getInstance
* Description: This function is responsible for ensuring that only one instance of the class is created during the lifetime of the program. 
* Input:
*   none
* Output:
*   returns new object if instance is null, else returns current object
*/
Database &Database::getInstance() {
    static Database instance;
    return instance;
}


/*
* Function: getEmployeeList
* Description: This function gets list of employees. 
* Input:
*   none
* Output:
*   returns list of employees
*/
list<Employee> Database::getEmployeeList() const {
    return employeeList;
}


/*
* Function: addEmployee
* Description: This function adds employee to the list of employees.
* Input:
*   name - employee name
*   position - employee position
*   phoneNumber - employee phone number
* Output:
*   returns none
*/
void Database::addEmployee(string name, Position position, string phoneNumber) {
    Employee employee;
    employee.setName(name);
    employee.setPosition(position);
    employee.setPhoneNumber(phoneNumber);
    employeeList.push_back(employee);
}


/*
* Function: editEmployeeInformation
* Description: This function edits position of an employee.
* Input:
*   id - employee ID
* Output:
*   returns none
*/
void Database::editEmployeeInformation(int id) {
    int positionSelect;

    for (auto &employee : employeeList) {
        if (employee.getId() == id) {
            displayEmployee(employee);

            select_position:
            cout << "Please select new position (1 - Janitor, 2 - Security, 3 - Chef): ";
            cin >> positionSelect;

            switch (positionSelect)
            {
            case 1: employee.setPosition(JANITOR); break; 

            case 2: employee.setPosition(SECURITY); break;
            
            case 3: employee.setPosition(CHEF); break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_position;
            }

            cout << "Edit position successfully." << endl;
            return;
        }
    }
    
    cout << "Not found ID." << endl;
}


/*
* Function: deleteEmployee
* Description: This function deletes an employee from the employee list.
* Input:
*   id - employee ID
* Output:
*   returns none
*/
void Database::deleteEmployee(int id) {
    list<Employee>::iterator it;
    for (it = employeeList.begin(); it != employeeList.end(); it++) {
        if ((*it).getId() == id) {
            employeeList.erase(it);
            cout << "Delete employee successfully." << endl;
            return;
        }  
    }

    cout << "Not found ID." << endl;
}


/*
* Function: setEmployeeShifts
* Description: This function sets shifts for an employee.
* Input:
*   id - employee ID
* Output:
*   returns none
*/
void Database::setEmployeeShifts(int id) {
    string formatString;
    for (auto &employee : employeeList) {
        if (employee.getId() == id) {   // 2-M,2-A,3-A,4-E,5-A,6-M
            cout << "Please enter the corresponding weekly work shifts in the following format (Day - Shift, Day - Shift, ...): ";  
            cin >> formatString;

            employee.setShiftsFromString(formatString); 

            cout << "Set shifts for employee " << employee.getName() << " successfully." << endl;
            return;
        }
    }

    cout << "Not found ID." << endl;
}


/*
* Function: printEmployeeList
* Description: This function prints the list of employees.
* Input:
*   none
* Output:
*   returns none
*/
void Database::printEmployeeList() const {
    cout << "Employee list" << endl;
    cout << "No.\t|\tID\t|\tName\t|\tPhone number\t|\tPosition" << endl;

    int i = 0; string position;
    for (const auto &employee : employeeList) {
        i++;
        if (employee.getPosition() == JANITOR) {position = "Janitor";}
        if (employee.getPosition() == SECURITY) {position = "Security";}
        if (employee.getPosition() == CHEF) {position = "Chef";}
        cout << i << "\t|\t" << employee.getId() << "\t|\t" << employee.getName()
            << "\t|\t" << employee.getPhoneNumber() << "\t|\t" << position << endl;
    }
}


/*
* Function: displayEmployee
* Description: This function displays information of an employee.
* Input:
*   employee - employee that want to display information
* Output:
*   returns none
*/
void Database::displayEmployee(Employee employee) const {
    employee.displayInformation();
}


/*
* Function: printWorkSchedule
* Description: This function prints work schedule of all employees.
* Input:
*   none
* Output:
*   returns none
*/
void Database::printWorkSchedule() const {
    cout << "\t\t\t\tEmployee work schedule" << endl;
    cout << "+" << setw(COL_WIDTH) << setfill('-') << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" << "+" << endl;
         
    cout << "|" << center("Name", COL_WIDTH) 
         << "|" << center("Monday", COL_WIDTH) 
         << "|" << center("Tuesday", COL_WIDTH) 
         << "|" << center("Wednesday", COL_WIDTH) 
         << "|" << center("Thursday", COL_WIDTH) 
         << "|" << center("Friday", COL_WIDTH) << "|" << endl;
         
    cout << "+" << setw(COL_WIDTH) << setfill('-') << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" << "+" << endl;

    for (const auto &employee : employeeList) {
        employee.displayIndividualSchedule();
    }

}


/*
* Function: addRoom
* Description: This function adds room to the room list.
* Input:
*   id - room ID
* Output:
*   returns none
*/
void Database::addRoom(int id) {
    Room room(id);
    Service service;
    roomList.push_back(make_pair(room, service));
}


/*
* Function: deleteRoom
* Description: This function deletes room from the room list.
* Input:
*   id - room ID
* Output:
*   returns none
*/
void Database::deleteRoom(int id) {
    vector<pair<Room, Service>>::iterator it;
    for (it = roomList.begin(); it != roomList.end(); it++) {
        if ((*it).first.getRoomId() == id) {
            roomList.erase(it);
            cout << "Delete room successfully." << endl;
            return;
        }
        
    }

    cout << "Not found room ID." << endl;
}


/*
* Function: sortRoomById
* Description: This function sorts rooms in the room list by ID.
* Input:
*   none
* Output:
*   returns none
*/
void Database::sortRoomById() {
    sort(roomList.begin(), roomList.end(), [](const pair<Room, Service>& a, const pair<Room, Service>& b) {
        return a.first.getRoomId() < b.first.getRoomId();
    });
}


/*
* Function: printRoomList
* Description: This function prints the list of rooms and its status for the manager.
* Input:
*      none
* Output:
*   returns none
*/
void Database::printRoomList() {
    sortRoomById();
    
    vector<pair<Room, Service>> roomsInAFloor;

    for (int i = 1; i <= MAX_FLOOR; i++) {

        for (const auto &room : roomList) {
            int id = room.first.getRoomId();

            if (room.first.getFloor(id) == i) {
                roomsInAFloor.push_back(room);
            }
        }
        
        // Print room list in floor i 
        cout << "Floor " << i << ":" << endl;
        for (const auto &room : roomsInAFloor) {
            cout << "\t" << room.first.getRoomId();
        }
        cout << endl;

        for (const auto &room : roomsInAFloor) {
            cout << "\t" << (room.first.getRoomStatus() == AVAILABLE ? "A" : "U");
        }
        cout << endl;

        roomsInAFloor.clear();
    }
    cout << endl;
    cout << "U: Unavailable" << endl;
    cout << "A: Available" << endl;
}


/*
* Function: viewRoomInformation
* Description: This function displays information of a room.
* Input:
*   id - rooom ID
* Output:
*   returns none
*/
void Database::viewRoomInformation(int id) {
    for (const auto &room : roomList) {
        if (room.first.getRoomId() == id) {
            room.first.displayRoomInformation();
            return;
        }
    }

    cout << "Not found room ID." << endl;
}


/*
* Function: addItem
* Description: This function adds item to the food and drink menu.
* Input:
*   name - item name
*   price - item unit price
* Output:
*   returns 
*/
void Database::addItem(string name, double price) {
    FoodAndDrink item(name, price);

    foodAndDrinkMenu.push_back(item);
}


/*
* Function: deleteItem
* Description: This function dedletes item from the food and drink menu.
* Input:
*   id - ID of item that want to delete
* Output:
*   returns none
*/
void Database::deleteItem(int id) {
    list<FoodAndDrink>::iterator it;

    for (it = foodAndDrinkMenu.begin(); it != foodAndDrinkMenu.end(); it++) {
        if ((*it).getId() == id) {
            foodAndDrinkMenu.erase(it);
            cout << "Delete " << (*it).getName() << " successfully." << endl;
            return;
        }
    }

    cout << "Not found item ID." << endl;
}


/*
* Function: viewMenu
* Description: This function prints lthe list of the food and drink menu.
* Input:
*   none
* Output:
*   returns none 
*/
void Database::viewMenu() const {
    int i = 0;

    cout << "No.\t|\tID\t|\tName\t\t|\tPrice" << endl;

    for (const auto &item : foodAndDrinkMenu) {
        i++;
        cout << i << "\t|\t" << item.getId() << "\t|\t" << item.getName() << "\t|\t" << item.getPrice() << endl;
    }
}


/*
* Function: updatePrice
* Description: This function updates new price for an item.
* Input:
*   id - ID of item that want to update price
* Output:
*   returns none
*/
void Database::updatePrice(int id) {
    double newPrice;

    for (auto &item : foodAndDrinkMenu) {
        if (item.getId() == id) {
            cout << "ID\t|\tName\t\t|\tPrice" << endl;
            cout << item.getId() << "\t|\t" << item.getName() << "\t|\t" << item.getPrice() << endl << endl;

            cout << "Enter new price: ";
            cin >> newPrice;
            item.setPrice(newPrice);

            cout << "Update price successfully." << endl;
            return;
        }
    }

    cout << "Not found item ID." << endl;
}


/*
* Function: setSwimmingPoolPrice
* Description: This function sets price use swimming pool per an hour.
* Input:
*   newPrice - price want to set
* Output:
*   returns none
*/
void Database::setSwimmingPoolPrice(double newPrice) {
    for (auto &room : roomList) {
        room.second.setSwimmingPoolPrice(newPrice);
    }
}


/*
* Function: setGymPrice
* Description: This function sets price use gym per an hour.
* Input:
*   newPrice - price want to set
* Output:
*   returns none
*/
void Database::setGymPrice(double newPrice) {
    for (auto &room : roomList) {
        room.second.setGymPrice(newPrice);
    }
}


/*
* Function: setLaundryPrice
* Description: This function sets price use laundry per one time.
* Input:
*   newPrice - price want to set
* Output:
*   returns none
*/
void Database::setLaundryPrice(double newPrice) {
    for (auto &room : roomList) {
        room.second.setLaundryPrice(newPrice);
    }
}


/*
* Function: serviceCost
* Description: This function calculates cost of services that the guest used.
* Input:
*   roomId - ID of room that want to calculate service cost
* Output:
*   returns service cost
*/
double Database::serviceCost(int roomId) {
    for (const auto &room : roomList) {
        if (room.first.getRoomId() == roomId) {
            return room.second.serviceCost();
        }
    }

    return -1;
}


/*
* Function: parseDate
* Description: This function parses string of date and convert to date.
* Input:
*   date - string of date
* Output:
*   returns date
*/
tm Database::parseDate(const string &date) {
    tm tm = {};
    stringstream ss(date);
    ss >> get_time(&tm, "%d/%m/%Y");
    return tm;
}


/*
* Function: calculateDays
* Description: This function calculates rental days based on check in and check out date.
* Input:
*   checkIn - string of check in date
*   checkOut - string of check out date
* Output:
*   returns rental days
*/
int Database::calculateDays(const string& checkIn, const string& checkOut) {
    tm tmCheckIn = parseDate(checkIn);
    tm tmCheckOut = parseDate(checkOut);
    
    // Chuyen tm sang time_t
    time_t timeCheckIn = mktime(&tmCheckIn);
    time_t timeCheckOut = mktime(&tmCheckOut);
    
    // Tinh khoang thoi gian giua check-in va check-out
    auto difference = difftime(timeCheckOut, timeCheckIn);
    
    // Doi tu so giay sang so ngay
    return difference / (60 * 60 * 24);
}


/*
* Function: viewIndividualSchedule
* Description: This function displays the work schedule of an employee.
* Input:
*   id - employee ID
* Output:
*   returns none
*/
void Database::viewIndividualSchedule(int id) const {
    cout << "+" << setw(COL_WIDTH) << setfill('-') << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" << "+" << endl;
         
    cout << "|" << center("Name", COL_WIDTH) 
         << "|" << center("Monday", COL_WIDTH) 
         << "|" << center("Tuesday", COL_WIDTH) 
         << "|" << center("Wednesday", COL_WIDTH) 
         << "|" << center("Thursday", COL_WIDTH) 
         << "|" << center("Friday", COL_WIDTH) << "|" << endl;
         
    cout << "+" << setw(COL_WIDTH) << setfill('-') << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" << "+" << endl;
    // cout << "Name\t|\tMonday\t|\tTuesday\t|\tWednesday\t|\tThursday\t|\tFriday" << endl;
    // cout << "------------------------------------------------------" << endl;
    for (const auto &employee : employeeList) {
        if (employee.getId() == id) {
            employee.displayIndividualSchedule();
            break;
        }
    }
}


/*
* Function: editPassword
* Description: This function edits password of the employee.
* Input:
*   id - employee ID
* Output:
*   returns none
*/
void Database::editPassword(int id) {
    for (auto &employee : employeeList) {
        if (employee.getId() == id) {
            string currentPassword, newPassword;
            cout << "Enter current password: ";
            cin >> currentPassword;

            if (employee.getPassword() == currentPassword) {
                cout << "Enter new password: ";
                cin >> newPassword;
                employee.setPassword(newPassword);
                cout << endl << "Change password successfully." << endl;
                return;
            } else {
                cout << "Incorrect password." << endl;
            }

        }
    }
}


/*
* Function: editPhoneNumber
* Description: This function edits phone number of the employee.
* Input:
*   id - employee ID
* Output:
*   returns none
*/
void Database::editPhoneNumber(int id) {
    for (auto &employee : employeeList) {
        if (employee.getId() == id) {
            string currentPhoneNumber, newPhoneNumber;
            cout << "Enter current phone number: ";
            cin >> currentPhoneNumber;

            if (employee.getPhoneNumber() == currentPhoneNumber) {
                cout << "Enter new phone number: ";
                cin >> newPhoneNumber;
                employee.setPhoneNumber(newPhoneNumber);
                cout << endl << "Change phone number successfully." << endl;
                return;
            } else {
                cout << "Incorrect phone number." << endl;
            }

        }
    }
}


/*
 * Function: viewRoomStatus
 * Description: This function displays the list of rooms and its status for the employees.
 * Input:
 *  none
 * Output:
 *   returns none
 */
void Database::viewRoomStatus() {
    sortRoomById();
    
    vector<pair<Room, Service>> roomsInAFloor;

    for (int i = 1; i <= MAX_FLOOR; i++) {

        for (const auto &room : roomList) {
            int id = room.first.getRoomId();

            if (room.first.getFloor(id) == i) {
                roomsInAFloor.push_back(room);
            }
        }
        
        // Print room list in floor i 
        cout << "Floor " << i << ":" << endl;
        for (const auto &room : roomsInAFloor) {
            cout << "\t" << room.first.getRoomId();
        }
        cout << endl;

        for (const auto &room : roomsInAFloor) {
            cout << "\t" << (room.first.getRoomStatus() == AVAILABLE ? "O" : "X");
        }
        cout << endl;

        roomsInAFloor.clear();
    }
    cout << endl;
    cout << "X: In use" << endl;
    cout << "O: Empty" << endl;
}


/*
 * Function: bookRoom
 * Description: This function books room for the the guest.
 * Input:
 *  none
 * Output:
 *   returns none
 */
void Database::bookRoom() {
    int roomId;
    cout << "Please select room: ";
    cin >> roomId;

    for (auto &room : roomList) {
        if (room.first.getRoomId() == roomId) {
            room.first.bookRoom();
            return;
        }
    }

    cout << "Not found room ID." << endl;
}


/*
 * Function: checkOutRoom
 * Description: This function checks out room for the guest.
 * Input:
 *  none
 * Output:
 *   returns none
 */
void Database::checkOutRoom() {
    string phoneNumber;
    cout << "Please enter guest phone number: ";
    cin >> phoneNumber;

    for (auto &room : roomList) {
        if (room.first.getGuestPhoneNumber() == phoneNumber) {
            string checkOutDate, feedback;

            cout << "Guest information: " << endl;
            cout << "Name: " << room.first.getGuestName() << endl;
            cout << "Phone number: " << room.first.getGuestPhoneNumber() << endl;
            cout << "Room: " << room.first.getRoomId() << endl;
            cout << "Check-in date: " << room.first.getCheckInDate() << endl;
            cout << "Please enter check-out date: ";
            cin >> checkOutDate;

            string checkInDate = room.first.getCheckInDate();
            int rentalDays = calculateDays(checkInDate, checkOutDate);
            double rentalUnitPrice = 200000;
            double totalServiceCost = rentalUnitPrice * rentalDays + serviceCost(room.first.getRoomId());

            cout << "Service used: " << endl;
            cout << "Service name\t|\tUnit price\t|\tQuantity" << endl;
            cout << "Rental time\t|\t" << rentalUnitPrice << "\t|\t" << rentalDays << endl;
            cout << "Total service cost: " << totalServiceCost << " VND" << endl;
            cout << "VAT: 10%" << endl;
            cout << "Total amount: " << totalServiceCost * 1.1 << " VND" << endl << endl;

            cout << "Feedback: ";
            cin.ignore();
            getline(cin, feedback);
            
            room.first.checkOutRoom(checkOutDate, feedback);
            
            cout << "Check-out room successfully." << endl;
            return;
        }
    }

    cout << "Not found phone number." << endl;
    
}