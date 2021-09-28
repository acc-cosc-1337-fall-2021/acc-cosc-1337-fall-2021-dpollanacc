//write include statement for decisions header
#include<string>

using std::string;


//Write code for function(s) code here

string get_letter_grade_using_if(int grade) {
    string letter_grade;

    letter_grade = "Invalid Entry"; 

    // less than 60 is F
    if ((grade >= 0) && (grade <= 59)) {
        letter_grade = "F";
    }

    // Between 60 and 69 is D
    if ((grade >= 60) && (grade <= 69)) {
        letter_grade = "D";
    }

    // Between 70 and 79 is C
    if ((grade >= 70) && (grade <= 79)) {
        letter_grade = "C";
    }

    // Between 80 and 89 is B
    if ((grade >= 80) && (grade <= 89)) {
        letter_grade = "B";
    }

    // Above 90 is A
    if ((grade >= 90) && (grade <= 100)) {
        letter_grade = "A";
    }
    return letter_grade;
}

string get_letter_grade_using_switch(int grade) {
    string letter_grade;

    switch (grade) {
    case 0 ... 59:
        letter_grade = 'F';
        break;
    case 60 ... 69:
        letter_grade = "D";
        break;
    case 70 ... 79:
        letter_grade = "C";
        break;
    case 80 ... 89:
        letter_grade = "B";
        break;
    case 90 ... 100:
        letter_grade = "A";
        break;
    default:
        letter_grade = "Invalid Entry";
    }

     return letter_grade;
}