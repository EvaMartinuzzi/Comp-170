#include "order.h"
#include <fstream> 
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream fin;
	char temp[200];
	int num_orders = 0;

	int quantity;
	int orderid;
	char msg_type;
	char side;
	double price;
	char * symbol;
	symbol = new char[4];

	Order ** orders; 
	fin.open("orders.txt");
	fin >> num_orders;
	fin.getline(temp, 200, '\n');
	orders = new Order *[num_orders];

	for(int j=0; j<num_orders; j++)
	{
		fin >> msg_type;
		fin.getline(temp, 200, ',');
		//symbol[0] = 'Y'; //get rid of this
		//symbol[1] = 'H';
		//symbol[2] = 'O';
		//symbol[3] = 'O';
		for (int j = 0; j < 4; j++) {
			fin >> symbol[j];
			strcpy(symbol, temp); //unsafe variable
		}
		fin.getline(temp, 200, ',');
		fin >> side;
		fin.getline(temp, 200, ',');
		fin >> price;
		fin.getline(temp, 200, ',');
		fin >> quantity;
		fin.getline(temp, 200, ',');
		fin >> orderid;
		fin.getline(temp, 200, '\n');
		orders[j]->write_console(symbol, side, price, quantity, msg_type, orderid);
	}
		orders[num_orders]->count_msg_types(orders, num_orders);

	for (int j = 0; j < num_orders; j++) {
		delete[] orders[j]; 
	}
	delete[] orders;
	fin.clear(); fin.close();
	system("pause");
	return 0;
}
