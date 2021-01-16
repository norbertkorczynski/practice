#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <unordered_map>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Ice Cream Parlor\\Tests\\");

std::vector<int> icecreamParlor(int m, std::vector<int> arr) {
	auto result = std::vector<int>();
	auto memo = std::unordered_map<int, int>(); // value, index in arr
	for (auto index = 0; index < arr.size(); ++index) {
		auto price = arr[index];
		auto diff = m - price;
		auto found = memo.find(diff);
		if (found != std::end(memo)) {
			result.push_back(index + 1);
			result.push_back(found->second + 1);
			break;
		} else {
			memo.insert({ price, index });
		}
	}
	std::sort(std::begin(result), std::end(result));
	return result;
}

int main() {
	//code
	std::list<std::string> files = { "example.txt" };
	for (auto file : files) {
		auto input_stream = std::ifstream(g_test_dir + file);
		auto out_stream = std::ofstream(g_test_dir + file + ".out");
		uint16_t test_cases;
		input_stream >> test_cases;
		Flush(input_stream);
		for (decltype(test_cases) test_case = 0; test_case < test_cases; ++test_case) {
			int m;
			input_stream >> m;
			input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			int n;
			input_stream >> n;
			input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::vector<int> arr(n);
			input_stream >> arr;

			std::vector<int> result = icecreamParlor(m, arr);

			out_stream << result << std::endl;
		}
		input_stream.close();
		out_stream.close();

	}

	return 0;
}