#define _CRT_SECURE_NO_WARNINGS
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
		fin.getline(temp, 200, ',');//YHOO
		symbol = new char[strlen(temp) + 1];
		strcpy(symbol, temp); //this is dynamic array
		fin >> side;
		fin.getline(temp, 200, ',');
		fin >> price;
		fin.getline(temp, 200, ',');
		fin >> quantity;
		fin.getline(temp, 200, ',');
		fin >> orderid;
		fin.getline(temp, 200, '\n');
		orders[j] = new Order(symbol, side, price, quantity, msg_type, orderid);
		delete[] symbol;
		orders[j]->write_console();
	}
	fin.clear(); fin.close();

	orders[num_orders]->count_msg_types(orders, num_orders);

	for (int j = 0; j < num_orders; j++) {
		delete orders[j]; 
	}
	delete[] orders;
	system("pause");
	return 0;
}
