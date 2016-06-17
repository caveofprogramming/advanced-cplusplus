//============================================================================
// Name        : Static.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
public:
	virtual void speak() {
		cout << "parent!" << endl;
	}
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main() {

	Parent parent;
	Brother brother;

	Parent *ppb = &brother;

	Brother *pbb = dynamic_cast<Brother *>(ppb);

	if (pbb == nullptr) {
		cout << "Invalid cast" << endl;
	} else {
		cout << pbb << endl;
	}

	return 0;
}
