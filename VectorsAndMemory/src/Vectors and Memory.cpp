//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <numeric>
#include <future>
using namespace std;

template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
	auto len = end - beg;
	if (len < 1000)
		return std::accumulate(beg, end, 0);

	RAIter mid = beg + len / 2;
	auto handle = std::async(std::launch::async,
		parallel_sum<RAIter>, mid, end);
	int sum = parallel_sum(beg, mid);
	return sum + handle.get();
}

int main() {

	vector<double> numbers(0);

	cout << "Size: " << numbers.size() << endl;

	auto capacity = static_cast<int>(numbers.capacity());
	cout << "Capacity: " << capacity << endl;

	for(auto i=0; i<10000000; i++) {

		if(numbers.capacity() != capacity) {
			capacity = static_cast<int>(numbers.capacity());
			cout << "Capacity: " << capacity << endl;
			cout << "Size: " << numbers.size() << endl;
		}

		numbers.push_back(static_cast<double>(i));
	}

	//numbers.reserve(1000000);
	cout << numbers[2] << endl;
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

	auto sum = parallel_sum(numbers.begin(), numbers.end());
	cout << "Sum: " << sum << endl;
	return 0;
}
