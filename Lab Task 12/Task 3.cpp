#include <iostream>
using namespace std;
int square(int n) {
 return n * n;
}
int main() {
 int (*squarePtr)(int); 
 squarePtr = square; 
 int num;
 cout << "Enter a number: ";
 cin >> num;
 int result = squarePtr(num); 
 cout << "Square of " << num << " is: " << result << endl;
 return 0;
}


