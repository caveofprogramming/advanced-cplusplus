//============================================================================
// Name        : Function.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void test(int value) {
	cout << "Hello: " << value << endl;
}

int main() {
	test(7);

	void (*pTest)(int) = test;

	pTest(8);



	return 0;
}
