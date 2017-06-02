//============================================================================
// Name        : Elision.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <omp.h>

using namespace std;

template<typename data_type>
vector<data_type> map(const vector<data_type> &input, data_type (*func)(const data_type&)) {
	auto begin = input.begin();
	auto end = input.end();
	auto len = distance(begin, end);
	cout << "Length: " << len << endl;
	vector<future<data_type>> futures;
	vector<data_type> results;
	futures.reserve(len);
	results.reserve(len);
	for(auto it = begin; it != end; it++)
	{
		futures.push_back(std::async(std::launch::async, func, *it));
	}

	for_each(futures.begin(), futures.end(), [&results](future<data_type> &fut) {results.push_back(fut.get()); });

	return results;
}

template <typename RAIter>
void loop_in_parallel(RAIter first, RAIter last) {
	const size_t n = std::distance(first, last);

	#pragma omp parallel for
	for (size_t i = 0; i < n; i++) {
		auto& elem = *(first + i);
		elem *= elem;
	}
}

double m_long_func(const double &input)
{
	double ret_val = input;
	for (auto i = 0; i < 1000; i++)
	{
		ret_val += i;
	}
	return ret_val;
}

int main() {

	vector<double> nums;
	auto vector_length = 100000;
	nums.reserve(vector_length);
	for(auto i = 0; i < vector_length; i++)
	{
		nums.push_back(static_cast<double>(i));
	}

	
	auto func = &m_long_func;
	time_t begin, end; // time_t is a datatype to store time values.

	time(&begin); // note time before execution
	loop_in_parallel(nums.begin(), nums.end());
	time(&end); // note time after execution
	auto parallel_time = difftime(end, begin);

	time_t s_begin, s_end;
	time(&s_begin);
	vector<double> local_res;
	local_res.reserve(nums.size());
	for(auto val: nums)
	{
		local_res.push_back(m_long_func(val));
	}

	time(&s_end);

	auto serial_time = difftime(s_end, s_begin);

	printf("Parallel time: %.2lf seconds.\n", parallel_time);
	printf("Serial time: %.2lf seconds.\n", serial_time);

	return 0;
}
