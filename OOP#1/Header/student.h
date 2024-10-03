/*
* File: student.h
* Author: Tran Quang Khai
* Date: 01/09/2024
* Description: This file includes properties and methods about student information. 
*/

#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef enum {
    FEMALE,
    MALE
} Gender;

/*
* Class: Student
* Description: This class contains basic properties and methods of the Student object.
*/
class Student {
private:
    string name;
    int age;
    Gender gender;
    string id;
    float mathScore;
    float physicsScore;
    float chemistryScore;

public:
    Student(string name, int age, Gender gender, string id, float math, float physics, float chemistry);

    string getName() const;
    void setName(string name);

    int getAge() const;
    void setAge(int age);

    Gender getGender() const;
    void setGender(Gender gender);

    string getId() const;
    void setId(string id);

    float getMathScore() const;
    void setMathScore(float mathScore);

    float getPhysicsScore() const;
    void setPhysicsScore(float physicsScore);

    float getChemistryScore() const;
    void setChemistryScore(float chemistryScore);

    float getAverageScore() const;

    string getRank() const;

};

#endif /* __STUDENT_H */