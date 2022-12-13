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

void Drawing::Circle::draw() const
{
	std::cout << "Drawing Circle at " << get_coord()
		<< " with r: " << radius_ << "\n";
}

void Drawing::Line::draw() const
{
	std::cout << "Drawing Line from: " << get_coord()
		<< " to: " << end_of_line_ << "\n";
}

void Drawing::Line::move(int dx, int dy)
{
	Shape::move(dx, dy); // calling impl from base class
	end_of_line_.translate(dx, dy);
}