//============================================================================
// Name        : Parsing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {

	string filename = "stats.txt";
	ifstream input;

	input.open(filename);

	if(!input.is_open()) {
		return 1;
	}

	while(input) {
		string line;

		getline(input, line, ':');

		int population;
		input >> population;

		// input.get();
		input >> ws;

		if(!input) {
			break;
		}

		cout << "'" << line << "'" << " -- '" << population << "'" << endl;
	}

	input.close();

	return 0;
}
