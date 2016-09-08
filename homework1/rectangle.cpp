#include <iostream>
#include "rectangle.h"

using namespace std;

//This is your class that has a scope of Header Rectangle
Rectangle::Rectangle(int l, int w)
{
	if(l<=0){
		cout << "Length must be a positive integer" << endl;
	}
	else
	{
		if(w<=0){
			cout << "Width must be a positive integer" << endl;
		}
		else
		{
			length=l;
			width=w;
		}
	}
}

int Rectangle::get_length()
{
	return length;
}

int Rectangle::get_width()
{
	return width;
}

int Rectangle::get_area()
{
	return length*width;
}
