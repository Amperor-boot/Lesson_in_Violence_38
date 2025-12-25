#include "Header.h"

//Getting access to the identifiers in the std namespace without needing to prefix them with std::
using namespace std;

class Fraction
{
private:
	double numerator, denominator;
	double quotient()
	{
		return (numerator / denominator);
	}

public:
	Fraction(double new_numerator, double new_denominator)
	{
		numerator = new_numerator;
		denominator = new_denominator;
	}

	~Fraction()
	{
		cout << "Fraction of\t" << numerator << (":") << denominator << "\tdeleted" << endl;
	}

	Fraction operator+(const Fraction& incoming)
	{
		return Fraction(numerator + incoming.numerator, denominator + incoming.denominator);
	}

	Fraction operator-(const Fraction& incoming)
	{
		return Fraction(numerator - incoming.numerator, denominator - incoming.denominator);
	}

	Fraction& operator++()
	{
		numerator++;
		denominator++;
		return *this;
	}

	Fraction& operator++(int)
	{
		return ++(*this);
	}

	Fraction& operator--()
	{
		numerator--;
		denominator--;
		return *this;
	}

	Fraction& operator--(int)
	{
		return --(*this);
	}

	bool operator==(Fraction& incoming)
	{
		return quotient() == incoming.quotient();
	}

	bool operator!=(Fraction& incoming)
	{
		return quotient() != incoming.quotient();
	}

	bool operator> (Fraction & incoming)
	{
		return quotient() > incoming.quotient();
	}

	bool operator< (Fraction & incoming)
	{
		return quotient() < incoming.quotient();
	}

	bool operator>=(Fraction& incoming)
	{
		return quotient() >= incoming.quotient();
	}

	bool operator<=(Fraction& incoming)
	{
		return quotient() <= incoming.quotient();
	}

	string print()
	{
		return to_string(static_cast<int>(numerator)) + ":" + to_string(static_cast<int>(denominator));
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE, "RU");
	SetConsoleCP(1251);		//устанавливаем кодовую страницу в поток ввода
	SetConsoleOutputCP(1251);	//устанавливаем кодовую страницу в поток вывода

	double user_numerator[2], user_denominator[2];
	for (uint16_t i = 0; i < sizeof(user_numerator) / sizeof(double); i++)
	{
		cout << "Enter the numerator of fraction[" << i << "]:\t";
		cin >> user_numerator[i];

		cout << "Enter the denominator of fraction[" << i << "]:\t";
		cin >> user_denominator[i];
	}

	Fraction f1(user_numerator[0], user_denominator[0]);
	Fraction f2(user_numerator[1], user_denominator[1]);

	std::cout << f1.print() << ((f1 == f2)	? "\t==\t" :	"\tnot ==\t") <<f2.print() << '\n';
	std::cout << f1.print() << ((f1 != f2)	? "\t!=\t" :	"\tnot !=\t") <<f2.print() << '\n';
	std::cout << f1.print() << ((f1 < f2)	? "\t<\t" :	"\tnot <\t") <<	f2.print() << '\n';
	std::cout << f1.print() << ((f1 > f2)	? "\t>\t" :	"\tnot >\t") <<	f2.print() << '\n';
	std::cout << f1.print() << ((f1 <= f2)	? "\t<=\t" :	"\tnot <=\t") <<f2.print() << '\n';
	std::cout << f1.print() << ((f1 >= f2)	? "\t>=\t" :	"\tnot >=\t") <<f2.print() << '\n';

	return EXIT_SUCCESS;
}