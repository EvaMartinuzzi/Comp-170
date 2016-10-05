#include <iostream>
#include <cstring>
#include "cqueue2.h"

using namespace std;

int main()
{
	int i;
	string Temp;
	int n;
	int num_members;

	cout << "*********************** The Josephus Problem ***********************" << endl;
	cout << "A group of soldiers is surrounded. There is no hope for victory." << endl;
	cout << "There is but a single horse available for escape and many soldiers." << endl;
	cout << "Who will survive??" << endl;

	cout << "How many soldiers are there: ";
	cin >> num_members;
	Cqueue2 Q(num_members);
	for (i = 0; i < num_members; i++) {
		cout << "What is soldier #" << i + 1 << "'s name? ";
		cin >> Temp;
		Q.Add(Temp);
	}

	cout << "We'll be counting around a circle. What is n: ";
	cin >> n;

	string Name;
	if (Q.Is_Empty()) {
		Q.write_Cqueue_to_Console();
	}
	while (Q.get_size()>1)
	{
		Name = Q.remove_nth_member(n);	//function removes the member
		cout << endl << Name << " has been removed from the circle.\n";

		cout << "Now the queue contains: ";
		Q.write_Cqueue_to_Console();
	}
	if (Q.get_size() == 1) {
		cout << endl;
		cout << "Congratulations, " << Q.getFront() << " you get to ride to safety!" << endl;
	}
	system("pause");
	return 0;
}




#pragma once
/*********************************************
This is a modification of the Cqueue class
for the Josephus Problem. The class variable
Queue is an array of strings (for names).
*********************************************/
#include <cstring>
#include <string>
using namespace std;

class Cqueue2
{
private:
	int Rear, Front;
	string * Queue;
	int Max;
	int Size;
public:
	Cqueue2(int n = 0);
	~Cqueue2();
	int Is_Empty();
	int Is_Full();
	void Add(string Element);
	string Delete();
	string getFront();
	void write_Cqueue_to_Console();         //write all of the class variables to the console
	int get_size();                         //this function is added to Cqueue2 so can tell when have 1 member in the queue
	string remove_nth_member(int n);        //for Josephus problem to remove a member
};


Cqueue2::Cqueue2(int n)
{
	Size = 0;
	Rear = Front = -1;
	Max = n;
	Queue = new string[n];        //the Queue array is dynamically allocated
}

Cqueue2::~Cqueue2()
{
	delete[] Queue;               //have to delete dynamically allocated memory
}

int Cqueue2::Is_Empty()
{
	if (Size == 0) return true;
	else return false;
}

int Cqueue2::Is_Full()
{
	if (Size == Max) return true;
	else return false;
}

void Cqueue2::Add(string Element)
{
	if (!Is_Full()) Rear = (Rear + 1) % Max;
	Queue[Rear] = Element;
	Size++;
}

string Cqueue2::Delete()
{
	if (Is_Empty())
	{
		cout << "The Cqueue is empty.";
		return "";
	}
	else
	{
		Front = (Front + 1) % Max;
		Size--;
		return Queue[Front];
	}
}

string Cqueue2::getFront()
{
	int Temp1;
	if (Is_Empty())
	{
		return "";
	}
	else
	{
		Temp1 = (Front + 1) % Max;
		return Queue[Temp1];
	}
}

void Cqueue2::write_Cqueue_to_Console()         //write all of the class variables to the console
{
	int i;
	int Temp;
	if (Is_Empty())
		cout << "Queue is empty.\n";
	else
	{
		for (i = 1; i <= Size; i++)
		{
			Temp = (Front + i) % Max;
			cout << Queue[Temp] << " ";
		}
		cout << endl;
	}
}

int Cqueue2::get_size()
{
	return Size;
}
//2: Do this 
string Cqueue2::remove_nth_member(int n)
{
	string name;
	int index = (n%Size) - 1;
	name = Queue[(n - 1) % Size];
	int start;
	int i;
	start = n%Size;

	string * TempQ = new string[Size - 1];

	for (i = 0; i < Size - 1; i++)
	{
		index = (start + i) % Max;
		TempQ[i] = Queue[index];
	}
	
	delete[] Queue;
	Size--;
	Queue = new string[Size];
	for (i = 0; i < Size; i++)
	{
		Queue[i] = TempQ[i];
	}
	delete[] TempQ;
	Max--;
	return name;
}
