#include <iostream>
#include <string>

using namespace std;

void quitProgram()
{
	return;
}

void addPolynomial()
{
	string input;
	cout << "Enter a polynomial:\n"
	cin >> input;
	showMenu();
}

void showMenu()
{
	int option;
	cout << "Please select an option from below:\n";
	cout << "0: Add polynomial\n";
	cout << "1: Quit\n";
	cin >> option;

	switch (option)
	{
	case 0:
		addPolynomial();
		break;
	case 1:
		quitProgram();
		break;
	}
}