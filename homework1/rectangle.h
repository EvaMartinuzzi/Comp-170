class Rectangle {
	private:
		//class variables that are private below
		int length;
		int width;
	public:
		Rectangle(int l, int w); //your constructor that takes in 2 parameters
		//you accessors, this program does not have mutators
		int get_area();
		int get_length();
		int get_width();
};
