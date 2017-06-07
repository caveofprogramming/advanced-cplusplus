//============================================================================
// Name        : ObjectInitialization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Test
{
	int id{ 3 };
	string name{"Mike"};

public:
	Test() = default;
	Test(const Test &other) = delete;
	Test& operator=(const Test& other) = delete;

	Test(int id) : id(id)
	{
		
	}

	void print()
	{
		cout << id << ": " << name << endl;
	}
};

int main() {

	Test test;
	test.print();

	Test test1(77);
	test1.print();
	
	/**
	 * Won't work, we deleted them. 
	 */
	//test2 = test;

	return 0;
}
