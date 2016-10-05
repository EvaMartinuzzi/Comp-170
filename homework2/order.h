#ifndef Order_h
#define Order_h

class Order {

private:
	char * sym;
	char side;
	double price;
	int quantity;
	char message_type;
	int order_id;
public:
	Order(); //default constructor, default private variables to respective defaults, 0's for nums, NULL for char arrays, NULL terminator for char
	Order(char * s, char bs, double p, int q, char mp, int oid); //assign variables with parameters given by the user
	~Order(); //if there is any variables that are made dynamically release there memory look at rectangle_example_dynamic.cp for assistance
	bool set_symbol(char * s); //look at Examples/Week2/rectangle_example_dynamic.cpp for assistance
	bool set_side(char s); //set to new side
	bool set_orderid(int oid);//set to new orderid
	bool set_message_type(char mp); //set to new message_type
	bool set_quantity(int q); //make sure if quantity is <= 0 print a statement saying 'Can Not be less or equal to 0' return false otherwise set it return true
	bool set_price(double p); //make sure if price is <= 0.0 print a statement saying Can not be less or equal to 0.0 return false other set it return true
	char * get_symbol(); //return said var
	char get_side(); //return said var
	double get_price(); //return said var
	int get_quantity(); //return said var
	void write_console();
	void count_msg_types(Order **& orders, int num_orders);
	char get_message_type();
	char get_order_id();
};
#endif 

