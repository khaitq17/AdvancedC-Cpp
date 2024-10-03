/*
* File: employee.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file includes menu and operations of the employees.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "employee.h"
#include "database.h"
#include "table.h"

using namespace std;

/*
 * Function: Employee
 * Description: This function initializes the initial information of an employee.
 * Input:
 *  none
 * Output:
 *   returns a new employee
 */
Employee::Employee() {    
    static int id = 1;
    this->id = id;
    id++;
    
    this->password = "123456";
}


/*
 * Function: menu
 * Description: This function includes menu and operations of an employee.
 * Input:
 *  employeeId - employeeID
 * Output:
 *   returns none
 */
void Employee::menu(int employeeId) {
    int choice, choiceInCase, select;

    do
    {
        employee_menu:
        cout << "------------------------------------------------" << endl;
        cout << "\t\tEMPLOYEE" << endl;
        cout << "1. View my shift" << endl;
        cout << "2. Edit information" << endl;
        cout << "3. Book room" << endl;
        cout << "4. Checkout room" << endl;
        cout << "5. View room list" << endl;
        cout << "0. Return" << endl;
        cout << "Please enter your choice: "; 
        cin >> choice;

        switch (choice)
        {
        case 1: // View my shift
        {
            cout << "------------------------------------------------" << endl;
            cout << "\t\tView my shift" << endl;
            Database::getInstance().viewIndividualSchedule(employeeId);
            cout << "------------------------------------------------" << endl;
            select_after_view_shedule:
            cout << "0. Return" << endl;
            cout << "Please enter 0 to return" << endl;
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_view_shedule;
            }

            break;
        }


        case 2: // Edit information
        {
            edit_information:
            cout << "------------------------------------------------" << endl;
            cout << "\t\tEdit information" << endl;
            cout << "1. Edit password" << endl;
            cout << "2. Edit phone number" << endl;
            cout << "0. Return" << endl;
            cout << "Please enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Edit password
            {
                edit_password:
                cout << "------------------------------------------------" << endl;
                cout << "\t\tEdit password" << endl;
                Database::getInstance().editPassword(employeeId);
                cout << "------------------------------------------------" << endl;
                select_after_edit_password:
                cout << "1. Continue edit information" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1:
                    goto edit_password;

                case 0:
                    break;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_edit_password;
                }

                break;
            }

            case 2: // Edit phone number
            {
                edit_phone_number:
                cout << "------------------------------------------------" << endl;
                cout << "\t\tEdit phone number" << endl;
                Database::getInstance().editPhoneNumber(employeeId);
                cout << "------------------------------------------------" << endl;
                select_after_edit_phone_number:
                cout << "1. Continue edit information" << endl;
                cout << "0. Return" << endl;
                cout << "Please enter your choice: ";
                cin >> select;

                switch (select)
                {
                case 1:
                    goto edit_phone_number;

                case 0:
                    break;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    goto select_after_edit_phone_number;
                }

                break;
            }

            case 0:
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                goto edit_information;
            }
            break;
        }


        case 3: // Book room
        {
            cout << "------------------------------------------------" << endl;
            cout << "\t\tBook room" << endl;
            Database::getInstance().viewRoomStatus();
            cout << "------------------------------------------------" << endl;
            Database::getInstance().bookRoom();
            cout << "------------------------------------------------" << endl;
            select_after_book_room:
            cout << "0. Return" << endl;
            cout << "Please enter 0 to return" << endl;
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_book_room;
            }

            break;
        }


        case 4: // Checkout room
        {
            cout << "------------------------------------------------" << endl;
            cout << "\t\tCheck-out room" << endl;
            Database::getInstance().checkOutRoom();
            cout << "------------------------------------------------" << endl;
            select_after_checkout_room:
            cout << "0. Return" << endl;
            cout << "Please enter 0 to return" << endl;
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_checkout_room;
            }

            break;
        }


        case 5: // View room list
        {
            cout << "------------------------------------------------" << endl;
            cout << "\t\tView room list" << endl;
            Database::getInstance().viewRoomStatus();
            cout << "------------------------------------------------" << endl;
            select_after_view_room_list:
            cout << "0. Return" << endl;
            cout << "Please enter 0 to return" << endl;
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
                goto select_after_view_room_list;
            }

            break;
        }


        case 0: // Return
            break;


        default:
            cout << "Invalid choice. Please try again." << endl;
            goto employee_menu;
        }


    } while (choice != 0);
    
}


/*
 * Function: getName
 * Description: This function gets employee name.
 * Input:
 *  none
 * Output:
 *   returns employee name
 */
string Employee::getName() const {
    return name;
}

/*
 * Function: getId
 * Description: This function gets employee ID.
 * Input:
 *  none
 * Output:
 *   returns employee ID
 */
int Employee::getId() const {
    return id;
}


/*
 * Function: getPhoneNumber
 * Description: This function gets employee phone number.
 * Input:
 *  none
 * Output:
 *   returns employee phone number
 */
string Employee::getPhoneNumber() const {
    return phoneNumber;
}


