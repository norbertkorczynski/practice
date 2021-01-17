#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Game of Two Stacks\\Tests\\");
using namespace std; //copied from hackerrank;

int twoStacks(int x, vector<int> a, vector<int> b) {
	int sum = 0;
	auto a_index = 0, b_index = 0;
	for (; a_index < a.size(); ++a_index) { //pop all available elements form 'a' stack
		if (sum + a[a_index] > x) {
			break;
		}
		sum += a[a_index];
	}
	int counter = a_index--; // save counter and decrease index to point to last element of vector

	int benefit = x - sum; // benefit of inserting - how many points will be lost in case of pop given element, initialy x-sum diff is avaliable for 'b' stack, <0 means it's not worth
	for (sum = 0; b_index < b.size(); ++b_index) { //pop all available elements form 'b' stack
		if (sum + b[b_index] > x) {
			break;
		}
		sum += b[b_index];
		if (benefit >= b[b_index]) { //is it possible to pop additional element?
			benefit -= b[b_index];
			++counter;
		} else {
			int a_value = a_index >= 0 ? a[a_index] : 0;
			benefit += (a_value - b[b_index]);
			--a_index;
		}
	}

	return counter;
}

int main() {
	//code
	std::list<std::string> files = { "input01.47.txt" };
	for (auto file : files) {
		auto input_stream = std::ifstream(g_test_dir + file);
		auto out_stream = std::ofstream(g_test_dir + file + ".out");
		uint16_t test_cases;
		input_stream >> test_cases;
		Flush(input_stream);
		for (decltype(test_cases) test_case = 0; test_case < test_cases; ++test_case) {
            int n, m, x;
            input_stream >> n >> m >> x;
            auto a = std::vector<int>(n), b = std::vector<int>(m);
            input_stream >> a >> b;

            auto result = twoStacks(x, a, b);

            out_stream << result << std::endl;
		}
		input_stream.close();
		out_stream.close();

	}

	return 0;
}