#include <iostream>
using namespace std;
int main() {
 int var = 5; 
 int *pointVar; 
 pointVar = &var; 
 cout << "var = " << var << endl;
 cout << "Address of var (&var) = " << &var << endl;
 cout << "pointVar = " << pointVar << endl;
 cout << "Content of address pointed to by pointVar (*pointVar) = " << 
*pointVar << endl;
 cout << "Enter new value for var: ";
 cin >> *pointVar;
 cout << "Updated value of var = " << var << endl;
 return 0;
}
