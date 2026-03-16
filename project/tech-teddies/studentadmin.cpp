#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class Student
{
public:
    string name;
    string studentID;
    string faculty;
    string course;
    string contactnumber;
};

Student arr[100];
int total = 0;

string readIDNoSpaces()
{ 
    string id;
    while (true) 
    {
    cout << "(no spaces allowed): ";
    cin >> id;
    if (id.find( ' ') == string ::npos) 
    { 
        cin.ignore(1000, '\n'); 
        return id;
    }
      cout << "Invalid input. Student ID should not contain spaces. Please try again." << endl;
}
    }
void loadFromFile() 
{
    ifstream file("students.txt");
    if (!file) return;
    if (!(file >> total)) return;
    file.ignore(1000, '\n');

    for ( int i = 0; i < total; i++)
    {
        getline(file, arr[i].name);
        getline(file, arr[i].studentID);
        getline(file, arr[i].faculty);
        getline(file, arr[i].course);
        getline(file, arr[i].contactnumber);
    } 
    file.close();
}

void saveToFile()
{
    ofstream file ("students.txt");
    file << total << endl;
    for (int i = 0; i < total; i++)
    {
        file << arr[i].name << endl;
        file << arr[i].studentID << endl;
        file << arr[i].faculty << endl;
        file << arr[i].course << endl;
        file << arr[i].contactnumber << endl;
    }
    file.close();

}

void printStudent(const Student &s)
{
    cout << "Name: " << s.name << endl;
    cout << "Student ID: " << s.studentID << endl;
    cout << "Faculty: " << s.faculty << endl;
    cout << "Course: " << s.course << endl;
    cout << "ContactNumber: " << s.contactnumber << endl;
}

void enter()
{
    int choice;

    cout << "Please enter the number of students you wish to add: ";
    cin >> choice;
    cin.ignore();

    if (total + choice > 100)
    {
        cout << "Not enough space! You can only add " << 100 - total << " more student(s)." << endl;
        return;
    }

    for (int i = total; i < total + choice; i++)
    {
        cout << "\nEnter data of student " << i + 1 << endl << endl;

        cout << "Enter name: ";
        getline(cin, arr[i].name);

        cout << "Enter student ID ";
         arr[i].studentID = readIDNoSpaces();

        cout << "Enter faculty: ";
        getline(cin, arr[i].faculty);

        cout << "Enter course: ";
        getline(cin, arr[i].course);

        cout << "Enter contactnumber: ";
        getline(cin, arr[i].contactnumber);
    }

    total += choice;

    cout << "\nStudent(s) added successfully!" << endl;
}
void view()
{
    if (total == 0)
    {
        cout << "\nNo student records found." << endl;
        return;
    }

    cout << endl;

    for (int i = 0; i < total; i++)
    {
        cout << "Data of student " << i + 1 << endl;
        printStudent(arr[i]);
        cout << "-----------------------------" << endl;
    }
}

void search()
{
    string id;
    bool found = false;

    cout << "\nEnter student ID: ";
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (id == arr[i].studentID)
        {
            cout << "\nStudent found:\n" << endl;
            printStudent(arr[i]);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

void update()
{
    string id;
    bool found = false;

    cout << "\nEnter student ID: ";
    cin >> id;
    cin.ignore(1000, '\n');

    for (int i = 0; i < total; i++)
    {
        if (id == arr[i].studentID)
        {
            cout << "\nCurrent data:\n";
            printStudent(arr[i]);

            cout << "\nEnter new data\n";

            cout << "Enter name: ";
            getline(cin, arr[i].name);

            cout << "Enter student ID: ";
            arr[i].studentID = readIDNoSpaces();
            

            cout << "Enter faculty: ";
            getline(cin, arr[i].faculty);

            cout << "Enter course: ";
            getline(cin, arr[i].course);

            cout << "Enter contactnumber: ";
            getline(cin, arr[i].contactnumber);

            cout << "\nStudent data updated successfully!" << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

void deleterecord()
{
    int choice;

    cout << "\nPress 1 to delete all records" << endl;
    cout << "Press 2 to delete a specific record" << endl;
    cin >> choice;

    if (choice == 1)
    {
        total = 0;
        cout << "All records deleted successfully!" << endl;
    }
    else if (choice == 2)
    {
        string id;
        bool found = false;

        cout << "Enter the student ID to delete: ";
        cin >> id;

        for (int i = 0; i < total; i++)
        {
            if (id == arr[i].studentID)
            {
                for (int j = i; j < total - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }

                total--;

                cout << "Record deleted successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
    else
    {
        cout << "Invalid input." << endl;
    }
    
    int main()
{
    loadFromFile();
    int value;

    while (true)
    {
        cout << "===================================\n";
        cout << "      Student Management System\n";
        cout << "===================================\n";

        cout << "Press 1 to add student" << endl;
        cout << "Press 2 to view all students" << endl;
        cout << "Press 3 to search student" << endl;
        cout << "Press 4 to update student" << endl;
        cout << "Press 5 to delete student" << endl;
        cout << "Press 6 to exit\n" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> value))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n" << endl;
            continue;
        }

        switch (value)
        {
        case 1:
            enter();
            cout << endl;
            break;

        case 2:
            view();
            cout << endl;
            break;

        case 3:
            search();
            cout << endl;
            break;

        case 4:
            update();
            cout << endl;
            break;

        case 5:
            deleterecord();
            cout << endl;
            break;

        case 6:
            saveToFile();
            exit(0);

        default:
            cout << "Invalid input. Please try again.\n" << endl;
        }
    }

    return 0;
}
