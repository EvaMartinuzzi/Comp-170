#include <iostream>
#include <time.h>

using namespace std;

bool set_ships(int **& matrix, int size, int num1);

int main()
{
	int ** B;
	int size, num_ships, row, col;
	int num_hits = 0;
	int i = 0;
	cout << "***** Battleship *****" << endl;
	cout << "How many rows/columns is the board? ";
	cin >> size;

	B = new int *[size];
	for (int i = 0; i<size; i++) {
		B[i] = new int[size];
	}

	for (i = 0; i < size; i++) {
		B[i][i] = 0;
	}

	cout << "A " << size << "x" << size << " board has been created.\n";
	cout << "How many ships? ";
	cin >> num_ships;
	set_ships(B, size, num_ships);

	while (num_hits != num_ships)
	{
		cout << "What row: ";
		cin >> row;
		cout << "What col: ";
		cin >> col;
		row = row - 1;
		col = col - 1;

		if (B[row][col] == 1) {
			cout << "It's a hit!" << endl;
			num_hits++;
		}
		else {
			cout << "You missed! Try again." << endl;
		}
	}

cout << "You sunk my battleships!" << endl;

for (int j = 0; j<size; j++) {
	delete[] B[j];
}

delete [] B;
system("pause");
return 0;
}

bool set_ships(int **& B, int size, int num_ships) {
	int ships = 0;
	srand(time(NULL));
	int row;
	int col;
	while (ships <= num_ships) {
		row = rand() % size;
		col = rand() % size;

		if (B[row][col] == 0) {
			B[row][col] = 1;
		}
		ships++;
	}
	return true;
}
