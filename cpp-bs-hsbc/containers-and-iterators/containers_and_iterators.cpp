#include "helpers.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace LegacyCode
{
	double avg(const int* data, int size)
	{
		double sum = 0.0;

		for (const int* ptr_item = data; ptr_item != data + size; ++ptr_item)
			sum += *ptr_item;

		return sum / size;
	}
}

namespace ModernCpp
{
	// TODO: Modernize avg function
}

int main()
{
	int oldschool_data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	Helpers::print(oldschool_data, "oldschool_data");
	std::cout << "avg: " << LegacyCode::avg(oldschool_data, 10) << "\n";
}