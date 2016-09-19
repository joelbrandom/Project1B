#include <iostream>
#include <string>
#include <regex>

using namespace std;

void showMenu();

void quitProgram()
{
	return;
}

void addPolynomial()
{
	string input, formatted_input;
	cout << "Enter a polynomial:\n";
	cin >> input;

	std::regex find_for_pattern("(^|\\+|-)([xX])"), term_match("(-)?([0-9]+)([xX])?(\\^(-)?([0-9]+))?");

	formatted_input = std::regex_replace(input, find_for_pattern, "$011$2", std::regex_constants::format_default);
	std::sregex_iterator it(formatted_input.begin(), formatted_input.end(), term_match), it_end;

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
