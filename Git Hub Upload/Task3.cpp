#include <iostream>
using namespace std;
int main() { 
 int secretNumber =67; 
 int userGuess;
 cout << "Guess the number between 1 and 100!" << endl;
 do {
 cout << "Enter your guess: ";
 cin >> userGuess;
 if (userGuess < secretNumber) {
 cout << "Too low! Try again." << endl;
 } else if (userGuess > secretNumber) {
 cout << "Too high! Try again." << endl;
 } else {
 cout << "Congratulations! You guessed the secret number!" << endl;
 }
 } while (userGuess != secretNumber);
 return 0;
}

