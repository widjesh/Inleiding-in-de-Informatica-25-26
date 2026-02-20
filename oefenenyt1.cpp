#include <iostream>
using namespace std;

void enter()
{

}
void view()
{

}
void search()
{

}
void update()
{

}
void deleterecord()
{

}

int  main() {
    int value;
    while (true) { 

    cout << "Press 1 to add student" << endl;
    cout << "Press 2 to view all students" << endl; 
    cout << "Press 3 to search student" << endl;
    cout << "Press 4 to update student" << endl;
    cout << "Press 5 to delete student" << endl;
    cout << "Press 6 to exit" << endl;
cin >> value; 
switch (value) 
{ 
    case 1: 
    enter();
    break;
    case 2:
    view();
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
    break;
    default:
    cout << "Invalid input. Please try again." << endl;
    break;
}
    }
    return 0;
}   
