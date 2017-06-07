#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Test
{
	string name;
public:

	explicit Test(string name) : name(name)
	{
		
	}

	~Test()
	{
		
	}

	void print() const
	{
		cout << name << endl;
	}
};
int main(int argc, char const *argv[])
{
	//LIFO
	stack<Test> testStack;
	
	testStack.push(Test("Mike"));
	testStack.push(Test("John"));
	testStack.push(Test("Sue"));

	cout << endl;

	Test &test1 = testStack.top();
	test1.print();

	testStack.pop();
	Test &test2 = testStack.top();
	test2.print();

	//FIFO
	queue<Test> testQueue;

	testQueue.push(Test("Mike"));
	testQueue.push(Test("John"));
	testQueue.push(Test("Sue"));
	
	cout << endl;

	testQueue.back().print();

	while(testQueue.size() > 0)
	{
		Test &test = testQueue.front();
		test.print();
		testQueue.pop();
	}

	return 0;
}