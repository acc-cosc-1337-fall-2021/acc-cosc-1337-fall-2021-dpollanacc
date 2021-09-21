//write include statements
#include<iostream>
#include"hwexpressions.h"


//write namespace using statement for cout
using std::cin;
using std::cout;
using std::endl;


/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	cout << "Please enter the meal amount: ";
	cin >> meal_amount;
	tax_amount = get_sales_tax_amount(meal_amount);
	cout << "Please enter the desired tip rate (example - for 15% enter 0.15): ";
	cin >> tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);
	total = meal_amount + tip_amount + tax_amount;

	//Display Receipt
	cout << "Meal Amount:   " << meal_amount << endl;
	cout << "Sales Tax:     " << tax_amount << endl;
	cout << "Tip Amount:    " << tip_amount << endl;
	cout << "_______________" << endl;
	cout << "Total:         " << total;
	

	return 0;
}
