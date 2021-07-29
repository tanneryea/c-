#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 500;

	srand(time(0));

	int x = (rand() % (MAX_VALUE - MIN_VALUE +1)) + MIN_VALUE;
	int y = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	int answer = x + y;
	int solution;

	cout << right << setw(5) << x << endl;
	cout << "+" << right << setw(4) << y << endl;
	cout << "-----" << endl;
	cin >> solution;

	if (solution == answer)
	{
		cout << "Correct answer!" << endl;
	}
	else
	{
		cout << "Incorrect answer, sorry!" << endl;
	}

	system("pause");
	return 0;
}
