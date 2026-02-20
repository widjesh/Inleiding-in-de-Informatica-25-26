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
        };
