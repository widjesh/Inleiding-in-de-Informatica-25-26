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

float calculateDiscountedPrice (float Car.price, float premiumDiscount) {
    return Car.price - (Car.price * premiumDiscount / 100);
}

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

    string availableCars[] = { "Toyota Corolla", "Ferrari SF90"}; // dit zijn de verschillende available auto's 

<<<<<<< HEAD
    string purchaseHistory[] = {"Ford Ranger" , "Toyota Vitz"}; // previously purchased cars

    
    int carIndex;
=======
    string purchaseHistory[] = {"Ford Ranger, Toyota Vitz"};
>>>>>>> e8105e5ae924939a73debf1a7990a43e08aec2a8

    switch(view){
        case 'a': // dit geeft een lijst van available cars onder elkaar weer
            cout << "Which car would you like to view the specifications of? " << endl;
            for (int i=0; i<2; i++){ 
            cout << availableCars[i] << endl;
             }
             cin >> carIndex;
                break;
        
<<<<<<< HEAD
        case 'b': // dit geeft een lijst van previously purchased cars onder elkaar weer 
             for (int j=0; j<2; j++){
            cout << purchaseHistory[j] << endl;
=======
        case 'b':
             for (int i=0; i<3; i++){
            cout << purchaseHistory[i] << endl;
>>>>>>> e8105e5ae924939a73debf1a7990a43e08aec2a8
             }
        break;

            }

            cin >> carIndex;

            Car car1;
            car1.brand = "Toyota";
            car1.model = "Corolla";
            car1.engineType = "1.2L Turbo V4";
            car1.horsePower = 156;
            car1.topSpeed = 160;
            car1.buildYear = 2020;
            car1.price = 20.000;

            Car car2;
            car2.brand = "Ferrari";
            car2.model = "Sf90";
            car2.engineType = "4.0L V8";
            car2.horsePower = 900;
            car2.topSpeed = 300;
            car2.buildYear = 2019;
            car2.price = 269.000;

            switch(carIndex){
                case '1':
                     car1.specs();
                break;

                case '2':
                    car2.specs();
                break;
            }
            
            

    return 0;
}
