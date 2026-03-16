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
