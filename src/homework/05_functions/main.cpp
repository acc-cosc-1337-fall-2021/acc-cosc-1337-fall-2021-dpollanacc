#include<iostream>
#include<string>
#include"func.h"
#include"menu.h"

using std::string;
using std::cout;
using std::cin;

int main() 
{
	int user_choice = 0;
	char confirm = 'n';
	double percent_gc;
	string data;


	while ((confirm != 'Y') && (confirm != 'y')) {
		user_choice = draw_menu();
		if (user_choice == 3) {
			cout << "You selected 3-Exit\nAre you sure you want to quit the program (Y or N)?\n";
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				cout << "\nGoodbye";
				return 0;
			}
		}
		if (user_choice == 1) {
			data = input_dna_data();
			percent_gc = get_gc_content(data);
			cout << "The percentage GC content is %" << percent_gc << ".\n";
		}
		if (user_choice == 2) {
			data = input_dna_data();
			data = get_dna_complement(data);
			cout << "\nThe DNA Complement is: " << data << ".\n";
		} 
		
	}
	return 0;
}