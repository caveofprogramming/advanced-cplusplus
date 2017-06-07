//============================================================================
// Name        : Template.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

template<class T, class K>
class Test {
private:
	T obj;
	K id;
public:
	Test(T obj, K m_id) {
		this->obj = obj;
		this->id = m_id;
	}

	void print() {
		cout << obj << ": " << id << endl;
	}
};

int main() {

	Test<string, int> test1("Hello", 5);
	test1.print();

	Test<string, double> test2("Hello again", 4.0);
	test2.print();

	return 0;
}
