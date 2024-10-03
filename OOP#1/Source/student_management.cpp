/*
* File: student_management.cpp
* Author: Tran Quang Khai
* Date: 01/09/2024
* Description: This file includes operations to change information in the student management list.
*/

#include <algorithm>
#include <fstream>
#include "student_management.h"

using namespace std;

/*
* Function: addStudent
* Description: This function adds new student into the list.
* Input:
*   database - list that stores information of students
*   student - student that want to add into the list 
* Output:
*   list after add new student
*   returns none
*/
void addStudent(list<Student> &database) {
    string name, id;
    int age;
    Gender gender;
    float mathScore, physicsScore, chemistryScore;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);

    cout <<"Enter student ID: ";
    getline(cin, id);

    cout << "Enter age: ";
    cin >> age;

    int genderChoice;
    do
    {
        cout << "Enter gender (0 - FEMALE, 1 - MALE): ";
        cin >> genderChoice;
        if (genderChoice == 0) {
            gender = FEMALE;
        } else if (genderChoice == 1) {
                gender = MALE;
        }
    } while (genderChoice != 0 && genderChoice != 1);
    
    math_input:
    cout << "Enter Math score: ";
    cin >> mathScore;
    if (mathScore < 0 || mathScore > 10) {
        cout << "Entered score is invalid. Please enter Math score again." << endl;
        goto math_input;
    }

    physics_input:
    cout << "Enter Physics score: ";
    cin >> physicsScore;
    if (physicsScore < 0 || physicsScore > 10) {
        cout << "Entered score is invalid. Please enter Physics score again." << endl;
        goto physics_input;
    }
    
    chemistry_input:
    cout << "Enter Chemistry score: ";
    cin >> chemistryScore;
    if (chemistryScore < 0 || chemistryScore > 10) {
        cout << "Entered score is invalid. Please enter Chemistry score again." << endl;
        goto chemistry_input;
    }

    Student sv(name, age, gender, id, mathScore, physicsScore, chemistryScore);
    database.push_back(sv);

    printInformationOf1Student(sv);
}


/*
* Function: printInformationOf1Student
* Description: This function prints information of a student.
* Input:
*   student - student that want to print information
* Output:
*   returns none
*/
void printInformationOf1Student(Student student) {
    cout << "---------------------------------------------" << endl;
    cout << "ID:\t\t" << student.getId() << endl;
    cout << "Name:\t\t" << student.getName() << endl;
    cout << "Age:\t\t" << student.getAge() << endl;
    cout << "Gender:\t\t" << (student.getGender() == FEMALE ? "Female" : "Male") << endl;
    cout << "\tMath score\t|\tPhysics score\t|\tChemistry score" << endl;
    cout << "\t" << student.getMathScore() << "\t\t|\t" << student.getPhysicsScore() << "\t\t|\t" << student.getChemistryScore() << endl;
    cout << "Average score: " << student.getAverageScore() << endl;
    cout << "Classification: " << student.getRank() << endl;
}


