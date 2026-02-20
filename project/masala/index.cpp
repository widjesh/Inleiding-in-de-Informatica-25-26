#include <iostream>
#include <vector>


using namespace std;

class Bird {
    public:
        int ID; 
        string birdName;
        string birdType;
        string birdSpecies;
        string scientificName;
        string typeOfInjury;
        string dateInAndOut;
      

        Bird() {}; //global constructor

    Bird(int ID, string birdName, string birdSpecies, string scientificName, string typeOfInjury, string dateInAndOut) : ID(ID), birdName(birdName), birdType(birdType), birdSpecies(birdSpecies), scientificName(scientificName), typeOfInjury(typeOfInjury), dateInAndOut(dateInAndOut) {}; //constructor met parameters
};

/*int createNewBird() {

}*/

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
    
    cout << "Welcome to our bird clinique" << endl;
    cout << "Please choose one of the following options" << endl; 

    do{
    cout << "Choose one of the following options" << endl;
    cout << "Enter [1] to lookup birds" << endl;
    cout << "Enter [2] to access birds database(Administrator Password Required)" << endl;
    cin >> firstOption;


if (firstOption == 1 || firstOption == 2) { 
    if (firstOption == 1) {
    do { //do while loop to make sure user inputs either A or ID, if not it will ask again until they do
        cout << "Welcome, do you want to view the whole database or search a specific bird?" << endl;
        cout << "[A] for whole database" << endl;
        cout << "[ID] for specific bird" << endl;
        cout << "[R] to return to main menu" << endl;
        cin >> birdIDOrAll;

        if (birdIDOrAll == "A") {
            cout << birdLookupAll() << endl;
        } else if(birdIDOrAll == "ID") {
            cout << birdLookupSpecific() << endl;
        } else if (birdIDOrAll == "R") {
            main();
        } else {
            cout << "Please put in A, ID, or R(Case sensitive)" << endl;
            cin >> birdIDOrAll;
         }   
        }while (birdIDOrAll != "A" && birdIDOrAll != "ID" && birdIDOrAll != "R");
    }
    

 else if (firstOption == 2) {
    do {    // do while loop to make sure user inputs correct password, if not it will ask again until they do
            cout << "Please enter the administrator Password(Case Sensitive!)" << endl;
            cin >> userPasswordInput;

        if (userPasswordInput == administratorPassword) {
            cout << "Welcome administrator" << endl;
            cout << "Please choose one of the following" << endl;
            cout << "[1] to View Database" << endl;
            cout << "[2] to Add a New Bird" << endl;
            cout << "[3] to Remove a Bird" << endl;
            cout << "[4] to Alter an Existing Bird" << endl;
            cout << "[5] to Return to Main Menu" << endl;   
            cin >> administratorChoice;

            if (administratorChoice == 1) {
                cout << birdLookupAll() << endl;
            } else if (administratorChoice == 5) {
                main();
            }

            if (userPasswordInput != administratorPassword) {
            cout << "Wrong Password, please try again." << endl;
        }
    }
}while (userPasswordInput != administratorPassword);

<<<<<<< HEAD

}   } else {    cout << "Please put in a valid number" << endl;
            cin >> firstOption;
=======
}
}   else {    cout << "Please put in a valid number" << endl;           
>>>>>>> 13a44d9e37a43af9ade2e976b938dba607a78f78
           }
        }while (firstOption != 1 && firstOption != 2);

    return 0;
}        