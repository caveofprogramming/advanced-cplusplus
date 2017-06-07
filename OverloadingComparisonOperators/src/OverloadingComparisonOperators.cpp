//============================================================================
// Name        : Overloading.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complex.h"
using namespace std;
using namespace caveofprogramming;

int main() {

	Complex c1(3, 2);
	Complex c2(3, 3);

	if (c1 == c2) {
		cout << "Equal" << endl;
	} else {
		cout << "Not equal" << endl;
	}

	if (c1 != c2) {
		cout << "Not equal" << endl;
	} else {
		cout << "Equal" << endl;
	}

	return 0;
}
