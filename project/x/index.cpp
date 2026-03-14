#include <iostream>
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
int main(){
    cout<< "Hello World" << endl;
}
