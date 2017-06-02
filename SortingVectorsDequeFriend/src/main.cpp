#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Test
{
	string name;
	int id;

public:
	Test(int id, string name) :
		id(id), name(name)
	{
		
	}

	bool operator<(const Test &other)  const {
		return name == other.name ? id < other.id : name < other.name;
	}
	void print()
	{
		cout << id << ": " << name << endl;
	}

	friend bool comp(const Test &first, const Test &second);
};

bool comp(const Test &first, const Test &second)
{
	return first.name < second.name;
}

int main(int argc, char const *argv[])
{

	vector<Test> tests;

	tests.push_back(Test(5, "Mike"));
	tests.push_back(Test(10, "Sue"));
	tests.push_back(Test(7, "Raj"));
	tests.push_back(Test(3, "Vicky"));

	sort(tests.begin(), tests.end(), comp);

	for(int i = 0; i < tests.size(); i++)
	{
		tests[i].print();
	}

	return 0;
}