#include <iostream>
#include <string>
using namespace std;

class Car {
    public: 
    string brand;
    string model;
    string engineType;
    int horsePower;
    int topSpeed;
    int buildYear;
    float price;

    void specs() {
        cout << brand << " " << model << " specifications:\n"
        << "Build year: " << buildYear << endl 
        << "Engine type: " << engineType << endl 
        << "Horse power: " << horsePower << "hp" << endl 
        << "Top speed: " << topSpeed << "km/h" << endl 
        << "Price: $" << price <<  endl;
    };
};

int main(){
    //This is the welcome page that asks if you are an admin or guest and asks for your pw
    
    string userAnswer;
    string password; // Guest password: guest.pw   Admin password: admin.pw

     cout << "Welcome to Cooldos Motors! Are you a guest or an admin?" << endl;
     cin >> userAnswer;
     
        while(userAnswer != "guest" && userAnswer != "admin"){ // if you dont answer with guest or admin, your answer is invalid and u will have to try again
            cout << "Invalid answer." << endl << "Are you a guest or an admin?" << endl;
            cin >> userAnswer;
        }

    cout << "Please enter your password: " << endl;
    cin >> password;

    while(password != "guest.pw" && password != "admin.pw"){ // if you dont use the correct pw, u have to try again
        cout << "Please enter your correct password: " << endl;
        cin >> password;
    }

    cout << "Please enter what you would like to view: " << endl;

    string viewOptions[]= { "(a) Available cars", "(b) Purchase history"}; // these are the options that u can view

    for(int i=0; i<3; i++){ // dit geeft die opties onder elkaar weer
        cout << viewOptions[i] << endl;
    }

    char view;
    cin >> view; // hier kan je kiezen welke van de opties je wilt zien

    string availableCars[] = { "Toyota Corola", "Ferrari SF90", "Toyota Hilux"}; // dit zijn de verschillende available auto's 

    string purchaseHistory[] = {"Ford Ranger" , "Toyota Vitz"};

    switch(view){
        case 'a':
            for (int i=0; i<3; i++){
            cout << availableCars[i] << endl;
             }
        break;
        
        case 'b':
             for (int j=0; j<3; j++){
            cout << purchaseHistory[j] << endl;
             }
        break;

            }
    return 0;
}
