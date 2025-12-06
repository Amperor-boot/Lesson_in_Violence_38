#include "Header.h"

//Getting access to the identifiers in the std namespace without needing to prefix them with std::
using namespace std;

class ComplexNumber
{
private:
	double re, im;
	double z()
	{
		return sqrt(pow(re, 2) + pow(im, 2));
	}

public:
	ComplexNumber(double new_re, double new_im)
	{
		re = new_re;
		im = new_im;
	}

	~ComplexNumber()
	{
		cout << "The complex number\t" << re << (im < 0 ? "" : "+") << im << "i\tdeleted" << endl;
	}

	ComplexNumber operator+(const ComplexNumber& incoming)
	{
		return ComplexNumber(re + incoming.re, im + incoming.im);
	}

	void show_complex_number()
	{
		cout << re << (im < 0 ? "" : "+") << im << "i" << endl;
	}

	double get_sum()
	{
		return z();
	}
};

int main(int argc, char** argv)
{
	ComplexNumber complex_number_0(2, 0);
	complex_number_0.show_complex_number();
	cout << "Z = " << complex_number_0.get_sum() << endl;

	ComplexNumber complex_number_1(3, 0);
	complex_number_1.show_complex_number();
	cout << "Z = " << complex_number_1.get_sum() << endl;

	ComplexNumber complex_number_2(complex_number_0 + complex_number_1);
	complex_number_2.show_complex_number();
	cout << "Z = " << complex_number_2.get_sum() << endl;
	
	return EXIT_SUCCESS;
}