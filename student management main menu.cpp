#include <iostream>
using namespace std;
string arr1[20], arr2[20], arr3[20], arr4[20],arr5[20];
int total = 0;
void enter()
{
int choice;
cout << "How many students do you want to enter?" ;
cin >> choice;
if (total==0)
{
total = total + choice;
for (int i=0; i <choice; i++)
{
    cout << "Please enter the data of student " << i+1 << endl;
    cout << "Please enter the student's name: " << endl;
    cin >> arr1[i];
    cout << " Please enter the student number: " << endl;
    cin >> arr2[i];
    cout << "Please enter the student's class: " << endl;
    cin >> arr3[i];
    cout << "Please enter the student's faculty: " << endl;
    cin >> arr4[i];
    cout << "Please enter the student's contact number: " << endl;
    cin >> arr5[i];
    
}
}
else{
for (int i=total; i < total+choice; i++)
{
    cout << "Please enter the data of student " << i+1 << endl << endl;
    cout << "Please enter the student's name: " << endl;
    cin >> arr1[i];
    cout << " Please enter the student number: " << endl;
    cin >> arr2[i];
    cout << "Please enter the student's class: " << endl;
    cin >> arr3[i];
    cout << "Please enter the student's faculty: " << endl;
    cin >> arr4[i];
    cout << "Please enter the student's contact number: " << endl;
    cin >> arr5[i];

}
total = total + choice;
}
}
void show()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else {
for (int i=0; i < total; i++)
{
    cout << "Data of student " << i+1 << endl << endl;
    cout << "Name of student: " << arr1[i] << endl;
    cout << "Student number: " << arr2[i] << endl;
    cout << "Class: " << arr3[i] << endl;
    cout << "Faculty: " << arr4[i] << endl;
    cout << "Contact number: " << arr5[i] << endl;
}
}
}
void search()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
     else {
    string studentnumber;
cout << "Please enter the student number to search: " << endl;
cin >> studentnumber;
for (int i=0; i < total; i++)
{
    if (arr2[i] == studentnumber)
    {
        cout << "Data of student " << i+1 << endl << endl;
        cout << "Name of student: " << arr1[i] << endl;
        cout << "Student number: " << arr2[i] << endl;
        cout << "Class: " << arr3[i] << endl;
        cout << "Faculty: " << arr4[i] << endl;
        cout << "Contact number: " << arr5[i] << endl;
    }
}
}
}
void update()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
     else {
string studentnumber;
cout << "Please enter the student number to update: " << endl;
cin >> studentnumber;
for (int i=0; i < total; i++)
{
    if (arr2[i] == studentnumber)
    {
       cout << "Previous data of student " << i+1 << endl << endl;
        cout << "Please enter the new data of student " << i+1 << endl;
        cout << "Please enter the student's name: " << endl;
        cin >> arr1[i];
        cout << "Please enter the student number: " << endl;
        cin >> arr2[i];
        cout << "Please enter the student's class: " << endl;
        cin >> arr3[i];
        cout << "Please enter the student's faculty: " << endl;
        cin >> arr4[i];
        cout << "Please enter the student's contact number: " << endl;
        cin >> arr5[i];
    }
}

}
}
void deleterecord()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
     else {
int a;
cout << "Press 1 to delete all records" << endl;
cout << "Press 2 to delete specific record" << endl;
cin >> a;
if (a==1)
{
    total = 0;
    cout << "All records have been succesfully deleted" << endl;
}
else if (a==2) 
{
string studentnumber;
cout << "Please enter the student number which you want to delete: " << endl;
cin >> studentnumber;
for (int i=0; i < total; i++)
{
    if (arr2[i] == studentnumber)
    {
        for (int j = i; j < total-1; j++)
        {
            arr1[j] = arr1[j+1];
            arr2[j] = arr2[j+1];
            arr3[j] = arr3[j+1];
            arr4[j] = arr4[j+1];
            arr5[j] = arr5[j+1];
        }
        total--;
        cout << "The student's data has been succesfully deleted" << endl;
    }
}
}
}
 int main () 
 {

int value;
    while(true) 
    {
cout << "Press 1 to enter data" << endl;
cout << "Press 2 to show data" << endl;
cout << "Press 3 to search data" << endl;
cout << "Press 4 to update data" << endl;
cout << "Press 5 to delete data" << endl;
cout << "Press 6 to exit" << endl;
cin >> value;
switch (value) {

case 1:
    enter();
    break;
case 2:
    show();
    break;
case 3:
    search();
    break;
case 4:
    update();
    break;
case 5:
    deleterecord();
    break;
case 6:
    exit(0);
    return 0;
default:
    cout << "Invalid input. Please try again." << endl;
    break;
}
} }