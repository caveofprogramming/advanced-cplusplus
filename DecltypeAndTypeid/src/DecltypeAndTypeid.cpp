//============================================================================
// Name        : DecltypeAndTypeid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Decltype and typeid in C++
//============================================================================

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
};

int main() {
	int value;
	string str;
	Test test;

	cout << typeid(value).name() << endl;
	cout << typeid(str).name() << endl;
	cout << typeid(test).name() << endl;

	decltype(str) name = "Bob";

	cout << name << endl;
	return 0;
}
