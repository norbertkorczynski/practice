#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Ice Cream Parlor\\Tests\\");

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
		}
		input_stream.close();
		out_stream.close();

	}

	return 0;
}