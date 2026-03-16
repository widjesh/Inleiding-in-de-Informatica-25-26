#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

string caesar_cipher(string word, bool decrypt)
{
    int shift = 17;

    if (decrypt)
        shift = -17;

    int i;
    char currentChar;
    int value;

    for (i = 0; i < word.length(); i++)
    {
        currentChar = word[i];

        if (currentChar >= 'a' && currentChar <= 'z')
        {
            value = currentChar + shift;

            while (value > 'z')
                value -= 26;

            while (value < 'a')
                value += 26;

            word[i] = value;
        }

        else if (currentChar >= 'A' && currentChar <= 'Z')
        {
            value = currentChar + shift;

            while (value > 'Z')
                value -= 26;

            while (value < 'A')
                value += 26;

            word[i] = value;
        }

        else if (currentChar >= '0' && currentChar <= '9')
        {
            value = currentChar + shift;

            while (value > '9')
                value -= 10;

            while (value < '0')
                value += 10;

            word[i] = value;
        }
    }

    return word;
}

int main()
{
    int choice;
    string website, password;

    map<string, string> passwords;

    string masterUser, masterPass;
    string storedUser, storedPass;

    ifstream authCheck("Master_Authentication.txt");

    if (!authCheck)
    {
        cout << "No master account found. Create one.\n";

        ofstream createAuth("Master_Authentication.txt");

        cout << "Create Master Username: ";
        getline(cin, masterUser);

        cout << "Create Master Password: ";
        getline(cin, masterPass);

        masterPass = caesar_cipher(masterPass, false);

        createAuth << masterUser << endl;
        createAuth << masterPass << endl;

        createAuth.close();

        cout << "Master account created.\n";
    }

    authCheck.close();

    ifstream authRead("Master_Authentication.txt");

    getline(authRead, storedUser);
    getline(authRead, storedPass);

    authRead.close();

    cout << "Login Required\n";

    cout << "Username: ";
    getline(cin, masterUser);

    cout << "Password: ";
    getline(cin, masterPass);

    masterPass = caesar_cipher(masterPass, false);

    if (masterUser != storedUser || masterPass != storedPass)
    {
        cout << "Authentication Failed\n";
        return 0;
    }

    ifstream readPasswords("Stored_Passkeys.txt");

    if (readPasswords)
    {
        while (readPasswords >> website >> password)
        {
            passwords[website] = password;
        }
    }

    readPasswords.close();

    while (true)
    {
        cout << "\nPassword Manager\n";
        cout << "1. Add Password" << endl;
        cout << "2. View Password" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter website: ";
            getline(cin, website);

            cout << "Enter password: ";
            getline(cin, password);

            password = caesar_cipher(password, false);

            passwords[website] = password;

            ofstream writePasswords("Stored_Passkeys.txt");

            for (auto &p : passwords)
            {
                writePasswords << p.first << " " << p.second << endl;
            }

            writePasswords.close();

            cout << "Password stored successfully.\n";
        }

        else if (choice == 2)
        {
            cout << "Enter website: ";
            getline(cin, website);

            bool found = false;

            for (auto &p : passwords)
            {
                if (p.first == website)
                {
                    string decrypted = caesar_cipher(p.second, true);

                    cout << "Password: " << decrypted << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "No password found for " << website << endl;
            }
        }

        else if (choice == 3)
        {
            cout << "Exiting program.\n";
            break;
        }

        else
        {
            cout << "Invalid Choice. Please try again.\n";
        }
    }

    return 0;
}
