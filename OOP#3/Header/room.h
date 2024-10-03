/*
* File: room.h
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file stores room information.
*/

#ifndef __ROOM_H
#define __ROOM_H

#include <string>
#include <list>

using namespace std;

typedef enum {
    UNAVAILABLE,
    AVAILABLE
} RoomStatus;

typedef struct {
    string guestName;
    string guestPhoneNumber;
    string checkInDate;
    string checkOutDate;
    string feedback;
} RoomHistory;

class Room {
private:
    int roomId;
    RoomStatus status;
    string guestName;       
    string guestPhoneNumber;      
    string checkInDate;
    list<RoomHistory> history;
    
public:
    Room(int id);

    int getFloor(int roomId) const;
    int getRoomId() const;
    void setRoomId(int id);
    RoomStatus getRoomStatus() const;
    void setRoomSatus(RoomStatus status);
    string getGuestName() const;
    void setGuestName(string name);
    string getGuestPhoneNumber() const;
    void setGuestPhoneNumber(string phoneNumber);
    string getCheckInDate() const;
    void setCheckInDate(string date);

    void bookRoom();
    void checkOutRoom(string checkOutDate, string feedback);
    void displayRoomInformation() const;
};

#endif /* __ROOM_H */