#include "helpers.hpp"

void Helpers::print_line(char c, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		std::cout << c;
	std::cout << "\n";
}
