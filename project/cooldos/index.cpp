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

    }

     float calculateDiscountedPrice(float price, float premiumDiscount) {
       return price = price - (price * premiumDiscount / 100);
     } // function for calculating price after discount (in class because it uses variables that are in the class)

    };

int main(){

    int numerPcars; // number purchased cars
    int numberAcars = 5; // number available cars
    float premiumDiscount = 15; // discount percentage for premium guests
    
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.engineType = "1.2L Turbo V4";
    car1.horsePower = 156;
    car1.topSpeed = 160;
    car1.buildYear = 2020;
    car1.price = 20000;

    Car car2;
    car2.brand = "Ferrari";
    car2.model = "SF90";
    car2.engineType = "4.0L V8";
    car2.horsePower = 900;
    car2.topSpeed = 300;
    car2.buildYear = 2019;
    car2.price = 269000;

    Car car3;
    car3.brand = "Porsche";
    car3.model = "911Turbo";
    car3.engineType = "3.8L F6";
    car3.horsePower = 572;
    car3.topSpeed = 330;
    car3.buildYear =2021;
    car3.price  = 190000;

    Car car4;
    car4.brand ="BMW";
    car4.model = "M3";
    car4.engineType ="3.0L TB I6"; 
    car4.horsePower = 473;
    car4.topSpeed = 290;
    car4.buildYear = 2020;
    car4.price = 70000;

    Car car5;
    car5.brand ="Mercedes-Benz";
    car5.model ="AMG-GT";
    car5.engineType = "4.0L V8"; 
    car5.horsePower =  523;
    car5.topSpeed = 310;
    car5.buildYear = 2019;
    car5.price = 115000;

        Car availableCars[numberAcars] = {car1, car2, car3, car4, car5};
    

    //This is the welcome page that asks if you are an admin or guest and asks for your pw
    string userAnswer;
    string password; // Guest password: guest.pw   Admin password: admin.pw

     cout << "Welcome to Cooldos Motors! Are you a guest or an admin?" << endl;
     cin >> userAnswer;
     
        while(userAnswer != "guest" && userAnswer != "admin"){ // if you dont answer with guest or admin, your answer is invalid and u will have to try again
            cout << "Invalid answer." << endl 
                << "Are you a guest or an admin?" << endl;
            cin >> userAnswer;
        }

    cout << "Please enter your password: " << endl;
    cin >> password;

      while ((password != "guest.pw" && password != "PREMIUMguest.pw" && userAnswer == "guest") || (password != "admin.pw" && userAnswer == "admin")){
        // if you dont use the correct pw for guest or admin, u have to try again (including new PREMIUM guest pw)
        cout << "Please enter your correct password: " << endl;
        cin >> password;
    }

     if (password == "PREMIUMguest.pw") {
            for(int i=-1; i<numberAcars; i++){ 
                availableCars[i].price = availableCars[i].calculateDiscountedPrice(availableCars[i].price, premiumDiscount);
            }
        }

    cout << "Please enter what you would like to view: " << endl;

    string viewOptions[]= { "(a) Available cars", "(b) Purchase history"}; // these are the options that u can view

    for(int i=0; i<3; i++){ // dit geeft die opties onder elkaar weer
        cout << viewOptions[i] << endl;
    }

    char view;
    cin >> view; // hier kan je kiezen welke van de opties je wilt zien

    string purchaseHistory[] = {"Ford Ranger" , "Toyota Vitz"}; // previously purchased cars

    int carIndex;

    switch(view){
        case 'a': // dit geeft een lijst van available cars onder elkaar weer
            cout << "Which car would you like to view the specifications of? " << endl;
            for (int i=0; i<numberAcars; i++){ 
            cout << i+1 << ") " << availableCars[i].brand << ' ' << availableCars[i].model << endl;
             }
             cin >> carIndex;
                break;
        
        case 'b': // dit geeft een lijst van previously purchased cars onder elkaar weer 
             for (int j=0; j<2; j++){
            cout << purchaseHistory[j] << endl;
             }
        break;

            }

    
            switch(carIndex){
                case 1:
                     availableCars[0].specs();
                break;

                case 2:
                    availableCars[1].specs();
                break;

                case 3:
                    availableCars[2].specs();
                break;

                case 4:
                    availableCars[3].specs();
                break;

                case 5:
                    availableCars[4].specs();
                break;
            }
            
            

    return 0;
}
