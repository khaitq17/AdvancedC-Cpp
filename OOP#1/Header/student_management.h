/*
* File: student_management.h
* Author: Tran Quang Khai
* Date: 01/09/2024
* Description: This file includes operations to change information in the student management list.
*/

#ifndef __STUDENT_MANAGEMENT_H
#define __STUDENT_MANAGEMENT_H

#include <list>
#include "student.h"

using namespace std;

typedef enum {
    NAME,
    ID,
    AGE,
    GENDER,
    MATHSCORE,
    PHYSICSSCORE,
    CHEMISTRYSCORE,
    AVERAGESCORE
} Option;

void addStudent(list<Student> &database);
void printInformationOf1Student(Student student);
void modifyStudentInformation(list<Student> &database, Option information, string targetId);
void deleteStudent(list<Student> &database, string targetId);
void searchByName(const list<Student> &database, string nameToSearch);
void searchById(const list<Student> &database, string idToSearch);
void sortStudent(list<Student> &database, Option information);
void printStudentList(const list<Student> &database);
void listSearchByName(const list<Student> &database);
void updateCSV(list<Student> &database);

#endif /* __STUDENT_MANAGEMENT_H */