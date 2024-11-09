#include <iostream>
using namespace std;
int main() 
{
    int number, factorial = 1;
    cout << "Enter a number: ";
    cin >> number;
    for (int i = 1; i <= number; i++) {
        for (int j = 0; j < 1; j++) {
            factorial *= i;
        }
    }
    cout << "Factorial of " << number << " is: " << factorial << endl;
    return 0;
}

