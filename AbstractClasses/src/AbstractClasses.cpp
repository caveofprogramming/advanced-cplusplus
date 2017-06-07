//============================================================================
// Name        : Abstract.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void run()=0;
	virtual void speak() = 0;
};

class Dog: public Animal {
public:
	virtual void speak() {
		cout << "Woof!" << endl;
	}
};

class Labrador: public Dog {
public:
	Labrador() {
		cout << "new labrador" << endl;
	}
	virtual void run() {
		cout << "Labrador running" << endl;
	}
};

class Husky: public Dog
{
public:
	Husky()
	{
		cout << "new husky" << endl;
	}
	virtual void run()
	{
		cout << "Husky running" << endl;
	}
};

void test(Animal &a) {
	a.run();
}

int main() {

	Labrador lab;
	lab.run();
	lab.speak();

	Animal *animals[5];
	animals[0] = &lab;

	animals[0]->speak();

	Husky husky;

	test(lab);
	test(husky);

	return 0;
}
