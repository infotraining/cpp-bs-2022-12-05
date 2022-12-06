#include <iostream>
#include <string>
#include <vector>

enum DayOfWeek { mon, tue, wed, thd, fri, sat, sun};

enum BankOp { withdraw, deposit, check };

enum class Direction : uint8_t { north, east, south, west };

int main()
{
	// enums
	int x = 2;
	DayOfWeek today = static_cast<DayOfWeek>(x); // int -> enum - illegal

	today = sun;

	switch (today)
	{
	case mon:
		std::cout << "Monday\n";
		break;
	case tue:
		std::cout << "Tuesday\n";
		break;
	default:
		std::cout << "Other day of week\n";
		break;
	}

	int value = today; // enum -> int

	std::vector<std::string> todo = { "weak up", "survive", "survive", "", "", "", ""};

	std::cout << todo[sun] << "\n";



	// scoped enumerations - since C++11


	/////////////////////////////////////////////
	// switch
	Direction direction = Direction::south;

	switch (direction)
	{
	case Direction::north:
		std::cout << "North\n";
		break;
	case Direction::east:
		std::cout << "East\n";
		break;
	case Direction::south:
		std::cout << "South\n";
		break;
	case Direction::west:
		std::cout << "West\n";
		break;
	default:
		std::cout << "Unknown direction\n";
		break;
	}

	system("PAUSE");
}