#include <iostream>
#include <string>
#include "shape.hpp"

int main()
{
	Drawing::Shape shp{ 10, 20 };
	shp.draw();
	shp.move(12, 55);
	shp.draw();
}