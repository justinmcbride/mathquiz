#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include "NoMoreGuesses.h"

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

int askQuestion(int first, int second) throw (NoMoreGuesses) {
	try {
		bool valid = false;
		int counter = 1;
		int maxGuesses = 3;

		string inputString;
		int guess;

		while (!valid && counter < (maxGuesses + 1)) {
			getline(cin, inputString);
			stringstream ss = stringstream(inputString);
			ss >> guess;
			if (ss.good()) return guess;
			counter++;
		}
		throw NoMoreGuesses("Exceeded the maximum number of guesses.");
	}
	catch (...) {
		throw;
	}
}

void playGame(int gameType) {
	srand(time(NULL));

	int nQuestions = 10;
	int maxNumber = 100;

	for (int i = 0; i < nQuestions; i++) {
		int first = (rand() % (maxNumber + 1));
		int second = 0;

		do {
			second = (rand() % (maxNumber + 1));
		} while (second == 0 && gameType == '/');

		if (second > first) {
			int temp = first;
			first = second;
			second = temp;
		}

		try {
			int answer = parseNumbers(gameType, first, second);
		} catch (NoMoreGuesses e) {
			cout << e.what() << endl;
		}

		if (guess == answer) {
			
		}

	}
}

int main() {
	cout << "Welcome to the game.." << endl;
	printGameMenu();
	int gameType = inputMathType();
	playGame(gameType);
	return 0;
}

