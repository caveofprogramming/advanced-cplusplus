//============================================================================
// Name        : Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T, class K>
class Test {
private:
	T obj;

public:
	Test(T obj) {
		this->obj = obj;
	}

	void print() {
		cout << obj << endl;
	}
};

int main() {

	Test<string, int> test1("Hello");
	test1.print();

	return 0;
}
