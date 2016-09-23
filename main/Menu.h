#include <iostream>
#include <string>
#include <regex>
#include "Term.h"

using namespace std;

class Menu
{
public:
	void showOptions()
	{
		int option;
		list<Term> listOfTerms;
		cout << "Please select an option from below:\n";
		cout << "0: Add polynomial\n";
		cout << "1: Quit\n";
		cin >> option;

		switch (option)
		{
		case 0:
			addPolynomial2(listOfTerms);
			break;
		case 1:
			quitProgram2();
			break;
		}
	}

	void addPolynomial2(list<Term>& list)
	{
		string input, formatted_input;
		regex find_for_pattern("(^|\\+|-)([xX])"), term_match("(-)?([0-9]+)([xX])?(\\^(-)?(\\d+))?");
		formatted_input = regex_replace(input, find_for_pattern, "$011$2", std::regex_constants::format_default);
		sregex_iterator it(input.begin(), input.end(), term_match), it_end;
		Polynomial list;

		while (it != it_end)
		{
			bool found = false;
			std::string coefficient = it->str(1) + it->str(2);
			std::string exponent = it->str(5) + it->str(6);
			if (!it->str(1).empty() && it->str(2).empty()) coefficient = "-1";
			if (coefficient.empty()) coefficient = "1";
			if (exponent.empty() && !letter) exponent = "0";
			if (exponent.empty() && letter) exponent = "1";
			if (coefficient != "0")
			{
				Term term(std::stoi(coefficient), std::stoi(exponent));
				for (Polynomial::iterator i = list.begin(); i != list.end(); ++i)
				{
					if (i->Exponent() == term.Exponent())
					{
						found = true;
						i->addCoefficient(term.Coefficient());
					}
				}
				if (found == false) list.push_back(term);
			}
			++it;
		}
	}

	void quitProgram2()
	{
		return 0;
	}
}

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

	regex find_for_pattern("(^|\\+|-)([xX])"), term_match("(-)?([0-9]+)([xX])?(\\^(-)?([0-9]+))?");

	formatted_input = std::regex_replace(input, find_for_pattern, "$011$2", regex_constants::format_default);
	sregex_iterator it(formatted_input.begin(), formatted_input.end(), term_match), it_end;

	while (it != it_end)
	{
		bool found = false;
		std::string coefficient = it->str(1) + it->str(2), exponent = it->str(5) + it->str(6);
		if (coefficient.empty())
			coefficient = "1";
		if (it->str(3).empty() && exponent.empty())
			exponent = "0";
		if (!it->str(3).empty() && exponent.empty())
			exponent = "1";

		if (coefficient != "0")
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