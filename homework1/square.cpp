#include <iostream>
#include "square.h"

using namespace std;

Square::Square(int l)
{
	if(l<=0){
		cout << "Length must be a positive integer" << endl;
	}
	else
	{
		length=l;
	}
}

int Square::get_length()
{
	return length;
}


int Square::get_area()
{
	return length*length;
}
