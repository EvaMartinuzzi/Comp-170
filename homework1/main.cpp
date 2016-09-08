#include <iostream>
#include "square.h"
#include "rectangle.h"

using namespace std;
int main()
{
	Rectangle r (5,3);
	cout << "Width is " ;
	cout << r.get_width() << endl;
	cout << "Length is ";
	cout << r.get_length() << endl;
	cout << "Area is ";
	cout << r.get_area() << endl;
	return 1;

	Square s (5);
	cout << "Square Length is ";
	cout << s.get_length() << endl;
	cout << "Square Area is ";
	cout << s.get_area() << endl;
	return 1;
}
