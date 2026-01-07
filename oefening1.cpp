#include <iostream>

using namespace std;
// y = ax + b
// a = 2
// b = 3
// x = 1
// y = 2*1 + 3 = 5 (DataType: in)
// Assumption: x is an integer, b is an integer, a is an integer

int calculateValueY(int x, int a, int b){
    return a*x+b; // Implementatie
}

int main(){
    cout << "Hello World, starting my first function call!" << endl;
    int y;
    int x;
    int a;
    int b;
    cout << "Please enter value for x: ";
    cin >> x;
    cout << "Please enter value for a: ";
    cin >> a;
    cout << "Please enter value for b: ";
    cin >> b;
    y = calculateValueY(x,a,b); // Use user-provided values for x, a, b
    cout << "The value of y is: " << y << ", thank you." << endl;
    return 0;
}