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
			if (coefficient == -1)
				str.append("-");
			if (exponent != 0) {
				str.append("X^");
				str.append(std::to_string(exponent));
			}
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