/*
*  Created on: Jan 16, 2014
*      Author: mdcsaenz
*/

#include <cmath>
#include <time.h>
#include <iostream>
using namespace std;

char get_comp_val()
{
	int i;
	i = rand() % 3;
	if (i == 0) {
		return 'r';
	}
	if (i == 1) {
		return 's';
	}
	return 'p';
}

int main()
{
	char comp_val; 
		char user_val = 'a';
	srand(time(NULL));
	cout << "We are going to play a game!";
	cout << "Rock, Scissors, Paper!";

	while (user_val != 'q') 
	{
		cout << "On the count of three, you'll choose." << endl;
		cout << "For Rock, type an r. For Scissors, s. For Paper, p. or to quit, q";
		cout << "\n" << "1.. 2.. 3.." << endl;
		cin >> user_val; /*reverse arrows*/

		comp_val = get_comp_val();

		if (comp_val == user_val) cout << "TIE!" << endl; 
		else if (user_val == 'q') cout << "Quitting thanks for playing" << endl;
		else
		{
			if (comp_val == 'r')
			{
				if (user_val == 's') cout << "Rock beats Scissor. You lose.\n";
				else cout << "Paper beats Rock. You win!\n";
			}
			if (comp_val == 's') /*put in quotes*/
			{
				if (user_val == 'r') cout << "Rock beats Scissor. You lose!\n";
				else cout << "Scissor beats Paper. You lose.\n";
			}
			if (comp_val == 'p')
			{
				if (user_val == 's') cout << "Scissor beats Paper. You win!\n";
				else cout << "Paper beats Rock. You lose.\n";
			}
		}
	}
	return 0; 
}
