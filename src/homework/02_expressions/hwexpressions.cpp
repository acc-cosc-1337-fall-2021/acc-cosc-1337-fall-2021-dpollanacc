#include "expressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

const double tax_rate = 0.0675;

//function get_sales_tax returns double and takes double as param
double get_sales_tax_amount(double meal_amount) {
	return meal_amount * tax_rate;
}

//function get_tip_amount returns double and takes two doubles as params
double get_tip_amount(double meal_amount, double tip_rate) {
	return meal_amount * tip_rate;
}






