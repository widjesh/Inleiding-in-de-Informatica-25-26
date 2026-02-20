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