/*
* Function: modifyStudentInformation
* Description: This function modifies information of a student in the list.
* Input:
*   database - list that stores information of students
*   information - information of student that want to modify 
*   targetId - ID of student that want to modify
* Output:
*   list after modify student information
*   returns none
*/
void modifyStudentInformation(list<Student> &database, Option information, string targetId) {  

    switch (information)
    {
    case NAME:
    {
        cout << "\t\tModify name" << endl;
        cout << "Please enter name: ";

        string modifiedName;
        cin.ignore();
        getline(cin, modifiedName);

        for (auto &student : database) {
            if (student.getId() == targetId) {
                student.setName(modifiedName);
                break;
            }
        }
        break;
    }


    case AGE:
    {
        cout << "\t\tModify age" << endl;
        cout << "Please enter age: ";

        int modifiedAge;
        cin >> modifiedAge;

        for (auto &student : database) {
            if (student.getId() == targetId) {
                student.setAge(modifiedAge);
                break;
            }
        }
        break;
    }


    case GENDER:
    {
        cout << "\t\tModify gender" << endl;

        modify_gender:
        cout << "Please enter gender (0 - Female, 1 - Male): ";

        int genderChoice;
        cin >> genderChoice;

        for (auto &student : database) {
            if (student.getId() == targetId) {
                if (genderChoice == 0) {
                    student.setGender(FEMALE);
                    break;
                }
                if (genderChoice == 1) {
                    student.setGender(MALE);
                    break;
                }
                if (genderChoice != 0 && genderChoice != 1) {
                    cout << "Invalid selection. Please select again." << endl;
                    goto modify_gender;
                }
            }
        }
        break;
    }


    case MATHSCORE:
    {
        cout << "\t\tModify Math score" << endl;
        modify_math:
        cout << "Please enter Math score: ";

        float modifiedMathScore;
        cin >> modifiedMathScore;

        if (modifiedMathScore < 0 || modifiedMathScore > 10) {
            cout << "Entered score is invalid. Please enter Math score again." << endl;
            goto modify_math;
        }

        for (auto &student : database) {
            if (student.getId() == targetId) {
                student.setMathScore(modifiedMathScore);
                break;
            }
        }
        break;
    }


    case PHYSICSSCORE:
    {
        cout << "\t\tModify Physics score" << endl;
        modify_physics:
        cout << "Please enter Physics score: ";

        float modifiedPhysicsScore;
        cin >> modifiedPhysicsScore;

        if (modifiedPhysicsScore < 0 || modifiedPhysicsScore > 10) {
            cout << "Entered score is invalid. Please enter Physics score again." << endl;
            goto modify_physics;
        }

        for (auto &student : database) {
            if (student.getId() == targetId) {
                student.setPhysicsScore(modifiedPhysicsScore);
                break;
            }
        }
        break;
    }


    case CHEMISTRYSCORE:
    {
        cout << "\t\tModify Chemistry score" << endl;
        modify_chemistry:
        cout << "Please enter Chemistry score: ";

        float modifiedChemistryScore;
        cin >> modifiedChemistryScore;

        if (modifiedChemistryScore < 0 || modifiedChemistryScore > 10) {
            cout << "Entered score is invalid. Please enter Chemistry score again." << endl;
            goto modify_chemistry;
        }

        for (auto &student : database) {
            if (student.getId() == targetId) {
                student.setChemistryScore(modifiedChemistryScore);
                break;
            }
        }
        break;
    }
    

    default:
        break;
    }

}


/*
* Function: deleteStudent
* Description: This function deletes student from the list.
* Input:
*   database - list that stores information of students
*   targetId - ID of student that want to delete
* Output:
*   list after delete student information
*   returns none
*/
void deleteStudent(list<Student> &database, string targetId) {
    cout << "---------------------------------------------" << endl;

    list<Student>::iterator it;

    for (it = database.begin(); it != database.end(); it++) {
        if ((*it).getId() == targetId) {
            database.erase(it);
            cout << "Deleted successfully" << endl;
            return;
        }
    }

    cout << "Not found ID" << endl;

}


/*
* Function: searchByName
* Description: This function searches student by name in the list.
* Input:
*   database - list that stores information of students
*   nameToSearch - name of student that want to search
* Output:
*   student(s) that want to search
*   returns none
*/
void searchByName(const list<Student> &database, string nameToSearch) {
    list<Student> searchList;

    for (const auto &student : database) {
        if(student.getName() == nameToSearch) {
            searchList.push_back(student);
            break;
        }
    }

    if (!searchList.empty()) {
        printStudentList(searchList);
    } else {
        cout << "Not found student" << endl;
    }
}


/*
* Function: searchById
* Description: This function searches student by ID in the list.
* Input:
*   database - list that stores information of students
*   idToSearch - id of student that want to search
* Output:
*   student that want to search
*   returns none
*/
void searchById(const list<Student> &database, string idToSearch) {
    list<Student> searchList;

    for (const auto &student : database) {
        if(student.getId() == idToSearch) {
            searchList.push_back(student);
            break;
        }
    }

    if (!searchList.empty()) {
        printStudentList(searchList);
    } else {
        cout << "Not found student" << endl;
    }
}


