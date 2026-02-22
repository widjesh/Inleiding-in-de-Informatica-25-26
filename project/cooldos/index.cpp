#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car
{
public:
    string brand;
    string model;
    string engineType;
    int horsePower;
    int topSpeed;
    int buildYear;
    float price;

    void specs()
    {
        cout << brand << " " << model << " specifications:\n"
             << "Build year: " << buildYear << endl
             << "Engine type: " << engineType << endl
             << "Horse power: " << horsePower << "hp" << endl
             << "Top speed: " << topSpeed << "km/h" << endl
             << "Price: $" << price << endl;
    }

    float calculateDiscountedPrice(float price, float premiumDiscount)
    {
        return price = price - (price * premiumDiscount / 100);
    } // function for calculating price after discount (in class because it uses variables that are in the class)
};
// delete function
void deleteCar(vector<Car> &cars, int &carCount)
{
    int deleteIndex;

    cout << "Enter the number of the car you want to delete:\n";

    for (int i = 0; i < carCount; i++)
    {
        cout << i + 1 << ") "
             << cars[i].brand << " "
             << cars[i].model << endl;
    }

    cout << "(0) Cancel\n";
    cin >> deleteIndex;

    if (deleteIndex > 0 && deleteIndex <= carCount)
    {
        cars.erase(cars.begin() + (deleteIndex - 1));
        carCount--;
        cout << "Car deleted successfully.\n";
    }
    else if (deleteIndex != 0)
    {
        cout << "Invalid selection.\n";
    }
}
//add function
void addCar(vector<Car> &cars, int &carCount)
{
    Car newCar;

    cout << "Enter car brand: ";
    cin >> newCar.brand;

    cout << "Enter car model: ";
    cin >> newCar.model;

    cout << "Enter car year: ";
    cin >> newCar.buildYear;

    cout << "Enter car price: ";
    cin >> newCar.price;

    // add the car to the vector
    cars.push_back(newCar);

    carCount++;

    cout << "Car added successfully.\n";
}
void changePrice(vector<Car>& aCars, int& vectorSize) { //function for updating price of cars
    int adminNumChoice;
    
    while (true) {
    cout << "Please select car to change price of: " << endl;
    for (int i = 0; i < vectorSize; i++) {
        cout << (i + 1) << ") " << aCars[i].brand << " " << aCars[i].model << endl;
    }
    cout << "0) Cancel " << endl;
    cin >> adminNumChoice;
    
    if (adminNumChoice == 0) {
        return ;
    }
    else if (adminNumChoice > 0 && adminNumChoice <= vectorSize) {
        cout << "enter new price for " << aCars[adminNumChoice - 1].brand << " " << aCars[adminNumChoice - 1].model << ": \n";
        cout << "$"; cin >> aCars[adminNumChoice - 1].price;
        cout << "price updated!!" << aCars[adminNumChoice - 1].brand << " " << aCars[adminNumChoice - 1].model << " now costs $" << aCars[adminNumChoice - 1].price<< endl;
    } while (true) {
        cout << "(0) return to menu" << endl;
        cin >> adminNumChoice;
        if (adminNumChoice == 0) {
            return;
        }
    }
    
    }
}
void adminMenu(vector<Car> aCars, int vectorSize)
{ // function for admin menu

    char adminChoice;
    int adminNumChoice;

    while (true)
    {
        cout << "(a) Available cars" << endl;
        cout << "(b) Remove cars" << endl;
        cout << "(c) Add cars" << endl;
        cout << "(d) Change car price" << endl;
        cout << "(e) Exit application" << endl;
        cin >> adminChoice;

        switch (adminChoice)
        {
        case 'e':
            return;

        case 'a':
            while (true)
            {
                cout << "Please select which car you would like to view" << endl;

                for (int i = 0; i < vectorSize; i++)
                {
                    cout << (i + 1) << ") " << aCars[i].brand << " " << aCars[i].model << endl;
                }
                cout << "(0) return to menu" << endl;
                cin >> adminNumChoice;

                if (adminNumChoice == 0)
                {
                    break;
                }
                else if (adminNumChoice > 0 && adminNumChoice <= vectorSize)
                {
                    aCars[adminNumChoice - 1].specs();
                }
                while (true)
                {
                    cout << "(0) Back to available cars list" << endl;
                    cin >> adminNumChoice;
                    if (adminNumChoice == 0)
                    {
                        break;
                    }
                }
            }
            break;

        case 'b':
            deleteCar(aCars, vectorSize);
            break;

        case 'c':
        addCar(aCars, vectorSize);
            break;

        case 'd':
            changePrice(aCars, vectorSize);
            break;
        }
    }
}
int main(){
{

    int numberPcars = 4;        // number purchased cars
    int numberAcars = 5;        // number available cars
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
    car3.buildYear = 2021;
    car3.price = 190000;

    Car car4;
    car4.brand = "BMW";
    car4.model = "M3";
    car4.engineType = "3.0L TB I6";
    car4.horsePower = 473;
    car4.topSpeed = 290;
    car4.buildYear = 2020;
    car4.price = 70000;

    Car car5;
    car5.brand = "Mercedes-Benz";
    car5.model = "AMG-GT";
    car5.engineType = "4.0L V8";
    car5.horsePower = 523;
    car5.topSpeed = 310;
    car5.buildYear = 2019;
    car5.price = 115000;

    Car car6;
    car6.brand = "Audi";
    car6.model = "RS5";
    car6.engineType = "2.9L TT V6";
    car6.horsePower = 444;
    car6.topSpeed = 280;
    car6.buildYear = 2021;
    car6.price = 75000;

    Car car7;
    car7.brand = "Honda";
    car7.model = "Civic";
    car7.engineType = "2.0L I4";
    car7.horsePower = 158;
    car7.topSpeed = 200;
    car7.buildYear = 2020;
    car7.price = 24000;

    Car car8;
    car8.brand = "Mazda";
    car8.model = "3";
    car8.engineType = "2.0 I4";
    car8.horsePower = 155;
    car8.topSpeed = 195;
    car8.buildYear = 2018;
    car8.price = 21000;

    Car car9;
    car9.brand = "Hyundai";
    car9.model = "Elantra";
    car9.engineType = "2.0L I4";
    car9.horsePower = 147;
    car9.topSpeed = 190;
    car9.buildYear = 2019;
    car9.price = 20000;

    vector<Car> availableCars = {car1, car2, car3, car4, car5}; // bassicly an array but you can add and remove items
    vector<Car> purchasedCars = {car6, car7, car8, car9};

    // This is the welcome page that asks if you are an admin or guest and asks for your pw
    string userAnswer;
    string password; // Guest password: guest.pw   Admin password: admin.pw

    cout << "Welcome to Cooldos Motors! Are you a guest or an admin?" << endl;
    cin >> userAnswer;

    while (userAnswer != "guest" && userAnswer != "admin")
    { // if you dont answer with guest or admin, your answer is invalid and u will have to try again
        cout << "Invalid answer." << endl
             << "Are you a guest or an admin?" << endl;
        cin >> userAnswer;
    }

    cout << "Please enter your password: " << endl;
    cin >> password;

    while ((password != "guest.pw" && password != "PREMIUMguest.pw" && userAnswer == "guest") || (password != "admin.pw" && userAnswer == "admin"))
    {
        // if you dont use the correct pw for guest or admin, u have to try again (including new PREMIUM guest pw)
        cout << "Please enter your correct password: " << endl;
        cin >> password;
    }

    if (password == "PREMIUMguest.pw")
    { // if you are a premium guest, you get a discount on all available cars
        for (int i = 0; i < numberAcars; i++)
        {
            availableCars[i].price = availableCars[i].calculateDiscountedPrice(availableCars[i].price, premiumDiscount);
        }
    }
if (userAnswer == "guest"){
    while (true)
    {
        cout << "Please enter what you would like to view: " << endl;

        string viewOptions[] = {"(a) Available cars", "(b) Purchase history",  "(e) Exit Cooldos Motors!"}; // these are the options that u can view

        for (int i = 0; i < 3; i++)
        { // dit geeft die lijst onder elkaar weer
            cout << viewOptions[i] << endl;
        }

        char view;
        cin >> view; // hier kan je kiezen welke van de opties je wilt zien

        int carIndex;
        int historyIndex;

        switch (view)
        {
        case 'a': // dit geeft een lijst van available cars onder elkaar weer
            while (true)
            {
                cout << "Which car would you like to view the specifications of? " << endl;
                for (int i = 0; i < numberAcars; i++)
                {
                    cout << i + 1 << ") " << availableCars[i].brand << ' ' << availableCars[i].model << endl;
                }
                cout << "(0) Back to main menu" << endl;
                cin >> carIndex;   // je kan dus kiezen welke specs je wilt zien
                if (carIndex == 0) // brengt je terug naar main menu
                {
                    break;
                }
                else if (carIndex > 0 && carIndex <= numberAcars)
                {
                    availableCars[carIndex - 1].specs(); // hier worden de specificaties van de gekozen auto weergegeven
                }
                while (true)
                {
                    cout << "(0) Back to available car list" << endl;
                    cin >> carIndex;
                    if (carIndex == 0)
                    {
                        break;
                    }
                }
            }
            break;

        case 'b': // dit geeft een lijst van previously purchased cars onder elkaar weer
            while (true)
            {
                cout << "Which car would you like to view the specifications of? " << endl;
                for (int j = 0; j < numberPcars; j++)
                {
                    cout << j + 1 << ") " << purchasedCars[j].brand << ' ' << purchasedCars[j].model << endl;
                }
                cout << "(0) Back to the main menu." << endl;
                cin >> historyIndex;   // kies welke specs van auto's je wilt zien
                if (historyIndex == 0) // brengt je terug naar main menu
                {
                    break;
                }
                else if (historyIndex > 0 && historyIndex <= numberPcars)
                {
                    purchasedCars[historyIndex - 1].specs(); // shows specs of previously bought cars
                }
                while (true)
                {
                    cout << "(0) Back to purchased car list" << endl;
                    cin >> historyIndex;
                    if (historyIndex == 0)
                    {
                        break;
                    }
                }
            }
            break;

        case 'e':
            cout << "Thank you for visiting Cooldos Motors!" << endl;
            return 0;
        }
    }
}
    else if (userAnswer == "admin")
        cout << "poopensharten"<< endl;
adminMenu(availableCars, numberAcars); // calls function for admin menu
}
return 0;
}
 

        return 0;
    }
}
