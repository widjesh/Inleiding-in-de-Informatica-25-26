#include <iostream>
#Include     
using namespace std;

string caesar_cipher(string word, int shift){
    int i;              // loop counter used to go through the word
    char currentChar;   // stores the current character from the word
    int value;          // numerical ASCII value used for shifting

    
    for (i = 0; i < word.length(); i++)
    {
        currentChar = word[i];

        
        if (currentChar >= 'a' && currentChar <= 'z')
        {
            value = currentChar + shift;

            while (value > 'z')
                value = value - 26;

            while (value < 'a')
                value = value + 26;

            word[i] = value;
        }

        
        else if (currentChar >= 'A' && currentChar <= 'Z')
        {
            value = currentChar + shift;

            while (value > 'Z')
                value = value - 26;

            while (value < 'A')
                value = value + 26;

            word[i] = value;
        }

       
        else if (currentChar >= '0' && currentChar <= '9')
        {
            value = currentChar + shift;

            while (value > '9')
                value = value - 10;

            while (value < '0')
                value = value + 10;

            word[i] = value;
        }
    }

    return word;
}
int main() {
    int choice;  
    string website, password;
    map<string, string> passwords;
  
    while (true) {
        cout << "\nPassword Manager\n";
        cout << "1. Add Password" << endl;
        cout << "2. View Password" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter website: ";
            getline(cin, website);
            cout << "Enter password: ";
            getline(cin, password);
            passwords[website] = password;
        }
        else if (choice == 2) {
            cout << "Enter website: ";
            getline(cin, website);
            bool found = false;
            for (auto& p : passwords) {
                if (p.first == website) {
                    cout << "Password: " << p.second << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No password found for " << website << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid Choice. Please try again." << endl;
        }
    }
    return 0;
}
}
