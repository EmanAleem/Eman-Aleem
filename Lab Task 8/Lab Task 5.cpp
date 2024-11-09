#include <iostream>
using namespace std;
int main() 
{
    int number, sum = 0;
    cout << "Enter a number: ";
    cin >> number;
    for (int temp = number; temp > 0; temp /= 10) {
        int digit = temp % 10;
        for (int i = 0; i < 1; i++) {
            sum += digit;
        }
    }
    cout << "Sum of the digits of " << number << " is: " << sum << endl;
    return 0;
}

