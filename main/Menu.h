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

	while (it != it_end)
	{
		bool found = false;
		std::string coefficient = it->str(1) + it->str(2), exponent = it->str(5) + it->str(6);
		if(coefficient.empty())
			coefficient = "1";
		if(it->str(3).empty() && exponent.empty())
			exponent = "0";
		if(!it->str(3).empty() && exponent.empty())
			exponent = "1";

		if(coefficient != "0")
		{
			std::cout << "Co: " << coefficient << ' ' << "Exp: " << exponent << '\n';
		}
		++it;
	}

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
