#include <iostream>
#include <string>
#include <vector>
#include <cassert>

int square(int x); // declaration

int square(int x) // definition
{
	return x * x;
}

int main()
{
	assert(square(4) == 16);
}