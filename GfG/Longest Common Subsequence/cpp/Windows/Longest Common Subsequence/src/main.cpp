#include <stdio.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

#include <StreamHelpers.h>

const std::string g_test_dir("C:\\repos\\personal\\practice\\GfG\\Longest Common Subsequence\\Tests\\");

using string = std::string;

int lcs(int x, int y, string s1, string s2) {
	auto subseq_map = std::vector<std::vector<uint16_t>>(x+1, std::vector<uint16_t>(y+1, 0));
	for (decltype(x) x_i = 1; x_i <= x; ++x_i) {
		for (decltype(y) y_j = 1; y_j <= y; ++y_j) {
			if (s1.at(x_i-1) == s2.at(y_j-1)) {
				subseq_map[x_i][y_j] = subseq_map[x_i - 1][y_j - 1] + 1;
			}
			else {
				subseq_map[x_i][y_j] = std::max(subseq_map[x_i - 1][y_j], subseq_map[x_i][y_j - 1]);
			}
		}
	}
	return subseq_map.back().back();
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
			uint32_t A, B;
			input_stream >> A >> B;
			Flush(input_stream);

			std::string s1, s2;
			input_stream >> s1;
			Flush(input_stream);
			input_stream >> s2;
			Flush(input_stream);

			auto result = lcs(A, B, s1, s2);
			out_stream << result << std::endl;
		}

		input_stream.close();
		out_stream.close();

	}

	return 0;
}