//============================================================================
// Name        : Functors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Functors in C++.
//============================================================================

#include <iostream>

using namespace std;

struct Test
{
	virtual bool operator()(string &text) = 0;
};

struct MatchTest : Test 
{
	virtual bool operator()(string &text){
		return text == "lion";
	}
};

struct MyMatchTest : Test
{
	virtual bool operator()(string &text) {
		return text == "text";
	}
};

void check(string text, Test &t)
{
	if(t(text))
	{
		cout << "Text matches!" << endl;
	}
	else
	{
		cout << "No match." << endl;
	}
}

int main() {
	
	MatchTest pred;
	string value = "lion";
	
	cout << pred(value) << endl;

	check(value, pred);

	MyMatchTest myPred;
	check(value, myPred);

	return 0;
}
