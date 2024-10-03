/*
* File: table.cpp
* Author: Tran Quang Khai
* Date: 12/09/2023
* Description: This file includes functions to create table.
*/

#include "table.h"

using namespace std;

/*
* Function: center
* Description: This function aligns the string in the center of the column.
* Input:
*   str - string that want to align in the center
*   width - column width
* Output:
*   returns string aligned in the center of the column
*/
string center(const string& str, int width) {
    int padding = width - str.size();
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return string(padLeft, ' ') + str + string(padRight, ' ');
}