#include <iostream>
#include "student_management.h"

using namespace std;

int main(){
    list<Student> database;

    static int choice = 0;
    do
    {
        cout << "---------------------------------------------" << endl;
        cout << "\t\t\tSTUDENT MANAGEMENT SYSTEM" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Modify student information" << endl;
        cout << "3. Delete student" << endl;
        cout << "4. Search student" << endl;
        cout << "5. Sort student" << endl;
        cout << "6. Print student list" << endl;
        cout << "7. Save into file \"database_sv.csv\"" << endl;
        cout << "0. Exit" << endl;

        cout << "Please enter your choice: ";
        cin >> choice;

        int choiceInCase;
        int selection;
        string nameToSearch;
        string idToSearch;

        switch (choice)
        {
        case 1: // Add student
        {    
            cout << "---------------------------------------------" << endl;
            cout << "\t\tAdd student" << endl;
            add_student_selection:
            addStudent(database);
            cout << "---------------------------------------------" << endl;
            cout << "1. Add another student" << endl;
            cout << "0. Return" << endl;
            cout << "Enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Add another student
                goto add_student_selection;
            
            case 0: // Return
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto add_student_selection;
            }
            break;
        }


        case 2: // Modify student information
        {   
            modify_student_information:
            cout << "---------------------------------------------" << endl;
            cout << "\t\tModify student information" << endl;

            cout << "Enter student name: ";
            
            cin.ignore();
            getline(cin, nameToSearch);
            searchByName(database, nameToSearch);

            
            cout << "Please enter the student ID you want to modify information: ";  
            cin >> idToSearch;

            for (const auto &student : database) {
                if (student.getId() == idToSearch) {
                    printInformationOf1Student(student);
                    break;
                } else {
                    cout << "Not found student" << endl;
                    goto modify_student_information;
                }
            }

            modify_selection:
            cout << "---------------------------------------------" << endl;
            cout << "1. Modify name" << endl;
            cout << "2. Modify age" << endl;
            cout << "3. Modify gender" << endl;
            cout << "4. Modify Math score" << endl;
            cout << "5. Modify Physics score" << endl;
            cout << "6. Modify Chemistry score" << endl;
            cout << "0. Return" << endl;

            cout << "Enter your choice: ";
            cin >> choiceInCase;
            
            cout << "---------------------------------------------" << endl;

            switch (choiceInCase)
            {
            case 1: // Modify name
                modifyStudentInformation(database, NAME, idToSearch);
                break;
            
            case 2: // Modify age
                modifyStudentInformation(database, AGE, idToSearch);                
                break;

            case 3: // Modify gender
                modifyStudentInformation(database, GENDER, idToSearch);
                break;

            case 4: // Modify Math score
                modifyStudentInformation(database, MATHSCORE, idToSearch);
                break;

            case 5: // Modify Physics score
                modifyStudentInformation(database, PHYSICSSCORE, idToSearch);
                break;

            case 6: // Modify Chemistry score
                modifyStudentInformation(database, CHEMISTRYSCORE, idToSearch);
                break;

            case 0: // Return 
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto modify_selection;
            }

            select_after_updated:
            cout << "---------------------------------------------" << endl;
            cout << "Updated information successfully" << endl;
            cout << "1. Return" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Return 
                goto modify_selection;
            
            case 0: // Exit
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto select_after_updated;
            }
            break;
        }


        case 3: // Delete student
        {
            delete_student:
            cout << "---------------------------------------------" << endl;
            cout << "\t\tDelete student" << endl;

            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, nameToSearch);
            searchByName(database, nameToSearch);

            cout << "Please enter the student ID you want to delete: ";  
            cin >> idToSearch;

            deleteStudent(database, idToSearch);

            select_after_deleted:
            cout << "1. Delete another student" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Return 
                goto delete_student;
            
            case 0: // Exit
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto select_after_deleted;
            }
            break;
        }


        case 4: // Search student
        {
            search_selection:
            cout << "---------------------------------------------" << endl;
            cout << "\t\tSearch student" << endl;
            cout << "1. Search by name" << endl;
            cout << "2. Search by ID" << endl;
            cout << "0. Return" << endl;
            cout << "Enter your choice: " << endl;
            cin >> choiceInCase;

            
            switch (choiceInCase)
            {
            case 1: // Search by name          
            {
                cout << "---------------------------------------------" << endl;
                cout << "\t\tSearch by name" << endl;
                cout << "Enter student name: ";
                cin >> nameToSearch;
                searchByName(database, nameToSearch);
                break;
            }

            case 2: // Search by ID 
            {
                cout << "---------------------------------------------" << endl;
                cout << "\t\tSearch by ID" << endl;
                cout << "Enter student ID: ";
                cin >> idToSearch;
                searchById(database, idToSearch);
                break;
            }

            case 0: // Return                
                break;
            
            default:
            {
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto search_selection;             
            }

            }

            select_after_searched:
            cout << "1. Search another student" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";
            
            cin >> selection;

            switch (selection)
            {
            case 1: // Search another student 
                goto search_selection;
            
            case 0: // Exit
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto select_after_searched;
            }
            break;
        }


        case 5: // Sort student
        {
            sort_selection:
            cout << "---------------------------------------------" << endl;
            cout << "\t\tSort student" << endl;
            cout << "1. Sort by name" << endl;
            cout << "2. Sort by Math score" << endl;
            cout << "3. Sort by Physics score" << endl;
            cout << "4. Sort by Chemistry score" << endl;
            cout << "5. Sort by average score" << endl;
            cout << "0. Return" << endl;

            cout << "Enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 1: // Sort by name
                sortStudent(database, NAME);
                break;

            case 2: // Sort by Math score
                sortStudent(database, MATHSCORE);
                break;
            
            case 3: // Sort by Physics score
                sortStudent(database, PHYSICSSCORE);
                break;

            case 4: // Sort by Chemistry score
                sortStudent(database, CHEMISTRYSCORE);
                break;
            
            case 5: // Sort by average score
                sortStudent(database, AVERAGESCORE);
                break;
            
            case 0: // Return
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto sort_selection;
            }

            cout << "---------------------------------------------" << endl;
            cout << "Sorted successfully" << endl;
            printStudentList(database);

            select_after_sorted:
            cout << "---------------------------------------------" << endl;
            cout << "1. Sort by another information" << endl;
            cout << "0. Return" << endl;
            cout << "Enter your choice: ";

            cin >> selection;

            switch (selection)
            {
            case 1: // Sort by another information 
                goto sort_selection;
            
            case 0: // Return
                break;

            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto select_after_sorted;
            }
            break;
        }


        case 6: // Print student list
        {
            cout << "---------------------------------------------" << endl;
            cout << "\t\tStudent list" << endl;
            printStudentList(database);

            select_after_print_list:
            cout << "---------------------------------------------" << endl;
            cout << "0. Return" << endl;
            cout << "Enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto select_after_print_list;
            }
            break;
        }


        case 7: // Save into file "database_sv.csv"
        {
            cout << "---------------------------------------------" << endl;
            cout << "\t\tSave into file \"database_sv.csv\"" << endl;
            updateCSV(database);

            select_after_saved:
            cout << "---------------------------------------------" << endl;
            cout << "0. Return" << endl;
            cout << "Enter your choice: ";
            cin >> choiceInCase;

            switch (choiceInCase)
            {
            case 0:
                break;
            
            default:
                cout << "---------------------------------------------" << endl;
                cout << "Choice is invalid. Please select again." << endl;
                goto select_after_saved;
            }
            break;
        }


        case 0: // Exit
        {
            cout << "---------------------------------------------" << endl;
            cout << "Exit..." << endl;
            break;
        }
            

        default:
        {
            cout << "---------------------------------------------" << endl;
            cout << "Choice is invalid. Please select again." << endl;
        }

        }

    } while (choice !=0);
    
    
    return 0;
}