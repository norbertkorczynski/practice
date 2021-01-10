#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Rotate Array\\Tests\\");

std::vector<uint32_t> RotateArray(const std::vector<uint32_t> arr) {
	return arr;
}

int main() {
	//code
	std::list<std::string> files = { "example.txt" };
	for (auto file : files) {
		auto input_stream = std::ifstream(g_test_dir + file);
		auto out_stream = std::ofstream(g_test_dir + file + ".out");

 		int test_cases;
		input_stream >> test_cases;
		Flush(input_stream);
		for (int test_case = 0; test_case < test_cases; ++test_case) {
			int N, D;
			input_stream >> N >> D;
			Flush(input_stream);

			auto arr = std::vector<uint32_t>(N);
			input_stream >> arr;
			Flush(input_stream);

			auto result = RotateArray(arr);
			out_stream << result << std::endl;
		}
		auto test = std::vector<std::vector<uint32_t>>(5, std::vector<uint32_t>(5));
		input_stream >> test;

		out_stream << test << std::endl;
		input_stream.close();
		out_stream.close();

	}

	return 0;
}