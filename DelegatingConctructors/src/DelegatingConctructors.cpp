//============================================================================
// Name        : Delegating.cpp
// Author      : John Purcell
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
	int dogs{5};
	string text{"hello"};

public:
	Parent(): Parent("hello") {
		cout << "No parameter parent constructor" << endl;
	}

	Parent(string text) {
		cout << "string parent constructor" << endl;
	}
};

class Child: public Parent {
public:
	Child() = default;
};

int main() {
	Parent parent("Hello");
	Child child;
	return 0;
}
