#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


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

void saveBird( const Bird& bird, const string& filename) {
    ofstream outfile(filename, ios::app);

    if(outfile.is_open()) {
        outfile << bird.ID << "," << bird.birdName << ","<< bird.birdType<< ","<< bird.birdSpecies << "," << bird.scientificName << "," << bird.typeOfInjury << "," << bird.dateInAndOut << endl;
        cout << "\nSaved " << bird.birdName << " to " << filename << endl;

    } else{
        cout << "\n Error, Please contact support";
    }      
}
    

   
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
    cin >> birdType;
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

vector<Bird> birdLookupAll(const string& filename) {
    vector<Bird> birdList;
    ifstream infile(filename);

    if(!infile.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return birdList;
    }

    string line;
    while (getline(infile, line)) {
        if (line.empty()) continue; //Skip empty lines

        stringstream ss(line); //ss zorgt ervoor dat we de lange zin met komma's kunnen omzetten naar individuele woorden
        string tempID, birdName, birdType, birdSpecies, scientificName, typeOfInjury, dateInAndOut;

        //nu wordt er een onderscheid gemaakt van de woorden. de woorden zijn opgeslagen met een komma tussen hun, dus we zeggen gebruik die komma om een onderscheid te maken tussen die woorden
        getline(ss, tempID, ',');
        getline(ss, birdName, ',');
        getline(ss, birdType, ',');
        getline(ss, birdSpecies, ',');
        getline(ss, scientificName, ',');
        getline(ss, typeOfInjury, ',');
        getline(ss, dateInAndOut, ',');

        try {
            int ID = stoi(tempID); //voor die getline hadden we voor ID een string gebruikt, we gaan deze string nu omzetten naar een integer
            birdList.push_back(Bird(ID, birdName, birdType, birdSpecies, scientificName, typeOfInjury, dateInAndOut))
        } catch (const exception& e) {
            cerr << "Error parsing line: " << line << " (" << e.what() << ")" << endl
        }

    }

    infile.close();
    return birdList;
}


Bird birdLookupSpecific(int targetID, const string& filename ) {
    vector<Bird> birdList = birdlookupAll(filename); //je called die function om alle birds te zien
    bool found = false;

    // loop through the vector to find the matching id
    for (const auto& b : birdList) {
        if (b.ID == targetID) {
            cout << "\n--- BIRD FOUND ---" << endl;
            return b;
            found = true;
            break; // Exit loop once found
        }
    }
    if(!found){
        cout << "\nError : Bird with ID "<< targetID <<" not found in the database."<< endl;
    }
    //if !found krijg je een illegal instruction error, dus might make a dummy bird to return

};




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
                    int searchID;
                    cout << "please enter the ID of the bird you would like to view"<< endl;
                    cin >> searchID;

                    Bird foundbird = birdlookupspecific(searchID, "bird_objects_list_saved.txt");
                    cout << foundBird.ID << " " << foundbird.birdName << " " << foundbird.birdType << " " << foundbirdd.birdSpecies << " " << foundbird.birdSpecies << " " << foundbird.typeOfInjury << " " << foundbird.dateInAndOut << endl;
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
                                vector<Bird> myBirds = birdLookupAll("bird_objects_list_saved.txt");
                                
                                //Checkk if the list is empty (in case the file didnt open)
                                if (myBirds.empty()){
                                    cout << "No birds found or file could not be opened." << endl;
                                } else {
                                    // You can now loop through the vector to use the data
                                    for (const auto& bird : myBirds){
                                        cout << " Bird Name: " << bird.ID << " " << bird.birdName << endl;
                                    }
                                }
                            } 
                            
                            else if (administratorChoice == 2) {
                               
                                Bird bird(createNewBird());
                                saveBird(bird, "bird_objects_list_saved.txt");
                                bird.display(); 
                                

                              do {     
                                    cout << "\n[0] to go back to administrator menu" << endl;
                                    cout << "[1] to add another bird" << endl;
                                    
                                    cin >> administratorChoice2;
                                    if (administratorChoice2 == 0) {
                                         goto startOfAdministratorMenu;
                                    } 
                                    
                                    else if (administratorChoice2 == 1) {
                                       // goto startOfCreateNewBird;
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