#include <iostream>
#include <string>

using namespace std;

class NoMoreGuesses
{
public:
	NoMoreGuesses() {
		message = "Out of the maximum number of guesses.";
	}

	NoMoreGuesses(string str) {
		message = str;
	}

	string what() {
		return message;
	}

private:
	string message;
};
