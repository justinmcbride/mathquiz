#include <sstream>
#include <string>
#include "question.h"

Question::Question() {
	// nothing to do really
}

std::string Question::ToString() {
	std::stringstream ss;
	ss << firstNumber << op << secondNumber << " = " << correctAnswer;
	return ss.str();
}