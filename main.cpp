#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

static 

void printGameMenu() {
	cout << "The game modes are: " << endl;
	cout << "\t" << "1. Addition" << endl;
	cout << "\t" << "2. Subtraction" << endl;
	cout << "\t" << "3. Multiplication" << endl;
	cout << "\t" << "4. Division" << endl;
}

bool checkInput(int input) {
	if (input == 1 || input == 2 || input == 3 || input == 4) return true;
	else return false;
}


int inputMathType() {
	bool valid = false;
	int counter = 0;
	string inputStr;
	int input;
	while (!valid) {
		counter++;
		if (counter == 3) {
			printGameMenu();
			cout << "You need to enter the number associated with the game type.." << endl;
			counter = 0;
		}
		cout << "Enter the game type you desire: ";
		getline(cin, inputStr);
		stringstream(inputStr) >> input;
		valid = checkInput(input);
	}
	return input;
}

int parseNumbers(char op, int first, int second) {
	switch(op) {
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '*':
			return first * second;
		case '/':
			return first / second;
		default:
			return 0;
	}
}

void playGame(int gameType) {

}

int main() {
	cout << "Welcome to the game.." << endl;
	printGameMenu();
	int gameType = inputMathType();
	playGame(gameType);
	return 0;
}

