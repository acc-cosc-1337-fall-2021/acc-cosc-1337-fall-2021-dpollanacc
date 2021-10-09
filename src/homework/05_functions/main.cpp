#include<iostream>
#include<string>
#include"func.h"
#include"menu.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

enum class Menu{gc_content=1,dna_complement=2,exit_program=3};

int main() 
{
	int user_choice = 0;
	char confirm = 'n';
	double percent_gc;
	string data;


	while ((confirm != 'Y') && (confirm != 'y')) {
		user_choice = draw_menu();
		if (user_choice == static_cast<int>(Menu::gc_content)) {
			data = input_dna_data();
			percent_gc = get_gc_content(data);
			cout << "The percentage GC content is " << percent_gc << endl;
		}
		if (user_choice == static_cast<int>(Menu::dna_complement)) {
			data = input_dna_data();
			data = get_dna_complement(data);
			cout << "\nThe DNA Complement is: " << data << endl;
		} 
		if (user_choice == static_cast<int>(Menu::exit_program)) {
			cout << "You selected 3-Exit\nAre you sure you want to quit the program (Y or N)?" << endl;
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				cout << "\nGoodbye";
				return 0;
			}
		}
		
	}
	return 0;
}