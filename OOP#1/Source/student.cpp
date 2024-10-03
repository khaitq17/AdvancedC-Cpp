/*
* File: student.cpp
* Author: Tran Quang Khai
* Date: 01/09/2024
* Description: This file includes properties and methods about student information.
*/

#include "student.h"

using namespace std;

/*
* Function: Student
* Description: Constructor initializes information for students.
* Input:
*   name - student name
*   age - student age
*   gender - student gender
*   id - student id
*   mathScore - student's math score
*   physicsScore - student's physics score
*   chemistryScore - student's chemistry score
* Output:
*   returns none
*/
Student::Student(string name, int age, Gender gender, string id, float math, float physics, float chemistry) 
    : name(name), age(age), gender(gender), id(id), mathScore(math), physicsScore(physics), chemistryScore(chemistry) {}


/*
* Function: getName
* Description: This function gets the student name.
* Input:
*   none
* Output:
*   returns student name
*/
string Student::getName() const {
    return name;
}


/*
* Function: setName
* Description: This function sets the student name.
* Input:
*   name - student name
* Output:
*   returns none
*/
void Student::setName(string name) {
    this->name = name;
}


/*
* Function: getAge
* Description: This function gets the student age.
* Input:
*   none
* Output:
*   returns student age
*/
int Student::getAge() const {
    return age;
}


/*
* Function: setAge
* Description: This function sets the student age.
* Input:
*   age - student age
* Output:
*   returns none
*/
void Student::setAge(int age) {
    this->age = age;
}


/*
* Function: getGender
* Description: This function gets the student gender.
* Input:
*   none
* Output:
*   returns student gender
*/
Gender Student::getGender() const {
    return gender;
}


/*
* Function: setGender
* Description: This function sets the student gender.
* Input:
*   gender - student gender
* Output:
*   returns none
*/
void Student::setGender(Gender gender) {
    this->gender = gender;
}


/*
* Function: getId
* Description: This function gets the student id. 
* Input:
*   none
* Output:
*   returns id
*/
string Student::getId() const {
    return id;
}


/*
* Function: setId
* Description: This function sets the student id.
* Input:
*   id - student id
* Output:
*   returns none
*/
void Student::setId(string id) {
    this->id = id;
}


/*
* Function: getMathScore
* Description: This function gets the student's math score.
* Input:
*   none
* Output:
*   returns student's math score
*/
float Student::getMathScore() const {
    return mathScore;
}


/*
* Function: setMathScore
* Description: This function sets the student's math score.
* Input:
*   mathScore - student's math score
* Output:
*   returns none
*/
void Student::setMathScore(float mathScore) {
    this->mathScore = mathScore;
}


/*
* Function: getPhysicsScore
* Description: This function gets the student's physics score.
* Input:
*   none
* Output:
*   returns student's physics score
*/
float Student::getPhysicsScore() const {
    return physicsScore;
}


/*
* Function: setPhysicsScore
* Description: This function sets the student's physics score.
* Input:
*   physicsScore - student's physics score
* Output:
*   returns none
*/
void Student::setPhysicsScore(float physicsScore) {
    this->physicsScore = physicsScore;
}


/*
* Function: getChemistryScore
* Description: This function gets the student's chemistry score.
* Input:
*   none
* Output:
*   returns student's chemistry score
*/
float Student::getChemistryScore() const {
    return chemistryScore;
}


/*
* Function: setChemistryScore
* Description: This function sets the student's chemistry score. 
* Input:
*   chemistryScore - student's chemistry score
* Output:
*   returns none
*/
void Student::setChemistryScore(float chemistryScore) {
    this->chemistryScore = chemistryScore;
}


/*
* Function: getAverageScore
* Description: This function calculates and returns average score of 3 subjects Math, Physics, Chemistry.
* Input:
*   none
* Output:
*   returns average score
*/
float Student::getAverageScore() const {
    float avg = (mathScore + physicsScore + chemistryScore) / 3.0;
    return round(avg * 10) / 10.0f ;
}


/*
* Function: getRank
* Description: This function returns classification of the student based on average score.
* Input:
*   none
* Output:
*   returns student's rank 
*/
string Student::getRank() const {
    float avg = getAverageScore();

    if (avg >= 8) {
        return "Excellent";
    } else if (avg >= 6.5) {
        return "Good";
    } else if (avg >= 5) {
        return "Average";
    } else {
        return "Weak";
    }
} 