/*
* Function: listSearchByName
* Description: This function prints the list of students that want to search by name.
* Input:
*   database - list that stores information of students
* Output:
*   list with the searched name will be printed
*   returns none
*/
void listSearchByName(const list<Student> &database) {
    list<Student> searchList;
    string nameToSearch;

    cout << "Enter student name: " << endl;
    getline(cin, nameToSearch);

    for (const auto &student : database) {
        if(student.getName() == nameToSearch) {
            searchList.push_back(student);
        }
    }

    cout << "---------------------------------------------" << endl;
    if (!searchList.empty()) {
        int i = 0;

        cout << "\tNo.\t|\tID\t\t|\tName" << endl;

        for (const auto &student : searchList) {
            i++;
            cout << "\t" << i << "\t|\t" << student.getId() << "\t|\t" << student.getName() << endl; 
        }
    } else {
        cout << "Not found student." << endl;
    }
}


/*
* Function: sortStudent
* Description: This function sorts student in ascending order in the list according to a specific information.
* Input:
*   database - list that stores information of students
*   information - list will be sorted by this information 
* Output:
*   list after sorted by a specific information
*   returns none
*/
void sortStudent(list<Student> &database, Option information) {
    switch (information)
    {
    case NAME:
        database.sort([](const Student &sv1, const Student &sv2) -> bool {
            return sv1.getName() < sv2.getName();
        });
        break;
    
    case ID:
        database.sort([](const Student &sv1, const Student &sv2) -> bool {
            return sv1.getId() < sv2.getId();
        });
        break;

    case MATHSCORE:
        database.sort([](const Student &sv1, const Student &sv2) -> bool {
            return sv1.getMathScore() < sv2.getMathScore();
        });
        break;

    case PHYSICSSCORE:
        database.sort([](const Student &sv1, const Student &sv2) -> bool {
            return sv1.getPhysicsScore() < sv2.getPhysicsScore();
        });
        break;
    
    case CHEMISTRYSCORE:
        database.sort([](const Student &sv1, const Student &sv2) -> bool {
            return sv1.getChemistryScore() < sv2.getChemistryScore();
        });
        break;

    case AVERAGESCORE:
        database.sort([](const Student &sv1, const Student &sv2) -> bool {
            return sv1.getAverageScore() < sv2.getAverageScore();
        });
        break;

    default:
        break;
    }
}


/*
* Function: printStudentList
* Description: This function prints the list of students.
* Input:
*   database - list that stores information of students
* Output:
*   list will be printed
*   returns none
*/
void printStudentList(const list<Student> &database) {
    int i = 0;
    cout << "\tNo.\t|\tID\t|\tName\t\t|\tGender\t|\tMath\t|\tPhysics\t|\tChemistry\t|\tAverage score\t|\tClassification\t" << endl;
    for (const auto &student : database) {
        i++;
        cout << "\t" << i << "\t|" 
            << "\t" << student.getId() << "\t|"
            << "\t" << student.getName() << "\t\t|" 
            << "\t" << (student.getGender() == FEMALE ? "Female" : "Male") << "\t|"
            << "\t" << student.getMathScore() << "\t|"
            << "\t" << student.getPhysicsScore() << "\t|"
            << "\t" << student.getChemistryScore() << "\t\t|"
            << "\t" << student.getAverageScore() << "\t\t|"
            << "\t" << student.getRank() << "\t" << endl;         
    }
}


/*
* Function: updateCSV
* Description: This function saves the list after modify into CSV file.
* Input:
*   database - list that stores information of students
* Output:
*   returns none
*/
void updateCSV(list<Student> &database) {
    ofstream outFile("database_sv.csv");
    
    if (outFile.is_open()) {
        outFile << "ID,Name,Age,Gender,MathScore,PhysicsScore,ChemistryScore,AverageScore,Classification" << endl;
        for (const auto &student : database) {
            outFile << student.getId() << "," 
                    << student.getName() << ","
                    << student.getAge() << ","
                    << (student.getGender() == FEMALE ? "Female" : "Male") << ","
                    << student.getMathScore() << ","
                    << student.getPhysicsScore() << ","
                    << student.getChemistryScore() << ","
                    << student.getAverageScore() << ","
                    << student.getRank() << "," << endl;
        }
        outFile.close();
        cout << "CSV file updated successfully." << endl;
    } else {
        cout << "Error opening \"database_sv.csv\"." << endl;
    }
}