#pragma once

#include "point.hpp"

namespace Drawing
{
	class Shape
	{
	protected:
		Point coord_;

	public:
		Shape(int x = 0, int y = 0)
			: coord_{x, y} // Point{x, y}
		{
		}

		Shape(const Point& pt)
			: coord_{pt} // Point{pt} -> copy constructor
		{
		}

		const Point& get_coord() const
		{
			return coord_;
		}

		void move(int dx, int dy)
		{
			coord_.translate(dx, dy);
		}

		void draw() const;
	};

	class Rectangle : public Shape /* BaseClass */
	{
		int width_;
		int height_;
	public:
		Rectangle(int x = 0, int y = 0, int w = 0, int h = 0)
			: Shape{x, y}, // constructor of a base class - the same as super() in Python
			  width_{w}, height_{h}
		{
		}

		Rectangle(const Point& pt, int w = 0, int h = 0)
			: Shape{pt}, width_{w}, height_{h}
		{}

		void draw() const;
	};

	//class Rectangle
	//{
	//	Point coord_;
	//	int width_;
	//	int height_;

	//public:
	//	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0)
	//		: coord_{ x, y }, width_{ w }, height_{ h } // Point{x, y}
	//	{
	//	}

	//	Rectangle(const Point& pt, int w = 0, int h = 0)
	//		: coord_{ pt }, width_{ w }, height_{ h } // Point{pt} -> copy constructor
	//	{
	//	}

	//	const Point& get_coord() const
	//	{
	//		return coord_;
	//	}

	//	void move(int dx, int dy)
	//	{
	//		coord_.translate(dx, dy);
	//	}

	//	void draw() const;
	//};

} // namesapce Drawing

