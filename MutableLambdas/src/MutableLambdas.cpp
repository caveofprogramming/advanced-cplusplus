//============================================================================
// Name        : Mutable.cpp
// Author      : John Purcell
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int cats = 5;

	[cats]() mutable {
		cats = 8;
		cout << cats << endl;
	}();

	cout << cats << endl;

	return 0;
}
