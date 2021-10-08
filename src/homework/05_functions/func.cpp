//add include statements
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

//add function code here

double get_gc_content(const string& dna) {
	double size_of_dna = dna.length();
	double gc_count = 0.0;
	//get total number of g or c values
	for (int i = 0; i < size_of_dna; i++) {
		if ((dna[i] == 'G') || (dna[i] == 'g')) {
			gc_count++;
		}
        if ((dna[i] == 'C') || (dna[i] == 'c')) {
			gc_count++;
		}
	}
	double gc_content = gc_count / size_of_dna;
	return gc_content;
}

string reverse_string(string dna) {
	int size_of_dna = dna.length();
	string dna_reversed(size_of_dna, ' ');
	for (int i = size_of_dna; i > 0; i--) {
		dna_reversed[size_of_dna - i] = dna[i - 1];
	}
	return dna_reversed;
}

string get_dna_complement(string dna) {
	int size_of_dna = dna.length();
	string dna_complement(dna.length(),' ');
	string reversed_dna = reverse_string(dna);
	char current;

	for (int i = 0; i < size_of_dna; i++) {
		current = reversed_dna[i];
		switch (current) {
		case 'C':
			dna_complement[i] = 'G';
			break;
		case 'G':
			dna_complement[i] = 'C';
			break;
		case 'A':
			dna_complement[i] = 'T';
			break;
		case 'T':
			dna_complement[i] = 'A';
			break;
		default:
			// If we hit the default it means we probably got some bad data 
			// Inform the user and throw an exception
			cout << "An error occurred when attempting to process DNA string, please check and ensure the data is formatted correctly.\nProgram ending";
			throw "Invalid data";
		}
	}
	return dna_complement;
}