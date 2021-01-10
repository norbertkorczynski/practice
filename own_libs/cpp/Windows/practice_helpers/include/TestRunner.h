#pragma once

#include <string_view>
#include <list>
#include <tuple>
#include <unordered_map>
#include <any>
#include <fstream>

using FilePath = std::string_view;
using InputName = std::string_view;
using TestInputs = std::unordered_map<InputName, std::any>;
using TestCase = std::list<TestInputs>;

//! Helper class which can be used to run tests with specified inputs
/*!	\class TestRunner
*
*/
class TestRunner {
public:
	explicit TestRunner(const FilePath file_math);
	virtual ~TestRunner() = default;

	void AddTestCase();

	template<typename T> T ParseInput();
	template<typename T> T ParseLine();

	template<typename T>
	void AddTestInput(const InputName input_name, const T& value);

	template<typename T>
	T GetTestInput(const InputName input_name);

private:
	TestCase m_test_cases;
	FilePath m_file_path;
	std::ifstream m_stream;
};

template<typename T>
inline T TestRunner::ParseInput() {
	T value;
	m_stream >> value;
	return value;
}

template<typename T>
inline T TestRunner::ParseLine() {
	T value;
	m_stream >> value;
	m_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return value;
}

template<typename T>
inline void TestRunner::AddTestInput(const InputName input_name, const T& value) {
	m_test_cases.back().emplace(input_name, value);
}

template<typename T>
inline T TestRunner::GetTestInput(const InputName input_name) {
	return std::any_cast<T>(m_test_cases.back()[input_name]);
}
