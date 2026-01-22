#include <iostream>
#include <string>
using namespace std;

int main(){
    //This is the welcome page that asks if you are an admin or guest and asks for your pw
    
    string userAnswer;
    string password; // Guest password: guest.pw   Admin password: admin.pw

     cout << "Welcome to Cooldos Motors! Are you a guest or an admin?" << endl;
    cin >> userAnswer;

    cout << "Please enter your password: " << endl;
    cin >> password;

    if (password== "guest.pw" || "admin.pw"){

        cout << "Please enter what you would like to view: " << endl;
    }

    else{
        cout << "Please enter your correct password: " << endl;
    }

    string viewOptions[]= { "Available cars", "Purchase history", "Wishlist"};

    for(int i=0; i<3; i++){
        cout << viewOptions[i] << endl;
    }
    
    return 0;
}

//test 