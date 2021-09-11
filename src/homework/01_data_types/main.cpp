//write include statements
#include<iostream>
#include"data_types.h"


//write namespace using statement for cout
using std::cout;
using std::cin;
using std::endl;


/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	int num;
	int num1;
	int result;

	cout << "Please enter a number:" << endl;
	cin >> num;
	result = multiply_numbers(num);
	cout << "Multiplying 5 times " << num << " results in: " << result << endl;
	num1 = 4;
	result = multiply_numbers(num1);
	cout << "Multiplying 5 times 4 results in: " << result << endl;
	

	return 0;

}