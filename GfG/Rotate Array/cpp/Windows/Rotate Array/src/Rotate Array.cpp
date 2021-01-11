#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Rotate Array\\Tests\\");

auto RotateArray(const std::vector<uint32_t>& arr, const uint32_t d) {
	auto result = std::vector<uint32_t>(arr.size());
	std::copy(std::next(std::begin(arr), d), std::end(arr), std::begin(result));
	std::copy(std::begin(arr), std::next(std::begin(arr), d), std::next(std::begin(result), arr.size() - d));
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
			uint32_t N, D;
			input_stream >> N >> D;
			Flush(input_stream);

			auto arr = std::vector<uint32_t>(N);
			input_stream >> arr;
			Flush(input_stream);

			auto result = RotateArray(arr, D);
			out_stream << result << std::endl;
		}

		input_stream.close();
		out_stream.close();

	}

	return 0;
}