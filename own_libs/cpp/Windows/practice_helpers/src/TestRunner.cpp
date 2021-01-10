#include "pch.h"
#include "TestRunner.h"

TestRunner::TestRunner(const FilePath file_path)
	: m_file_path(file_path) {
	m_stream.open(m_file_path.data());
}

void TestRunner::AddTestCase() {
	m_test_cases.emplace_back();
}