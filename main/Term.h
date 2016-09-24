#include <regex>
#include <list>
#include <iostream>

using namespace std;

class Term
{
private:
	int coefficient;
	int exponent;
public:
	Term(int co, int exp) : coefficient(co), exponent(exp)
	{ }

	bool operator<(Term t) const
	{
		return this->exponent < t.exponent;
	}

	void operator+(Term term)
	{
		this->coefficient += term.coefficient;
	}

	int Exponent() const
	{
		return this->exponent;
	}

	int Coefficient() const
	{
		return this->coefficient;
	}

	void addCoefficient(int co)
	{
		coefficient += co;
	}

	string toString(bool showpos) const
	{

		string str = "";
		if (coefficient != 0) {
			if (showpos && coefficient > 0) {
				str.append("+");
			}
			if (coefficient != 1 && coefficient != -1)
				str.append(std::to_string(coefficient));
			if (coefficient == 1 && exponent == 0)
				str.append("1");
			if (coefficient == -1)
				str.append("-");
			if (exponent != 0 && exponent != 1) {
				str.append("X^");
				str.append(std::to_string(exponent));
			}
			if (exponent == 1)
				str.append("X");
		}
		return str;
	}
};

struct compareTermDegree {
	bool operator()(const Term& lh, const Term& rh) {
		return lh.Exponent() > rh.Exponent();
	}
};
typedef list<Term> Polynomial;

/* Adds user inputted polynomial to Polynomial list
@param list The list to add user inputted polynomial to
*/
void addPolynomial(Polynomial& list)
{
	string input, formatted_input, invalid_test;
	cout << "Enter polynomial:" << endl;
	cin >> input;

	/* find_for_pattern regex searches for new line, + or - followed by x or X
	and regex_replace uses it to place a 1 before terms without explicit coefficients
	*/

	/* term_match searches for each term of polynomial, after regex_replace all
	terms now have a coefficient. We can use this constant pattern to find each term
	*/
	regex find_for_pattern("(^|\\+|-)([xX])"), term_match("(-)?([0-9]+)([xX])?(\\^(-)?([0-9]+))?"),
	invalid_match("(^|\\+|-)?([0-9]+)([xX])?(\\^(-)?([0-9]+))?");
	formatted_input = regex_replace(input, find_for_pattern, "$011$2", regex_constants::format_default);
	invalid_test = regex_replace(formatted_input, invalid_match, "", regex_constants::format_default);

	/* Check if there is leftover input after removing all term_matches.
	If so, then there is invalid input
	*/
	if (invalid_test != "")
		throw invalid_argument("Invalid input.\n");

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

void clearPolynomial(Polynomial& list)
{
	list.clear();
}

/*
void outputList(Polynomial & l)
{
	compareTermDegree cp;
	l.sort(cp);

	Polynomial::const_iterator it;
	bool showpos = false;
	for (it = l.begin(); it != l.end(); ++it)
	{
		cout << it->toString(showpos);

		if (!showpos)
		{
			showpos = true;
		}
	}
	std::cout << endl;
}

void fillList(std::string& inputt)
{
	std::regex find("(^|\\+|-)([xX])"), match("(-)?([0-9]+)([xX])?(\\^(-)?(\\d+))?");
	std::string input;
	input = std::regex_replace(inputt, find, "$011$2", std::regex_constants::format_default);
	std::sregex_iterator it(input.begin(), input.end(), match), it_end;
	Polynomial list;

	while (it != it_end)
	{
		bool found = false;
		std::string coefficient = it->str(1) + it->str(2);
		std::string exponent = it->str(5) + it->str(6);
		char letter = *it->str(3).c_str();
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
	outputList(list);
}

void processTerms()
{
	std::string input;
	std::cin >> input;
	fillList(input);
}
*/

/*
int main()
{
//string str = "2X^2-3X+1";
string str = "-6x^7-8X^10+2X^2-3X+1-0X^8+11X^21";
fillList(str);
return 0;
}
*/
