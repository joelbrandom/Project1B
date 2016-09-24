#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Menu
{
public:
	/* Construct a Menu
	*/
	Menu() {};
	void showOptions()
	{
		const int NUM_OPTIONS = 2;
		int option = 0;
		Polynomial listOfTerms;

		while (option == 0)
		{
			cout << "Your current polynomial is: ";
			if (listOfTerms.empty())
				cout << "empty\n";
			else
				outputList(listOfTerms);
			cout << "Please select an option from below:\n";
			cout << "0: Add polynomial to current polynomial\n";
			cout << "1: Quit\n";
			cin >> option;

			switch (option)
			{
			case 0:
				addPolynomial(listOfTerms);
				break;
			case 1:
				break;
			}
		}
	}

	/* Adds user inputted polynomial to Polynomial list
	@param list The list to add user inputted polynomial to
	*/
	void addPolynomial(Polynomial& list)
	{
		string input, formatted_input;
		cout << "Enter polynomial:" << endl;
		cin >> input;

		/* find_for_pattern regex searches for new line, + or - followed by x or X
		and regex_replace uses it to place a 1 before terms without explicit coefficients
		*/

		/* term_match searches for each term of polynomial, after regex_replace all
		terms now have a coefficient. We can use this constant pattern to find each term
		*/
		regex find_for_pattern("(^|\\+|-)([xX])"), term_match("(-)?([0-9]+)([xX])?(\\^(-)?([0-9]+))?");
		formatted_input = regex_replace(input, find_for_pattern, "$011$2", regex_constants::format_default);
		sregex_iterator it(formatted_input.begin(), formatted_input.end(), term_match), it_end;

		while (it != it_end)
		{
			bool found = false;

			/*
			it->str(n) for n =
			1 = - or nothing (sign of coefficient)
			2 = Absolute value of coefficient
			5 = - or nothing (sign of exponent)
			6 = Absolute value of exponent
			*/

			string coefficient = it->str(1) + it->str(2);
			string exponent = it->str(5) + it->str(6);
			char letter = *it->str(3).c_str();

			/* If it->str(1) is not empty but it->str(2) is empty,
			the coefficient is negative but not explicit, it is -1
			*/
			if (!it->str(1).empty() && it->str(2).empty()) coefficient = "-1";
			if (coefficient.empty()) coefficient = "1";

			/* If the exponent is empty, and there's no x or X,
			the exponent is actually 0
			*/
			if (exponent.empty() && !letter) exponent = "0";

			/* If the exponent is empty, but there is an x or X,
			the exponent is actually 1
			*/
			if (exponent.empty() && letter) exponent = "1";

			/* If the coefficient is not 0, make a Term from the coefficient and exponent
			and then add it to the list of Terms
			*/
			if (coefficient != "0")
			{
				Term term(stoi(coefficient), stoi(exponent));
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

	/* Outputs Polynomial list as string
	@param list The Polynomial list to be outputted
	*/
	void outputList(Polynomial& list)
	{
		compareTermDegree cp;
		list.sort(cp);

		Polynomial::const_iterator it;
		bool showpos = false;
		for (it = list.begin(); it != list.end(); ++it)
		{
			cout << it->toString(showpos);

			if (!showpos)
			{
				showpos = true;
			}
		}
		cout << endl;
	}
};
