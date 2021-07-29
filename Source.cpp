#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
	// Constants for math values
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 500;

	// Constants for menu
	const int ADD_CHOICE = 1;
	const int SUB_CHOICE = 2;
	const int MUL_CHOICE = 3;
	const int DIV_CHOICE = 4;
	const int QUIT_CHOICE = 5;

	// Other variables
	int choice; // Menu choice
	int correct = 0; // Number of correct answers
	int attempt = 0; // Number of attempted questions
	double solution; // Solution for question
	double answer; // Correct answer to question
	string symbol; // Display operator
	
	do
	{

		// Menu display
		cout << "Choose the type of problem you want to solve\n"
			<< "1. Addition\n"
			<< "2. Subtraction\n"
			<< "3. Multiplication\n"
			<< "4. Division\n"
			<< "5. Quit Program\n"
			<< "Enter your choice: ";
		cin >> choice;

		// Validation

		while (choice < ADD_CHOICE || choice > QUIT_CHOICE)
		{
			cout << "Please enter a valid option: ";
			cin >> choice;
		}

		if (choice != QUIT_CHOICE)
		{
			// Initializes numbers
			srand(time(0));
			double x = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
			double y = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

			switch (choice) // Calculates solution
			{
				case ADD_CHOICE:
					answer = x + y;
					symbol = "+";
					break;
				case SUB_CHOICE:
					answer = x - y;
					symbol = "-";
					break;
				case MUL_CHOICE:
					answer = x * y;
					symbol = "*";
					break;
				case DIV_CHOICE:
					answer = x / y;
					symbol = "/";
					break;
			}
			
			// Displays equation and asks for input
			cout << right << setw(5) << x << endl;
			cout << symbol << right << setw(4) << y << endl;
			cout << "-----" << endl;
			cin >> solution;

			// Feedback for answer, increments score
			if (solution == answer)
			{
				cout << "Correct answer!" << endl;
				correct++;
				attempt++;
			}
			else
			{
				cout << "Incorrect answer, sorry! The correct answer is " << setprecision(2) << answer << endl;
				attempt++;
			}
		}
	} while (choice != QUIT_CHOICE);

	cout << "Your score is " << correct << "/" << attempt << endl; //Displays score

	return 0;
}