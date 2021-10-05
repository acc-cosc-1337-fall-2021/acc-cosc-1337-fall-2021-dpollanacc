//write include statements
#include<iostream>
#include<string>
#include"dna.h"

//write using statements
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
Write code that prompts user to enter 1 for factorial 
and 2 for gcd
*/

int main() 
{
	char confirmation = 'n';
	int user_choice = 0;
	int user_input_num1;
	int user_input_num2;
	int results;

	do {
		cout << "_____MAIN MENU_____"<< endl;
		cout << "1-Factorial" << endl;
		cout << "2-Greatest Common Divisor" << endl;
		cout << "3-Exit" << endl;
		cout<< "___________________________" << endl;
		cout << "Please make a selection: ";
		cin >> user_choice;
		
		//Factorial
		if (user_choice == 1) {
			cout << "What number would you like to calculate factorial for? ";
			cin >> user_input_num1;
			results = factorial(user_input_num1);
			cout << "Factorial for " << user_input_num1 << " is " << results << "." << endl;
			cout << " " << endl; // Add spacing between result and new instance of main menu
		}

		//Greatest Common Divisor
		if (user_choice == 2) {
			cout << "Please enter the first number: ";
			cin >> user_input_num1;
			cout << "Please enter the second number: ";
			cin >> user_input_num2;
			results = gcd(user_input_num1, user_input_num2);
			cout << "The greatest common divisor for " << user_input_num1 << " and " << user_input_num2 << " is " << results << "." << endl;
			cout << " " <<endl; // add spacing between results and new instance of main menu
		}

		//Exit
		if (user_choice == 3) {
			cout << "Are you sure you want to exit?   ";
			cin >> confirmation;
			if ((confirmation == 'y') || (confirmation == 'Y')) {
				cout << "Goodbye" << endl;
				return 0;
			}
		}
		
	} while ((confirmation != 'Y') && (confirmation != 'y'));
	return 0;
}