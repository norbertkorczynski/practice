#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Longest Common Subsequence\\Tests\\");

int main() {
	//code
	std::list<std::string> files = { "example.txt" };
	for (auto file : files) {
		auto input_stream = std::ifstream(g_test_dir + file);
		auto out_stream = std::ofstream(g_test_dir + file + ".out");

		input_stream.close();
		out_stream.close();

	}

	return 0;
}