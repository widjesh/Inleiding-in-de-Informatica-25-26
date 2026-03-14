#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm> // Required for std::remove_if bij function om bird te removen


using namespace std;

class Bird {
    public:
        string ID; 
        string birdName;
        string birdType;
        string birdSpecies;
        string scientificName;
        string typeOfInjury;
        string dateInAndOut;
      

        Bird() {}; //global constructor

    Bird(string ID, string birdName, string birdType, string birdSpecies, string scientificName, string typeOfInjury, string dateInAndOut) : ID(ID), birdName(birdName), birdType(birdType), birdSpecies(birdSpecies), scientificName(scientificName), typeOfInjury(typeOfInjury), dateInAndOut(dateInAndOut) {}; //constructor met parameters

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
    string ID;
    string birdName;
    string birdType;
    string birdSpecies;
    string scientificName;
    string typeOfInjury;
    string dateInAndOut;

    cout << "Enter ID" << endl;
    getline(cin >> ws, ID);
    cout << "Enter name of bird" << endl;
    getline(cin >> ws, birdName);
    cout << "Enter type of bird" << endl;
    getline(cin >> ws, birdType);
    cout << "Enter birdSpecies" << endl;
    getline(cin >> ws, birdSpecies);
    cout << "Enter scientific name" << endl;
    getline(cin >> ws, scientificName);
    cout << "Enter type of injury" << endl;
    getline(cin >> ws, typeOfInjury);
    cout << "Enter date (DD/MM/YY)" << endl;
    getline(cin >> ws, dateInAndOut);

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
            string ID = (tempID); //voor die getline hadden we voor ID een string gebruikt, we gaan deze string nu omzetten naar een integer
            birdList.push_back(Bird(ID, birdName, birdType, birdSpecies, scientificName, typeOfInjury, dateInAndOut));
        } catch (const exception& e) {
            cerr << "Error parsing line: " << line << " (" << e.what() << ")" << endl;
        }

    }

    infile.close();
    return birdList;
}


Bird birdLookupSpecific(string targetID, const string& filename ) {
    vector<Bird> birdList = birdLookupAll(filename); //je called die function om alle birds te zien
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
     return Bird();


};

/*
//De logic behind de function van removeBirdByID is hetzelfde als van birdLookupSpecific
//De gebruikt de birdLookupAll function om alle saved birds op te roepen en te zetten in een vector
//Je gaat dan door alle birds en kijken welke ID matched met de ID die is ingevoerd
//Bij birdLookupSpecific dan ga je gewoon de bird returnen die matched met de ID die je hebt ingevoerd
//Maar bij deze ga je de bird deleten uit de vector die matched met de ID die je invoerd(vandaar birdList.erase)
//en dan overwrite het de originele file met de vector waarvan de bird die je wilt is weggehaald
*/

void removeBirdByID(string targetID, const string& filename) {
    // 1. LOAD all birds into a vector
    vector<Bird> birdList = birdLookupAll(filename); 
    bool found = false;

    // 2. REMOVE the bird with the matching ID
    // We use a simple loop or std::remove_if
    for (auto it = birdList.begin(); it != birdList.end(); ++it) {
        if (it->ID == targetID) {
            cout << "Removing: " << it->birdName << " (ID: " << it->ID << ")" << endl;
            birdList.erase(it); //haalt de bird weg die matched met de ID die je hebt ingevoerd
            found = true;
            break; // Stop once we find and remove the bird
        }
    }

    if (!found) {
        cout << "Bird with ID " << targetID << " not found." << endl;
        return;
    }

    // 3. OVERWRITE the file with the updated list
    ofstream outfile(filename, ios::trunc); // 'trunc' clears the old file
    if (outfile.is_open()) {
        for (const auto& b : birdList) {
            // Save in the exact same format (ID,Name,Type...)
            outfile << b.ID << "," << b.birdName << "," << b.birdType << "," 
                    << b.birdSpecies << "," << b.scientificName << "," 
                    << b.typeOfInjury << "," << b.dateInAndOut << endl;
        }
        outfile.close();
        cout << "Database updated successfully." << endl;
    }
}

