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

	Complex c1(3, 4);
	Complex c2(2, 3);

	Complex c3 = c1+c2;

	cout << c1 << endl;

	cout << c1+c2+c3 << endl;

	Complex c4(4, 2);
	Complex c5 = c4+7;
	cout << c5 << endl;

	Complex c6(1, 7);

	cout << 3.2 + c6 << endl;

	cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;


	return 0;
}
