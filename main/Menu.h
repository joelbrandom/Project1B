#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Menu
{
private:
	Polynomial listOfTerms;
public:
	/* Construct a Menu
	*/
	Menu() {};
	void showOptions()
	{
		int option = 0;

		while (option < 2 && option >= 0)
		{
			cout << "Your current polynomial is: ";
			if (listOfTerms.empty())
				cout << "empty\n";
			else
				outputList(listOfTerms);
			cout << "Please select an option from below:\n";
			cout << "0: Add polynomial to current polynomial\n";
			cout << "1: Clear polynomial\n";
			cout << "2: Quit\n";
			cin >> option;

			switch (option)
			{
			case 0:
			try
			{
				ui_addPolynomial();
			} catch (const invalid_argument& e)
			{
				cout << e.what();
			}
				break;
			case 1:
				ui_clearPolynomial();
				break;
			}
		}
	}

	void ui_addPolynomial()
	{
		addPolynomial(listOfTerms);
	}

	void ui_clearPolynomial()
	{
		clearPolynomial(listOfTerms);
	}
};
