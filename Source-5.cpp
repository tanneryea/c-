#include <iostream>
using namespace std;

double testAverage(int[], int);

//Function for calculating average
double testAverage(int grades[], int size) {
	int i, sum = 0;
	double avg;
	
	//Try block to create sum of test scores
	try {
		for (i = 0; i < size; ++i) {
			if (grades[i] <= 100 && grades[i] >= 0) {
				sum += grades[i];
			}
			else {
				//Exception is thrown if grade is below 0 or above 100
				throw (grades[i]);
			}
		}
		//Calculates average of scores
		avg = double(sum) / size;
		return avg;
	}
	//Catch block for thrown error
	catch (int grade) {
		cout << "Grade entered is not possible with grading rubric.\n";
		cout << "Grade entered is: " << grade << endl;
	}


}

int main(){

	const int SIZE = 5;

	//Two gradebooks, one with value that will throw error
	int gradeBook1[SIZE] = { 100, 50, 75, 62, 95 };
	int gradeBook2[SIZE] = { 40, 75, 100, 16, -5 };

	cout << "Calculating average of first grade book..." << endl;
	cout << "The average is: " << testAverage(gradeBook1, SIZE) << endl;

	cout << "Calculating average of second grade book. Error should be thrown..." << endl;
	testAverage(gradeBook2, SIZE);

	return 0;

}