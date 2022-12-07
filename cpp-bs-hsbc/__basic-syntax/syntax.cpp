#include <string>
#include <vector>
#include <iostream>

int global_x = 1024; // global

int main()
{
	global_x = 2048;

	int x = 665;
	const std::string desc = "even";

	// if 
	if (x % 2 == 0)
	{
		std::cout << x << " is " << desc << "\n";
	}
	else
	{
		std::cout << x << " is not" << desc << "\n";
	}

	int* ptr_int = nullptr;
	ptr_int = &x;

	if (ptr_int)
	{
		std::cout << "value: " << *ptr_int << "\n";
	}

	/////////////////////////////////////////////
	// switch
	uint8_t direction = 42;

	switch (direction)
	{
	case 1:
		std::cout << "North\n";
		break;
	case 2:
		std::cout << "East\n";
		break;
	case 3:
		std::cout << "South\n";
		break;
	case 4:
		std::cout << "West\n";
		break;
	default:
		std::cout << "Unknown direction\n";
		break;
	}

	//////////////////////////////
	// while

	int number = 10;
	while (number > 0)
	{
		std::cout << number << " ";
		--number;
	}

	do
	{
		std::cout << number << " ";
		++number;
	} while (number <= 10);


	///////////////////////////////////
	// for
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "for " << i << "\n";
	}

	using Matrix = std::vector<std::vector<int>>;

	const Matrix m = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	for (size_t row_index = 0; row_index < m.size(); ++row_index)
	{
		for (size_t column_index = 0; column_index < m[row_index].size(); ++column_index)
		{
			std::cout << m[row_index][column_index] << " ";
		}
		std::cout << "\n";
	}

	////////////////////////////////////////
	// for-each (range-based-for)
	for (const auto& row : m)
	{
		for (const auto& item : row)
		{
			std::cout << item << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
	system("PAUSE");
}