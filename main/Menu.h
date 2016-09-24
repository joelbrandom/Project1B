#include <iostream>
#include <string>
#include <regex>
#include <limits>

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

		while (option < 2)
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
			try
			{
				cin >> option;
				if (!cin)
					throw invalid_argument("Invalid input.\n");
			}
			catch (const invalid_argument& e)
			{
				cout << e.what();
				cin.clear();
				option = -1;
			}
			cin.ignore(numeric_limits<int>::max(), '\n');

			switch (option)
			{
				/* Option 0: Add polynomial to current polynomial
				*/
				case 0:
					try
					{
						ui_addPolynomial();
					}
					catch (const invalid_argument& e)
					{
						cout << e.what();
					}
					break;
				/* Option 1: Clear polynomial
				*/
				case 1:
					ui_clearPolynomial();
					break;
				/* If option entered is not an available option, do nothing
				*/
				default:
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
