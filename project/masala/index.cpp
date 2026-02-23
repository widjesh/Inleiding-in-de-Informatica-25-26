#include <iostream>
#include <vector>
#include <fstream>


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

    Bird(int ID, string birdName, string birdType, string birdSpecies, string scientificName, string typeOfInjury, string dateInAndOut) : ID(ID), birdName(birdName), birdType(birdType), birdSpecies(birdSpecies), scientificName(scientificName), typeOfInjury(typeOfInjury), dateInAndOut(dateInAndOut) {}; //constructor met parameters

    void display() {
        cout << "\nCreated new Bird Object" << endl;
    }

};

//void meaning no vaste data type als int of string ofzo
/*
void saveBird( const Bird& p, const string& filename) {
    ofstream outfile(filename, ios::app);

    if(outfile.is_open()) {
        outfile << p.ID << " " << p.birdName << endl;
        cout << "\nSaved " << p.birdName << "to " << filename << endl;

    } else{
        cout << "\n Error, Please contact support";
    }      
}
    */

   
Bird createNewBird() {
    int ID;
    string birdName;
    string birdType;
    string birdSpecies;
    string scientificName;
    string typeOfInjury;
    string dateInAndOut;

    cout << "Enter ID" << endl;
    cin >> ID;
    cout << "Enter name of bird" << endl;
    cin >> birdName;
    cout << "Enter type of bird" << endl;
    cin >> birdName;
    cout << "Enter birdSpecies" << endl;
    cin >> birdSpecies;
    cout << "Enter scientific name" << endl;
    cin >> scientificName;
    cout << "Enter type of injury" << endl;
    cin >> typeOfInjury;
    cout << "Enter date" << endl;
    cin >> dateInAndOut;

    return Bird(ID, birdName, birdType, birdSpecies, scientificName, typeOfInjury, dateInAndOut);
    //hiervoor is de constructor nodig, maken van die objects door die parameters
}

int birdLookupSpecific( ) {
    int test = 5;
    return test;
};

int birdLookupAll() {
    int x = 6;
    return x;
}

/*int administratorMenu() {
    int administratorChoice;
    cout << "Please choose one of the following" << endl;
    cout << "[1] to View Database" << endl;
    cout << "[2] to Add a New Bird" << endl;
    cout << "[3] to Remove a Bird" << endl;
    cout << "[4] to Alter an Existing Bird" << endl;
    cout << "[5] to Return to Main Menu" << endl;   // To return to main menu, we will call the main function again (So we will start the whole process again, asking for the first option and so on)
    cin >> administratorChoice;

    return administratorChoice;
}*/

int main() {
  //  startOfProgram:
    int firstOption;
    string userPasswordInput;
    string birdIDOrAll;
    int administratorChoice;
    int administratorChoice2;
    Bird object;
    string administratorPassword = "Masala";
    int i;
    
    cout << "WELCOME TO OUR BIRD CLINIC\n" << endl;
    startOfProgram:
    do{
        cout << "Choose one of the following options:" << endl;
        cout << "Enter [1] to lookup birds" << endl;
        cout << "Enter [2] to access birds database (Administrator Password Required)" << endl;
        cin >> firstOption;


        if (firstOption == 1 || firstOption == 2) { 
            
            if (firstOption == 1) {
                cout << "Welcome, do you want to view the whole database or search a specific bird?" << endl;
                do { //do while loop to make sure user inputs either A or ID, if not it will ask again until they do
                cout << "[A] for whole database" << endl;
                cout << "[ID] for specific bird" << endl;
                cout << "[R] to return to main menu" << endl; // To return to main menu, we will call the main function again (So we will start the whole process again, asking for the first option and so on)
                cin >> birdIDOrAll;

                if (birdIDOrAll == "A") {
                    cout << birdLookupAll() << endl;
                } 
                
                else if(birdIDOrAll == "ID") {
                    cout << birdLookupSpecific() << endl;
                } 
                
                else if (birdIDOrAll == "R") {
                    goto startOfProgram;
                } 
                
                else {
                    cout << "Please put in a valid input:" << endl;
                }   
                } while (birdIDOrAll != "A" && birdIDOrAll != "ID" && birdIDOrAll != "R");
            } 
            
            else if (firstOption == 2) {
                for(i=0;i<3;i++){
                    cout << "Please enter the administrator Password(Case Sensitive!)" << endl;
                    cin >> userPasswordInput;
                    

                        if (userPasswordInput == administratorPassword) {
                            cout << "Welcome administrator" << endl;
                            cout << "Please choose one of the following" << endl;
                            startOfAdministratorMenu:
                            cout << "\nASMINISTRATOR MENU:" << endl;
                            cout << "[1] to View Database" << endl;
                            cout << "[2] to Add a New Bird" << endl;
                            cout << "[3] to Remove a Bird" << endl;
                            cout << "[4] to Alter an Existing Bird" << endl;
                            cout << "[5] to Return to Main Menu" << endl;   // To return to main menu, we will call the main function again (So we will start the whole process again, asking for the first option and so on)
                            cin >> administratorChoice;
                            

                            if (administratorChoice == 1) {
                                cout << birdLookupAll() << endl;
                            } 
                            
                            else if (administratorChoice == 2) {
                                startOfCreateNewBird:
                                Bird bird = createNewBird();
                                bird.display();

                              do {     
                                    cout << "\n[0] to go back to administrator menu" << endl;
                                    cout << "[1] to add another bird" << endl;
                                    
                                    cin >> administratorChoice2;
                                    if (administratorChoice2 == 0) {
                                         goto startOfAdministratorMenu;
                                    } 
                                    
                                    else if (administratorChoice2 == 1) {
                                        goto startOfCreateNewBird;
                                    }

                                    else {
                                        cout << "Please put in a valid number" << endl;
                                }
                            }while (administratorChoice2 != 0 && administratorChoice2 !=1);
                                
                                
                            }
                            
                            else if (administratorChoice == 5) {
                                goto startOfProgram;
                            }
                            

                            else {
                                cout << "Please put in a valid number" << endl;
                                    goto startOfAdministratorMenu;
                            }
                        }
                    

                    
                    if (userPasswordInput != administratorPassword) {
                        if (i<2){
                            cout<< "Wrong Password, please try again" << endl;
                            cout << "You have " << 2-i << " attempt";
                            if (i<1){
                                cout<< "s left" << endl;
                            }
                            else if (i==1){
                                cout << " left!" << endl;
                            }
                        }
                        
                    } 
                } 
                cout << "Acces denied...exiting" << endl;
                return 0;


            }        
        }   
            else {    
                cout << "Please put in a valid number" << endl;           
                    
            }
    } while (firstOption != 1 && firstOption != 2);

    return 0;
}        