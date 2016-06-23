//============================================================================
// Name        : Bind.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test {
public:
	int add(int a, int b, int c) {
		cout << a << ", " << b << ", " << c << endl;
		return a + b + c;
	}
};

int run(function<int(int, int)> func) {
	return func(7, 3);
}

int main() {

	Test test;

	auto calculate = bind(&Test::add, test, _2, 100, _1);

	cout << run(calculate) << endl;

	return 0;
}
