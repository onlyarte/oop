#include "Triangle.h"

int main(void)
{
	//test data
	Point a, b(2, 8), c(4, 0), d(100, 100), f(300, 1);

	Triangle abc(a, b, c), bcd(b, c, d), cdf(c, d, f);

	//points, segments and lengths
	cout << abc.apexA() << endl;
	cout << bcd.side_a() << endl;
	cout << "length a of abc: " << abc.length_a() << endl;

	//perimenter and area
	cout << "perim of abc: " << abc.perimeter() << endl;
	cout << "area of abc: " << abc.area() << endl;

	//changing data
	abc.apexA() = d;
	cout << abc << endl;

	return 0;
}