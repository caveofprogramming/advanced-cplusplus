//============================================================================
// Name        : Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>
void print(T n) {
	cout << n << endl;
}

int main() {
	print<string>("Hello");
	print<int>(5);

	print("Hi there");

	return 0;
}