/*
de edit bird attribute function werkt met dezelfde logica als de remove bird function
roep de loadAllBirds function, kijk waar de ID'overeenkomen en dan edit je de attribute en "update" je de file door het te overwriten
*/

void editBirdAttribute(string targetID, const string& filename) {
    // 1. Load all birds into a vector
    vector<Bird> birdList = birdLookupAll(filename);
    bool found = false;

    // 2. Find the bird and let the user pick an attribute
    for (auto& b : birdList) {
        if (b.ID == targetID) {
            found = true;
            int choice;
            cout << "\nBird Found: " << b.birdName << endl;

            do{
            cout << "\nWhich attribute would you like to edit?" << endl;
            cout << "[1] ID  [2] Name  [3] Type  [4] Species  [5] Scientific Name  [6] Type of Injury  [7] Date in/out\nChoice: ";
            cin >> choice;

            if (choice >=1 && choice <=7){
            // Use getline(cin >> ws, ...) to handle spaces in user input
            if (choice == 1) { cout << "Enter new ID: "; getline(cin >> ws, b.ID); }
            else if (choice == 2) { cout << "Enter new type: "; getline(cin >> ws, b.birdName); }
            else if (choice == 3) { cout << "Enter new type: "; getline(cin >> ws, b.birdType); }
            else if (choice == 4) { cout << "Enter new species: "; getline(cin >> ws, b.birdSpecies); }
            else if (choice == 5) { cout << "Enter new type: "; getline(cin >> ws, b.scientificName); }
            else if (choice == 6) { cout << "Enter new injury: "; getline(cin >> ws, b.typeOfInjury); }
            else if (choice == 7) { cout << "Enter new dates: "; getline(cin >> ws, b.dateInAndOut); }
            
            cout << "\nAttribute updated in memory!" << endl;

           
        
            }

            else {
                cout << "\nPlease enter a valid input" << endl;
            }
            }while (choice <1 || choice >7);
        }
    }

    if (!found) {
        cout << "\nBird ID " << targetID << " not found." << endl;
        return;
    }

     // 3. Overwrite the file with the updated vector
            ofstream outfile(filename, ios::trunc); 
            for (const auto& b : birdList) {
                outfile << b.ID << "," << b.birdName << "," << b.birdType << "," 
                        << b.birdSpecies << "," << b.scientificName << "," 
                        << b.typeOfInjury << "," << b.dateInAndOut << endl;
            }
            outfile.close();
            cout << "Changes saved to " << filename << " successfully." << endl;

 
}

