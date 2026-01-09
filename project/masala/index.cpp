#include <iostream>
using namespace std;

class Bird {
    public:
        int ID; 
        string birdName;
        string birdType;
        string birdSpecies;
        string scientificName;
        string typeOfInjury;
        string dateIn;
        string dateOut;

};

int createNewBird() {

}

int birdLookupSpecific( ) {
    int test = 5;
    return test;
};

int birdLookupAll() {
    int x = 6;
    return x;
}

int main() {
    int firstOption;
    string userPasswordInput;
    string birdIDOrAll;
    int administratorChoice;
    string administratorPassword = "Masala";
    cout << "Welcome, please choose one of the following options" << endl;
    cout << "Enter [1] to lookup birds" << endl;
    cout << "Enter [2] to access birds database(Administrator Password Required)" << endl;
    cin >> firstOption;
    cout << firstOption << endl;

    if (firstOption == 1) {
        cout << "Welcome, do you want to view the whole database or search a specific bird?" << endl;
        cout << "[A] for whole database" << endl;
        cout << "[ID] for specific bird" << endl;
        cin >> birdIDOrAll;

        if (birdIDOrAll == "A") {
            cout << birdLookupAll() << endl;
        } else if(birdIDOrAll == "ID") {
            cout << birdLookupSpecific() << endl;
        } else {
            cout << "Please put in A or ID(Case sensitive)" << endl;
            cin >> birdIDOrAll;
        }

          } else if (firstOption != 1 || 2) {
             cout << "Please put in a valid number" << endl;
             cin >> firstOption;
           }

    if (firstOption == 2) {
        cout << "Please enter the administrator Password(Case Sensitive!)";
        cin >> userPasswordInput;
        if (userPasswordInput == administratorPassword) {
            cout << "Welcome administrator" << endl;
            cout << "Please choose one of the following" << endl;
            cout << "[1] to View Database" << endl;
            cout << "[2] to Add a New Bird" << endl;
            cout << "[3] to Remove a Bird" << endl;
            cout << "[4] to Alter a Existing Bird" << endl;
            cin >> administratorChoice;

            if (administratorChoice == 1) {
                cout << birdLookupAll() << endl;
            }
        }
        else {
            cout << "Wrong Password, please try again" << endl;
            cin >> userPasswordInput;
        }
    } 

    return 0;
}