#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------------\n"

class Fractions
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	/*Point()
	{
		x = y = double();	//значение по умолчанию для double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "1argConstructor:" << this << endl;
	}*/

	Fractions(const Fractions& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fractions()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Fractions& operator=(const Fractions& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fractions& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Fractions operator++(int)
	{
		Fractions old = *this;
		x++;
		y++;
		return old;
	}

	//				Methods:
	double distance(const Fractions& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));//Square Root
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;	//объявление переменной 'a' типа 'int'
//type name;
	Point A;//объявление переменной 'A' типа 'Point'
			//объявление объекта 'A' типа 'Point'
			//объявление экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;	//Default constructor
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;	//Default constructor
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
	cout << delimiter << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
	Point A;		//Default constructor
	A.print();
	cout << double() << endl;

	Point B(2, 3);
	B.print();

	Point C = 5;
	C.print();

	Point D = B;	//CopyConstructor
	D.print();

	Point E;
	E = D;			//CopyAssignment (=)
	E.print();
#endif // CONSTRUCTORS_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	c = a + b;

	Fractions A, B, C;
	A = B = C = Fractions(2, 3);

	C.print();
	C++;
	C.print();
}