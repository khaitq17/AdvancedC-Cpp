/*
* File: room.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores room information. 
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include "room.h"

using namespace std;

/*
* Function: Room
* Description: This function initializes the initial information of a room.
* Input:
*   id - room ID
* Output:
*   returns a new room
*/
Room::Room(int id) : roomId(id), status(AVAILABLE) {}


/*
* Function: getFloor
* Description: This function gets the floor based on the room ID.
* Input:
*   roomId - room ID
* Output:
*   returns floor ID
*/
int Room::getFloor(int roomId) const {
    return roomId / 100;
}


/*
* Function: getRoomId
* Description: This function gets room ID.
* Input:
*   none
* Output:
*   returns room ID
*/
int Room::getRoomId() const {
    return roomId;
}


/*
* Function: setRoomId
* Description: This function sets room ID.
* Input:
*   id - room ID
* Output:
*   returns none
*/
void Room::setRoomId(int id) {
    this->roomId = id;
}


/*
* Function: getRoomStatus
* Description: This function gets room status (Unavailable or Available).
* Input:
*   none
* Output:
*   returns room status
*/
RoomStatus Room::getRoomStatus() const {
    return status;
}


/*
* Function: setRoomSatus
* Description: This function sets room status.
* Input:
*   status - room status
* Output:
*   returns none
*/
void Room::setRoomSatus(RoomStatus status) {
    this->status = status;
}


/*
* Function: getGuestName
* Description: This function gets guest name.
* Input:
*   none
* Output:
*   returns guest name
*/
string Room::getGuestName() const {
    return guestName;
}


/*
* Function: setGuestName
* Description: This function sets guest name.
* Input:
*   name - guest name
* Output:
*   returns none
*/
void Room::setGuestName(string name) {
    this->guestName = name;
}


/*
* Function: getGuestPhoneNumber
* Description: This function gets guest phone number.
* Input:
*   none
* Output:
*   returns guest phone number
*/
string Room::getGuestPhoneNumber() const {
    return guestPhoneNumber;
}


/*
* Function: setGuestPhoneNumber
* Description: This function sets guest phone number.
* Input:
*   phoneNumber - guest phone number
* Output:
*   returns none
*/
void Room::setGuestPhoneNumber(string phoneNumber) {
    this->guestPhoneNumber = phoneNumber;
}


/*
* Function: getCheckInDate
* Description: This function gets guest's check in date.
* Input:
*   none
* Output:
*   returns check in date
*/
string Room::getCheckInDate() const {
    return checkInDate;
}


/*
* Function: setCheckInDate
* Description: This function sets guest's check in date.
* Input:
*   date - check in date
* Output:
*   returns none
*/
void Room::setCheckInDate(string date) {
    this->checkInDate = date;
}


/*
* Function: bookRoom
* Description: This function books room for the guest.
* Input:
*   none
* Output:
*   returns none
*/
void Room::bookRoom() {
    if (status == AVAILABLE) {
        string name, phoneNumber, checkInDate;
        cout << "Enter guest name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter phone number: ";
        cin >> phoneNumber;

        cout << "Enter check-in date: ";
        cin >> checkInDate;

        this->guestName = name;
        this->guestPhoneNumber = phoneNumber;
        this->checkInDate = checkInDate;
        this->status = UNAVAILABLE;

        cout << "Book room " << roomId << " successfully." << endl;
                
    } else {
        cout << "This room is unavailable now." << endl;
    }
}


/*
* Function: checkOutRoom
* Description: This function checks out room for the guest.
* Input:
*   checkOutDate - check out date
*   feedback - guest's feedback
* Output:
*   returns none
*/
void Room::checkOutRoom(string checkOutDate, string feedback) {
    RoomHistory record = {guestName, guestPhoneNumber, checkInDate, checkOutDate, feedback};
    history.push_back(record);

    // Reset room
    this->guestName = "";
    this->guestPhoneNumber = "";
    this->checkInDate = "";
    this->status = AVAILABLE;
}


/*
* Function: displayRoomInformation
* Description: This function displays information of a room.
* Input:
*   none
* Output:
*   returns none
*/
void Room::displayRoomInformation() const {
    cout << "Room " << roomId << ":" << endl;
    if (status == UNAVAILABLE) {
        cout << "Guest information: " << endl;
        cout << "Name: " << guestName << endl;
        cout << "Phone number: " << guestPhoneNumber << endl;
        cout << "Check in date: " << checkInDate << endl;
    } else {
        cout << "This room is available now." << endl;
    }

    cout << "Room history: " << endl;
    for (const auto &record : history) {
        cout << "Name: " << record.guestName << endl;
        cout << "Phone number: " << record.guestPhoneNumber << endl;
        cout << "Check in/check-out history: " << endl;
        cout << "Date\t\t\tCheck in/out" << endl;
        cout << record.checkInDate << "\t\tCheck in" << endl;
        cout << record.checkOutDate << "\t\tCheck out" << endl;
        cout << "Feedback: " << record.feedback << endl;
        cout << "----------------------------------------------" << endl;
    }

}