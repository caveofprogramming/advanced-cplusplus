//============================================================================
// Name        : RingBuffer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "ring.h"
using namespace std;

int main() {

	ring<string> textring(3);

	textring.add("one");
	textring.add("two");
	textring.add("three");

	// C++ 98 style
	for(ring<string>::iterator it = textring.begin(); it != textring.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	// C++ 11 style
	for(auto val : textring)
	{
		cout << val << endl;
	}

	return 0;
}
