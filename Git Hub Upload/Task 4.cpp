#include <iostream>
using namespace std;
int main() 
{
 int choice;
 do {
 cout << "\nMenu:\n";
 cout << "1. Print Hello\n";
 cout << "2. Print World\n";
 cout << "3. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Hello" << endl;
 break;
 case 2:
 cout << "World" << endl;
 break;
 case 3:
 cout << "Exiting program." << endl;
 break;
 default:
 cout << "Invalid choice. Try again." << endl;
 }
 } while (choice != 3);
 return 0;
}

