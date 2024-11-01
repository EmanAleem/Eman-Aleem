#include <iostream>
using namespace std;
int main() {
 int N, sum = 0, i = 1;
 cout << "Enter the value of N: ";
 cin >> N;
 do {
 sum += i * i;
 i++;
 } while (i <= N);
 cout << "The sum of squares of the first " << N << " natural numbers is: " << 
sum << endl;
 return 0;
}
