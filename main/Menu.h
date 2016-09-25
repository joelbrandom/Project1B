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
	Menu();
	void showOptions();
	void ui_addPolynomial();
	void ui_clearPolynomial();
};
