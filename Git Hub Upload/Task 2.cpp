#include <iostream>
using namespace std;
int main() {
 string p = "password123"; 
 string i;
 int n = 0;
 do {
 cout << "Enter password: ";
 cin >> i;
 n++;
 if (i == p) {
 cout << "Access granted!" << endl;
 break;
 } else {
 cout << "Incorrect password. Try again." << endl;
 }
 } while (n < 3);
 if (i != p) {
 cout << "Access denied. Maximum attempts reached." << endl;
 }
 return 0;
}

