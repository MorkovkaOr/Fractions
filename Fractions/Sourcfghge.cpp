#include<iostream>
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
	void set_numerator(double numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(double denominator)
	{
		this->denominator = denominator;
	}

	//				Constructors:

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
	//				Operators:
	Fractions& operator=(const Fractions& other)
	{
		this->integer_part = other.integer_part;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}


	//				Methods:

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



Fractions operator+(const Fractions& left, const Fractions& right )
{
	int left_numerator, right_numerator, left_denominator, right_denominator;
	left_numerator = left.get_numerator() + (left.get_integer_part() * left.get_denominator());
	right_numerator = right.get_numerator() + (right.get_integer_part() * right.get_denominator());
	left_denominator = left.get_denominator();
	right_denominator = right.get_denominator();
	Fractions res;
	res.set_integer_part(int((left_numerator * right_denominator + right_numerator * left_denominator)/ (right_denominator * left_denominator)));
	res.set_numerator(abs((left_numerator* right_denominator + right_numerator* left_denominator)% (right_denominator * left_denominator)));
	res.set_denominator(right_denominator* left_denominator);
	return res;
}
Fractions operator-(const Fractions& left, const Fractions& right)
{
	int left_numerator, right_numerator, left_denominator, right_denominator;
	left_numerator = left.get_numerator() + (left.get_integer_part() * left.get_denominator());
	right_numerator = right.get_numerator() + (right.get_integer_part() * right.get_denominator());
	left_denominator = left.get_denominator();
	right_denominator = right.get_denominator();
	Fractions res;
	res.set_integer_part(int((left_numerator * right_denominator - right_numerator * left_denominator) / (right_denominator * left_denominator)));
	res.set_numerator(abs((left_numerator * right_denominator - right_numerator * left_denominator) % (right_denominator * left_denominator)));
	res.set_denominator(right_denominator * left_denominator);
	return res;
}
Fractions operator*(const Fractions& left, const Fractions& right)
{
	int left_numerator, right_numerator, left_denominator, right_denominator;
	left_numerator = left.get_numerator() + (left.get_integer_part() * left.get_denominator());
	right_numerator = right.get_numerator() + (right.get_integer_part() * right.get_denominator());
	left_denominator = left.get_denominator();
	right_denominator = right.get_denominator();
	Fractions res;
	res.set_numerator(abs((left_numerator* right_numerator) % (right_denominator * left_denominator)));
	res.set_denominator(right_denominator * right_denominator);
	res.set_integer_part(int((left_numerator * right_numerator)/ (right_denominator * left_denominator)));
	return res;
}
Fractions operator/(const Fractions& left, const Fractions& right)
{
	int left_numerator, right_numerator, left_denominator, right_denominator;
	left_numerator = left.get_numerator() + (left.get_integer_part() * left.get_denominator());
	right_numerator =  right.get_denominator();
	left_denominator = left.get_denominator();
	right_denominator = right.get_numerator() + (right.get_integer_part() * right.get_denominator());
	Fractions res;
	res.set_numerator(abs((left_numerator * right_numerator) % (right_denominator * left_denominator)));
	res.set_denominator(right_denominator * right_denominator);
	res.set_integer_part(int((left_numerator * right_numerator) / (right_denominator * left_denominator)));
	return res;
}
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
	setlocale(LC_ALL, "");
	Fractions A, B, C, D, F;
	A = Fractions(2, 5, 8);
	B = Fractions(2, 5, 8);
	C = Fractions(4, 6, 8);
	D = Fractions(2, 5, 8);
	A = C + B;
	A.print();
	A = B - C;
	A.print();
	A = B * C;
	A.print();
	A = B / D;
	A.print();
}