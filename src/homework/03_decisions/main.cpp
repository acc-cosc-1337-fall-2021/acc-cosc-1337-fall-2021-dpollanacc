//write include statements
#include<iostream>
#include<string>
#include"decisions.h"

using std::cout;
using std::cin;
using std::string;

int main()
{


    int user_choice;
    int numeric_grade;
    string letter_grade;
   
    //Display the menu
    cout << "     MAIN MENU     \n\n";
    cout << "1-Letter grade using if\n";
    cout << "2-Letter grade using switch\n";
    cout << "3-Exit\n\n";

    cout << "Please make a selection: ";
    cin >> user_choice;

    if (user_choice == 1) {
        cout << "\nEnter the student's grade: ";
        cin >> numeric_grade;
        letter_grade = get_letter_grade_using_if(numeric_grade);
        cout << "Student's grade calculated using if statement\n";
    }
    if (user_choice == 2) {
        cout << "\nEnter the student's grade: ";
        cin >> numeric_grade;
        letter_grade = get_letter_grade_using_switch(numeric_grade);
        cout << "Student's grade calculated using switch statement\n";
    }
    if (user_choice == 3) {
        cout << "Goodbye\n";
        return 0;
    }
    // Display the letter grade and exit program
    cout << "The student recieved a letter grade of: " << letter_grade;
    return 0;
}
