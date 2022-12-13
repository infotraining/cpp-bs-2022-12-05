#include "shape.hpp"

void Drawing::Shape::draw() const
{
	std::cout << "Drawing Shape at " << coord_ << "\n";
}


void Drawing::Rectangle::draw() const
{
	std::cout << "Drawing Rectangle at " << get_coord()
		<< " with w: " << width_ << " & h: " << height_ << "\n";
}