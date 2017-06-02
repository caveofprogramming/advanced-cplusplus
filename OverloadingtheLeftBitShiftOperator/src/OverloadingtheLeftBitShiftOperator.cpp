//============================================================================
// Name        : Overloading the Left Bit Shift Operator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Overloading the left bit shift (for printing). 
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Test
{
	int id; 
	string name;

public:
	Test() : id(0), name("")
	{
		
	}

	Test(int id, string name) : id(id), name(name)
	{
		
	}

	Test(const Test& other)
	{
		this->id = other.id;
		this->name = other.name;
	}

	const Test& operator=(const Test &other) {
		this->id = other.id;
		this->name = other.name;
		return *this;
	}
	
	friend ostream& operator<<(ostream &os, const Test& object) {
		os << object.id << ": " << object.name;
		return os;
	}

};

int main() {

	Test test1(10, "Mike");

	cout << test1 << endl;
	return 0;
}
