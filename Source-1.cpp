#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Function prototypes
bool alreadyAdded(int, int);
bool alreadyAddedGuess(int, int);
bool comparePowerball();
void guessNumbers();
void generateNumbers();
int compareArray();

//Global variables
const int SIZE = 5;
int winningNumbers[SIZE];
int guessedNumbers[SIZE];
int winningPowerball;
int guessedPowerball;

bool alreadyAdded(int value, int index) {

	//Iterates through array to check if number is already present
	//If so, generates new number in parent function
	for (int i = 0; i < index; i++) {
		if (winningNumbers[i] == value) {
			return true;
		}
	}
	return false;

}

bool alreadyAddedGuess(int value, int index) {

	//Iterates through array to check if number is already present
	//If so, prompts user to enter new number in parent function
	for (int i = 0; i < index; i++) {
		if (guessedNumbers[i] == value) {
			return true;
		}
	}
	return false;

}

void generateNumbers() {
	
	//Loop for populating winning numbers
	for (int i = 0; i < 5; i++) {
		
		//Generates random number
		srand(time(NULL));		
		int num = 0 + rand() % 9;
		
		//Checks to see if number is already in array. Ignores first random number generated
		while (i != 0 && alreadyAdded(num, i)) {
			num = 0 + rand() % 9;
		}
		
		//If not a duplicate, writes to index
		winningNumbers[i] = num;
		
	}
	
	//Generates powerball seperate from array to avoid duplicate match results
	winningPowerball = 0 + rand() % 100;
}

void guessNumbers() {

	//Initializes local variables
	int digit;
	int powerball;

	cout << "Enter your five lottery numbers (range of 0 to 9)" << endl;

	//Loop to populate guessed number array
	for (int i = 0; i < 5; i++) {
		do {
			cout << "Number " << (i + 1) << ": ";
			cin >> digit;

			//Input validation loop to not exceed range bounds and to ensure digit is not repeated
			if (digit < 0 || digit > 9) {
				cout << "Invalid number!\n"
					<< "Pick a number in the range of 0 to 9." << endl;
			}
			else if (alreadyAddedGuess(digit, i)) {
				cout << "Invalid number!\n"
					<< "You can not have duplicate numbers in your guess." << endl;
			}

		} while (digit < 0 || digit > 9 || alreadyAddedGuess(digit, i));

		//Assigns non-repetitive inbound digit to guessed array
		guessedNumbers[i] = digit;
	}

	//Enter powerball guess seperate from array
	cout << "Enter your Powerball guess (range of 0 to 100): ";

	do {
		cin >> powerball;

		//Validation loop
		if (powerball < 0 || powerball > 100) {
			cout << "Invalid number!\n"
				<< "Pick a number in the range of 0 to 100." << endl;
		} 
	} while (powerball < 0 || powerball > 100);

	guessedPowerball = powerball;

}

int compareArray() {
	int correct = 0;

	//Compares the two arrays and increments 'correct' if number is present in both loops
	for (int x : winningNumbers) {
		for (int y : guessedNumbers) {
			if (x == y) {
				correct++;
			}
		}
	}
	return correct;
}

bool comparePowerball() {
	
	//Compares both powerball numbers
	if (winningPowerball == guessedPowerball) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	//Function calls
	generateNumbers();
	guessNumbers();
	int result = compareArray();

	//Displays winning numbers then player's guessed numbers
	cout << "The winning numbers are: " << endl;
	for (int x : winningNumbers) {
			cout << x << " ";
	}
	cout << winningPowerball << endl;

	cout << "Your guesses are: " << endl;
	for (int y : guessedNumbers) {
		cout << y << " ";
	}
	cout << guessedPowerball << endl;

	//Displays results of comparison and gives 'reward'
	cout << "You got " << result << " matches!" << endl;
	if (result == 3) {
		cout << "You get 1 credit!" << endl;
		}
	else if (result == 4) {
		cout << "You get 5 credits!" << endl;
	}
	else if (result == 5) {
		cout << "You won the jackpot!" << endl;
	}

	//True-false flag for comparing powerball numbers
	if (comparePowerball()) {
		cout << "You got the powerball!" << endl;
	}

	return 0;
}