/*
 * Function: getPosition
 * Description: This function gets employee position.
 * Input:
 *  none
 * Output:
 *   returns employee position
 */
Position Employee::getPosition() const {
    return position;
}


/*
 * Function: getPassword
 * Description: This function gets employee password.
 * Input:
 *  none
 * Output:
 *   returns employee password
 */
string Employee::getPassword() const {
    return password;
}


/*
 * Function: setName
 * Description: This function sets employee name.
 * Input:
 *  name - employee name
 * Output:
 *   returns none
 */
void Employee::setName(string name) {
    this->name = name;
}

/*
 * Function: setPhoneNumber
 * Description: This function sets employee phone number.
 * Input:
 *  newPhoneNumber - employee phone number
 * Output:
 *   returns none
 */
void Employee::setPhoneNumber(string newPhoneNumber) {
    this->phoneNumber = newPhoneNumber;
}


/*
 * Function: setPosition
 * Description: This function sets employee position.
 * Input:
 *  newPosition - employee position
 * Output:
 *   returns none
 */
void Employee::setPosition(Position newPosition) {
    this->position = newPosition;
}


/*
 * Function: setPassword
 * Description: This function sets employee password.
 * Input:
 *  newPassword - employee password
 * Output:
 *   returns none
 */
void Employee::setPassword(string newPassword) {
    this->password = newPassword;
}


/*
 * Function: displayInformation
 * Description: This function displays information of an employee.
 * Input:
 *  none
 * Output:
 *   returns none
 */
void Employee::displayInformation() const {
    cout << endl << "ID\t|\tName\t|\tPhone number\t|\tPosition" << endl;

    string _position;
    if (position == JANITOR) {_position = "Janitor";}
    if (position == SECURITY) {_position = "Security";}
    if (position == CHEF) {_position = "Chef";}

    cout << id << "\t|\t" << name << "\t|\t"
        << phoneNumber << "\t|\t" << _position << endl << endl; 
}


/*
 * Function: setShiftsFromString
 * Description: This function converts string of shifts that manager set to the shifts of an employee.
 * Input:
 *  input - string of shifts that want to convert
 * Output:
 *   returns none
 */
void Employee::setShiftsFromString(const string &input) {
    stringstream ss(input); // Phan tach cac phan cua chuoi input
    string pairStr; // Bien tam de luu tung cap WorkDay - Shift

    while (getline(ss, pairStr, ',')) {
        // Xoa khoang trang
        pairStr.erase(remove_if(pairStr.begin(), pairStr.end(), ::isspace), pairStr.end());

        // Tach ngay va ca lam viec
        size_t dashPos = pairStr.find('-'); // Tim vi tri '-' trong pairStr
        if (dashPos != string::npos) {
            int day = stoi(pairStr.substr(0, dashPos)); // string to int 
            char shiftChar = pairStr[dashPos + 1];

            WorkDay workDay;
            Shift shift;

            // Chuyen doi ngay
            switch (day) {
                case 2: workDay = MONDAY; break;
                case 3: workDay = TUESDAY; break;
                case 4: workDay = WEDNESDAY; break;
                case 5: workDay = THURSDAY; break;
                case 6: workDay = FRIDAY; break;
                default: continue;  // Bo qua neu ngay khong hop le
            }

            // Chuyen doi ca lam viec
            switch (shiftChar) {
                case 'M': shift = MORNING; break;
                case 'A': shift = AFTERNOON; break;
                case 'E': shift = EVENING; break;
                default: continue;  // Bo qua neu ca khong hop le
            }

                // Them vao danh sach shifts
                shifts.push_back(make_pair(workDay, shift));
            }
    }
}


/*
 * Function: displayIndividualSchedule
 * Description: This function displays work schedule of an employee.
 * Input:
 *  none
 * Output:
 *   returns none
 */
void Employee::displayIndividualSchedule() const {
    map<WorkDay, map<Shift, string>> workSchedule;
    Shift shiftsArray[] = {MORNING, AFTERNOON, EVENING};
    WorkDay days[] = {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};

    for (const auto& shift : shifts) {
        workSchedule[shift.first][shift.second] = (shift.second == MORNING ? "Morning" : (shift.second == AFTERNOON ? "Afternoon" : "Evening"));
    }

    

    // cout << "|" << center(col1, COL_WIDTH)
    //      << "|" << center(col2, COL_WIDTH)
    //      << "|" << center(col3, COL_WIDTH) << "|" << endl;
                    
    for (Shift shift : shiftsArray) {
            
        if (shift != AFTERNOON) {
            cout << "|" << center(" ", COL_WIDTH);
        } else {
            cout << "|" << center(name, COL_WIDTH);
        }

        for (WorkDay day : days) {
            if (workSchedule[day][shift] != "") {    
                cout << "|" << center(workSchedule[day][shift], COL_WIDTH);    
                workSchedule[day][shift] = ""; 
            } else {
                cout << "|" << center("X", COL_WIDTH);
            }
        }
        cout << "|" << endl;
    }
    cout << "+" << setw(COL_WIDTH) << setfill('-') << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" 
         << "+" << setw(COL_WIDTH) << "-" << "+" << endl;
}