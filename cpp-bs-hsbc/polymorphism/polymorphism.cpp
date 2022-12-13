#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "shape.hpp"

void use_shape(Drawing::Shape& shp)
{
	shp.move(100, 200);
	shp.draw();
}

int main()
{
	using namespace Drawing;

	Rectangle rect1{ 100, 200, 400, 500 };
	rect1.draw();
	rect1.move(100, 200);
	rect1.draw();

	Circle c1{ 100, 200, 400 /*radius*/ };
	c1.draw();
	c1.move(30, 50);
	c1.draw();

	std::cout << "---------------------------\n";

	Shape& ref_shape = rect1; // Base type Shape refers to object of derived class Rectangle
	ref_shape.draw();
	ref_shape.move(100, 500);
	
	Shape* ptr_shape = &rect1; // Pointer to base class points to object of dervied class
	ptr_shape->draw();
	ptr_shape = &c1;
	ptr_shape->draw();

	use_shape(rect1);
	use_shape(c1);

	Line ln1{ 100, 200, 400, 500 };
	use_shape(ln1);

	std::cout << "---------------------------\n";

	// Polymorphism + smart pointers

	std::vector<std::unique_ptr<Shape>> shapes;
	shapes.push_back(std::make_unique<Rectangle>(100, 200, 400, 500));
	shapes.push_back(std::make_unique<Circle>(10, 20, 300));
	shapes.push_back(std::make_unique<Line>(110, 220, 306, 506));

	for (const auto& ptr_s : shapes)
		ptr_s->draw();

	std::cout << "---------------------------\n";

	for (const auto& ptr_s : shapes)
		ptr_s->move(46, 88);

	for (const auto& ptr_s : shapes)
		ptr_s->draw();

}