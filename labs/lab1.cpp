#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

int main (){
	int response=-1;
	srand(time(NULL));
	int answer = rand()%100+1;
	cout<<"testing, answer is "<<answer<<endl;

	while (response!=answer){
		cout<< "Guess a number between 1 and 100: "<<endl;
		cin>> response;
		if(response<answer){
			cout << "Guess higher"<<endl;
		}
		else if (response>answer){
			cout << "Guess lower"<<endl;
		}
	}
	cout<< "Congratulations!"<<endl;
	system ("pause");
	return 0;
}
