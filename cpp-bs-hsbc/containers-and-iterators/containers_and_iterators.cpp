#include "helpers.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

namespace LegacyCode
{
	double avg(const int* data, int size)
	{
		assert(size >= 0);

		double sum = 0.0;

		for (const int* ptr_item = data; ptr_item != data + size; ++ptr_item)
			sum += *ptr_item;

		return sum / size;
	}

	double avg(const int* begin, const int* end)
	{
		assert(begin != end);

		double sum = 0.0;

		for (const int* ptr_item = begin; ptr_item != end; ++ptr_item)
			sum += *ptr_item;

		return sum / (end - begin);
	}
}

namespace ModernCpp
{
	// TODO: Modernize avg function
}

int main()
{
	const int size = 10;
	int oldschool_data[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < size; ++i)
		std::cout << oldschool_data[i] << "\n";

	for (int i = 0; i < size; ++i)
		std::cout << *(oldschool_data + i) << "\n";

	Helpers::print(oldschool_data, "oldschool_data");
	std::cout << "avg: " << LegacyCode::avg(oldschool_data, size) << "\n";


	std::cout << "avg with pointers: "
		<< LegacyCode::avg(oldschool_data, oldschool_data + size) << "\n";

}