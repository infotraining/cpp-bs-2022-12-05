#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "shape.hpp"

int main()
{
	Drawing::Point pt1{ 100, 200 };
	std::cout << "pt1.x = " << pt1.x << ", pt1.y = " << pt1.y << "\n";
	pt1.translate(30, 50);
	std::cout << pt1 << "\n";

	std::cout << "---------------------------\n";

	Drawing::Shape shp1{ 450, 200 };
	shp1.draw();
	shp1.move(30, 40);
	shp1.draw();

	std::cout << "---------------------------\n";

	using namespace Drawing;

	std::vector<Shape> shapes;
	shapes.push_back(shp1);
	shapes.push_back(Shape{ 100, 200 });
	shapes.push_back(Shape(80, 400));

	for (const auto& shp : shapes)
		shp.draw();

	std::cout << "---------------------------\n";
	
	for (auto& shp : shapes)
		shp.move(50, 80);

	for (const auto& shp : shapes)
		shp.draw();

	std::for_each(shapes.begin(), shapes.end(), [](const Shape& s) { s.draw(); });

	std::cout << "---------------------------\n";

	std::vector<Point> coordinates(shapes.size());

	std::transform(shapes.begin(), shapes.end(), coordinates.begin(),
		[](const Shape& shp) { return shp.get_coord(); });

	for (const auto& c : coordinates)
		std::cout << c << "\n";

	std::cout << "---------------------------\n";

	Rectangle rect1{ 100, 200, 400, 500 };
	rect1.draw();
	rect1.move(100, 200);
	rect1.draw();

	Circle c1{ 100, 200, 400 /*radius*/ };
	c1.draw();
	c1.move(30, 50);
	c1.draw();
}