#pragma once

#include <ostream>
#include <vector>

//istream

template <typename T>
void Flush(T& stream, int delimiter = '\n') {
	stream.ignore(std::numeric_limits<std::streamsize>::max(), delimiter);
}

template <template <typename, typename> typename ContainerType, typename T, typename Allocator>
std::istream& operator>>(std::istream& in, ContainerType<T, Allocator>& c) {
	std::copy_n(std::istream_iterator<T>(in), c.size(), std::begin(c));
	return in;
}

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<std::vector<T>>& c) {
	for (auto& v : c) {
		in >> v;
		Flush(in);
	}
	return in;
}

//ostream
template <template <typename, typename> typename ContainerType, typename T, typename Allocator>
std::ostream& operator<<(std::ostream& out, const ContainerType<T, Allocator>& c) {
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<T>(out, " "));
	return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<T>>& c) {
	for (auto& v : c) {
		out << v << std::endl;
	}
	return out;
}