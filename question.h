#include <string>

class Question {
public:
	int firstNumber;
	int secondNumber;
	char op;

	int guessedAnswer;
	int correctAnswer;
	double timeTaken;

	bool failed;

	Question();

	std::string ToString();
	std::string ToStringWasWrong();
private:

};
