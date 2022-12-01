#include <iostream>
#include <string>

namespace Helpers
{
	void print_line(char c = '-', size_t length = 40)
	{
		for (size_t i = 0; i < length; ++i)
			std::cout << c;
		std::cout << "\n";
	}

	template <typename T1, typename T2>
	std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& p)
	{
		out << "{" << p.first << ", " << p.second << "}";
		return out;
	}

	template <typename TContainer>
	void print(const TContainer& container, const std::string& prefix = "values")
	{
		std::cout << prefix << ": [ ";
		for (const auto& item : container)
			std::cout << item << " ";
		std::cout << "]\n";
	}
}

int main()
{
	Helpers::print_line();
	std::cout << "Basic types in C++...\n";

	////////////////////////////////////////
	// integers

	////////////////////////////////////////
	// floating points

	////////////////////////////////////////
	// boolean values

	////////////////////////////////////////
	// strings

	////////////////////////////////////////
	// vector

	////////////////////////////////////////
	// reference types

	////////////////////////////////////////
	// pointer types
}