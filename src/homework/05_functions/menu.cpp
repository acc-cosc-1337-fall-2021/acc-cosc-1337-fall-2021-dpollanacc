#include<iostream>
#include<string>

using std::string;

int draw_menu() {
    int user_choice;
    std::cout << "Main Menu\n\n";
    std::cout << "1- Get GC Content\n";
    std::cout << "2- Get DNA Complement\n";
    std::cout << "3- Exit\n";
    
    std::cout << "\n\nPlease enter selection: ";
    std::cin >> user_choice;

    return user_choice;
}

string input_dna_data() {
    string data;
    std::cout << "Enter the DNA data: ";
    std::cin >> data;

    bool invalid;

    //validate string data and convert to upper case if necessary
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == 'a') {
            data[i] = 'A';
        }
        if (data[i] == 'c') {
            data[i] = 'C';
        }
        if (data[i] == 'g') {
            data[i] = 'G';
        }
        if (data[i] == 't') {
            data[i] = 'T';
        }
        //next make sure the entry is A C G or T
        if ((data[i] == 'A') || (data[i] == 'C') || (data[i] == 'G') || (data[i] == 'T')) { 
            //this only happens if one of the characters entered is valid
            invalid = false;
        } else {
            invalid = true;
        }

        //throw an exception if the user entered invalid data
        if (invalid) {
            std::cout << "The data entered could not be proccessed, please ensure data is formatted properly.\nprogram is now exiting.\n\n\n";
            throw 1;
        }
    }
    //If all letters are validated return the string
    return data;
}