void exitOption(){
    cout << "Exiting the program..." <<endl;
    exit(0);
}

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
    
    cout << "WELCOME TO OUR BIRD CLINIC" << endl;
    startOfProgram:
    do{
        cout << "\nChoose one of the following options:" << endl;
        cout << "Enter [1] to lookup birds" << endl;
        cout << "Enter [2] to access birds database (Administrator Password Required)" << endl;
        cin >> firstOption;


        if (firstOption == 1 || firstOption == 2) { 

            if (firstOption == 1) {
                cout << "\nWelcome, do you want to view the whole database or search a specific bird?" << endl;
                startOflookup:
                do { //do while loop to make sure user inputs either A or ID, if not it will ask again until they do
                    cout << "\n[A] for whole database" << endl;
                    cout << "[ID] for specific bird" << endl;
                    cout << "[R] to return to main menu" << endl; // To return to main menu, we will call the main function again (So we will start the whole process again, asking for the first option and so on)
                    cin >> birdIDOrAll;

                    if (birdIDOrAll == "A") {
                        startOfA:
                        vector<Bird> myBirds = birdLookupAll("bird_objects_list_saved.txt");
                                    
                        //Check if the list is empty (in case the file didnt open)
                        if (myBirds.empty()){
                                cout << "No birds found or file could not be opened." << endl;
                        } 
                            
                        else {
                            // You can now loop through the vector to use the data
                            for (const auto& bird : myBirds){
                                cout << " Bird: " << bird.ID << " " << bird.birdName << " " << bird.birdType << " " << bird.birdSpecies << " " << bird.scientificName << " " << bird.typeOfInjury << " " << bird.dateInAndOut << endl;
                            }
                        }
                        
                        cout << "\n[0] to exit the program" << endl;                
                        cout << "[1] to go back to administrator menu" << endl;
                        
                        cin >> administratorChoice2;
                                        
                        if (administratorChoice2 == 1) {
                            goto startOflookup;
                        }

                        else if (administratorChoice2==0){
                            exitOption();
                        }

                        else {
                            while (true){
                                cout << "\nPlease put in a valid number" << endl;
                                cout << "[0] to exit the program" << endl;
                                cout << "[1] to go back to administrator menu" << endl;
                                
                                cin >> administratorChoice2;
                                                
                                if (administratorChoice2 == 1) {
                                        goto startOflookup;
                                }
                                 else if (administratorChoice2==0){
                                   exitOption();
                                }
                            }
                        } 
                    } 
                    
                    else if(birdIDOrAll == "ID") {
                        startOfID:
                        string searchID;
                        cout << "\nPlease enter the ID of the bird you would like to view:"<< endl;
                        cin >> searchID;

                        Bird foundbird = birdLookupSpecific(searchID, "bird_objects_list_saved.txt");
                        cout << foundbird.ID << " " << foundbird.birdName << " " << foundbird.birdType << " " << foundbird.birdSpecies << " " << foundbird.scientificName << " " << foundbird.typeOfInjury << " " << foundbird.dateInAndOut << endl;

                        do {     
                            cout << "\n[0] to exit the program" << endl;
                            cout << "[1] to go back to administrator menu" << endl;
                            cout << "[2] to continue" << endl;
                                        
                            cin >> administratorChoice2;
                            if (administratorChoice2 == 1) {
                                goto startOflookup;
                            } 
                                        
                            else if (administratorChoice2 == 2) {
                            goto startOfID;
                            }

                            else if (administratorChoice2==0){
                            exitOption();
                            }

                            else {
                                    cout << "\nPlease put in a valid number" << endl;
                            }
                            
                        }while (administratorChoice2 != 0 && administratorChoice2 !=1 && administratorChoice2!=2);
                                    
                    } 
                    
                    else if (birdIDOrAll == "R") {
                        goto startOfProgram;
                    } 
                    
                    else {
                        cout << "\nPlease put in a valid input:" << endl;
                    }   
                } while (birdIDOrAll != "A" && birdIDOrAll != "ID" && birdIDOrAll != "R");
            } 
            
            else if (firstOption == 2) {
                for(i=0;i<3;i++){
                    cout << "\nPlease enter the administrator Password(Case Sensitive!)" << endl;
                    cin >> userPasswordInput;

                    if (userPasswordInput==administratorPassword){
                        break;
                    }
                    if (userPasswordInput != administratorPassword) {
                        if (i<2){
                            cout<< "\nWrong Password, please try again" << endl;
                            cout << "You have " << 2-i << " attempt";
                            if (i<1){
                                cout<< "s left" << endl;
                            }
                            else if (i==1){
                                cout << " left!" << endl;
                            }
                        }else if (i==2){
                            cout << "\nAcces denied...exiting" << endl;
                            return 0;
                        }
                        
                    } 
                } 
              
                    

                if (userPasswordInput == administratorPassword) {
                    cout << "\nWelcome administrator" << endl;
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
                        
                        //Check if the list is empty (in case the file didnt open)
                        if (myBirds.empty()){
                            cout << "No birds found or file could not be opened." << endl;
                        } 
                        else {
                            // You can now loop through the vector to use the data
                            for (const auto& bird : myBirds){
                                cout << " Bird: " << bird.ID << " " << bird.birdName << " " << bird.birdType << " " << bird.birdSpecies << " " << bird.scientificName << " " << bird.typeOfInjury << " " << bird.dateInAndOut << endl;
                            }
                        }
                        do{
                            cout << "\n[0] to exit the program" << endl;
                            cout << "[1] to go back to administrator menu" << endl;
                        
                                
                            cin >> administratorChoice2;
                                    
                            if (administratorChoice2 == 1) {
                                    goto startOfAdministratorMenu;
                            }

                            else if (administratorChoice2==0){
                                exitOption();
                            }

                            else {
                                cout << "Please put in a valid number" << endl;
                            } 
                        }while (administratorChoice2!=0 && administratorChoice2!=1);
                    } 
                        
                    else if (administratorChoice == 2) {
                        startOfCreateNewBird:
                        Bird bird(createNewBird());
                        saveBird(bird, "bird_objects_list_saved.txt");
                        bird.display(); 
                        

                        do {     
                            cout << "\n[0] to exit the program" << endl;
                            cout << "[1] to go back to administrator menu" << endl;
                            cout << "[2] to add another bird" << endl;
                            cin >> administratorChoice2;

                            if (administratorChoice2 == 1) {
                                goto startOfAdministratorMenu;
                            } 
                            
                            else if (administratorChoice2 == 2) {
                                goto startOfCreateNewBird;
                            }

                            else if (administratorChoice2==0){
                            exitOption();
                            }

                            else {
                                    cout << "Please put in a valid number" << endl;
                            }
                        }while (administratorChoice2 != 0 && administratorChoice2 !=1 && administratorChoice2 !=2);
                            
                            
                    }

                    else if (administratorChoice == 3) {
                        startOfRemoveBird:
                        string IDToRemove;
                        cout << "\nEnter the ID of the bird you wish to remove: ";
                        cin >> IDToRemove;

                        removeBirdByID(IDToRemove, "bird_objects_list_saved.txt");

                        do {
                            cout << "\n[0] to exit the program" << endl;     
                            cout << "[1] to go back to administrator menu" << endl;
                            cout << "[2] to remove another bird" << endl;

                            cin >> administratorChoice2;
                            if (administratorChoice2 == 1) {
                                goto startOfAdministratorMenu;
                            } 
                            
                            else if (administratorChoice2 == 2) {
                                goto startOfRemoveBird;
                            }

                            else if (administratorChoice2==0){
                            exitOption();
                            }

                            else {
                                    cout << "\nPlease put in a valid number" << endl;
                            }
                        } while (administratorChoice2 != 0 && administratorChoice2 !=1 && administratorChoice2!=2);
                    }

                    else if (administratorChoice == 4) {
                        startOfEditBird:
                        string IDToEdit;
                        cout << "\nEnter the ID of the bird you wish to edit:" << endl;
                        cin >> IDToEdit;

                        editBirdAttribute(IDToEdit, "bird_objects_list_saved.txt");

                        do {
                            cout << "\n[0] to exit the program" << endl;     
                            cout << "[1] to go back to administrator menu" << endl;
                            cout << "[2] to edit another bird" << endl;

                            cin >> administratorChoice2;
                            if (administratorChoice2 == 1) {
                                goto startOfAdministratorMenu;
                            } 
                            
                            else if (administratorChoice2 == 2) {
                                goto startOfEditBird;
                            }

                            else if (administratorChoice2==0){
                            exitOption();
                            }

                            else {
                                    cout << "\nPlease put in a valid number" << endl;
                            }
                        } while (administratorChoice2 != 0 && administratorChoice2 !=1 && administratorChoice2!=2);
                    }

                        
                    else if (administratorChoice == 5) {
                        goto startOfProgram;
                    }
                    

                    else {
                        cout << "\nPlease put in a valid number" << endl;
                        goto startOfAdministratorMenu;
                    }
                }
            }   
        } 
        
        else {
            cout << "\nPlease put in a valid number" << endl;
        }           

    } while (firstOption != 1 && firstOption != 2);

    return 0;
}        