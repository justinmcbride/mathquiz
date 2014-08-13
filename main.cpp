#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include "NoMoreGuesses.h"
#include "question.h"

using namespace std;

struct s_answer {
	int guess;
	double time;
};

void printGameMenu() {
	cout << "The game modes are: " << endl;
	cout << "\t" << "( + ) Addition" << endl;
	cout << "\t" << "( - ) Subtraction" << endl;
	cout << "\t" << "( * ) Multiplication" << endl;
	cout << "\t" << "( / ) Division" << endl;
}

bool checkInput(int input) {
	if (input == '+' || input == '-' || input == '*' || input == '/') return true;
	else return false;
}

char inputMathType() {
	bool valid = false;
	int counter = 0;
	string inputStr;
	char input;
	while (!valid) {
		if (counter == 3) {
			cout << endl;
			printGameMenu();
			cout << "You need to enter the operator associated with the game type.." << endl;
			counter = 0;
		}
		cout << "Enter the game type you desire: ";
		getline(cin, inputStr);
		stringstream(inputStr) >> input;
		valid = checkInput(input);
		counter++;
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

s_answer askQuestion(char gameType, int first, int second) throw (NoMoreGuesses) {
	bool valid = false;
	int counter = 1;
	int maxGuesses = 3;

	string inputString;
	int guess;
	time_t start, end;

	try {
		while (!valid && counter < (maxGuesses + 1)) {
			cout << first << " " << gameType << " " << second << " = ";
			time(&start); // start timing
			getline(cin, inputString);
			stringstream ss(inputString);
			ss >> guess;
			if (!ss.fail()) {
				time(&end);
				s_answer value = {guess, difftime(end, start)};
				return value;
			}
			counter++;
		}
		throw NoMoreGuesses("Exceeded the maximum number of guesses.");
	}
	catch (...) {
		throw;
	}
}

void playGame(char gameType) {
	srand(time(NULL));

	int nQuestions = 10;
	int maxNumber = 100;

	int failedQuestions = 0;
	double totalTimeTaken = 0;

	for (int i = 0; i < nQuestions; i++) {
		int first = (rand() % (maxNumber + 1));
		int second = 0;
		s_answer returnedAnswer;
		int guess;
		double timeTaken;
		bool failed = false;

		do {
			second = (rand() % (maxNumber + 1));
		} while (second == 0 && gameType == '/');

		if (second > first) {
			int temp = first;
			first = second;
			second = temp;
		}

		int correctAnswer = parseNumbers(gameType, first, second);
		try {
			returnedAnswer =  askQuestion(gameType, first, second);
			guess = returnedAnswer.guess;
			timeTaken = returnedAnswer.time;
		} catch (NoMoreGuesses e) {
			cout << e.what() << endl;
		}

		if (guess == correctAnswer) {
			cout << "\t" << "Correct. Time taken: " << timeTaken << "seconds." << endl;
			totalTimeTaken += timeTaken;
		} else if (!failed) {
			cout << "\t" << "Wrong.. the answer was " << correctAnswer << "." << endl;
			totalTimeTaken += timeTaken;
		} else if (failed) {
			failedQuestions++;
		}

	}
}

int main() {
	cout << "Welcome to the game.." << endl;
	printGameMenu();
	char gameType = inputMathType();
	playGame(gameType);
	return 0;
}

