//============================================================================
// Name        : RingBuffer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class Test
{
public:
	Test(initializer_list<string> texts)
	{
		for(auto value : texts)
		{
			cout << value << endl;
		}
	}

	void print(initializer_list<string> strings)
	{
		for (auto value : strings)
		{
			cout << value << endl;
		}
	}
};
int main() {
	
	vector<int> numbers{ 1, 3, 4, 6 };
	cout << numbers[2] << endl;

	Test test{ "apple", "orange", "banana" };

	test.print({ "one", "two", "three", "four" });


	return 0;
}
