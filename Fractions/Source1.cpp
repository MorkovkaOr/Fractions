#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fractions
{
	double integer_part;
	double numerator;
	double denominator;
public:
	double get_integer_part()const
	{
		return integer_part;
	}
	double get_numerator()const
	{
		return numerator;
	}
	double get_denominator()const
	{
		return denominator;
	}
	void set_integer_part(double integer_part)
	{
		this->integer_part = integer_part;
	}
	void set_y(double numerator)
	{
		this->numerator = numerator;
	}
	void set_y(double denominator)
	{
		this->denominator = denominator;
	}
Fractions(int integer_part = 0, double numerator = 0, double denominator = 0)
{
	this->integer_part = integer_part;
	this->numerator = numerator;
	this->denominator = denominator;

	cout << "Constructor:\t" << this << endl;
}
~Fractions()
{
	cout << "Destructor:\t" << this << endl;
}
Fractions& operator=(const Fractions& other)
{
	this->integer_part = other.integer_part;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}


Fractions operator-(const Fractions other)
{
	this->integer_part -= other.integer_part;
	this->numerator -= other.numerator;
	while (numerator < 0)
	{
		integer_part--;
		numerator += denominator;
	}
	return *this;
}
Fractions operator*(const Fractions other)
{
	
	this->numerator = (other.numerator+(other.denominator * other.integer_part))*(this->numerator+(this->denominator * this->integer_part));
	this->denominator *= other.denominator;
	cout << numerator << " " << denominator << endl;
	integer_part = int(numerator / denominator);
	numerator = numerator - (integer_part * denominator);
	return *this;
}
Fractions operator/(const Fractions other)
{
	double left_numerator, right_numerator, left_denominator, right_denominator;
	left_numerator = this->numerator + (this->integer_part * this->denominator);
	right_numerator = other.numerator + (other.integer_part * other.denominator);
	left_denominator = this->denominator;
	right_denominator = other.denominator;
	this->numerator = left_numerator * right_denominator;
	this->denominator = left_denominator * right_numerator;
	integer_part = int(numerator / denominator);
	numerator = numerator - (integer_part * denominator);
	return *this;
}

Fractions operator+(const Fractions& left)
{
	Fractions res;
	res.set_integer_part(left.get_integer_part() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

void print()const
{
	if (numerator == 0)
	{
		cout << integer_part << endl;
	}
	else
	{
		cout << integer_part << " " << numerator << "/" << denominator << endl;
	}
}
};
void main()
{
	setlocale(LC_ALL, "");
	Fractions A,B,C,D,F;
	A = Fractions(2, 5, 8);
	B = Fractions(2, 5, 8);
	C = Fractions(2, 5, 8);
	D = Fractions(2, 5, 8);
	F = Fractions(4, 6, 78);
	A.print();
	A = A - B;
	A.print();
	A = C * C;
	A.print();
	A = D / F;
	A.print();
	B.print();
	C.print();
	D.print();
	F.print();
}