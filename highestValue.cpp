#include <iostream>
using namespace std;

// Functie die het hoogste getal vindt
int findHighest(int numbers[], int size) {
    int highest = numbers[0]; 
    for (int i = 1; i < size; i++) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }
    return highest;
}

int main() {
    int numbers[] = {3, 12, 3, 21, 8};
    int size = 5;

    int result = findHighest(numbers, size);

    cout << "Het hoogste getal is: " << result << endl;

    return 0;
}
