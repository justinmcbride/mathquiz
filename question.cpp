#include <sstream>
#include <string>
#include "question.h"

Question::Question() {
	// nothing to do really
}

std::string Question::ToString() {
	std::stringstream ss;
	ss << firstNumber << op << secondNumber;
	return ss.str();
}

std::string Question::ToStringWasWrong() {
	std::stringstream ss;
	ss << "You guessed " << guessedAnswer << ", but the answer was " << correctAnswer << ".\n";
	return ss.str();
}