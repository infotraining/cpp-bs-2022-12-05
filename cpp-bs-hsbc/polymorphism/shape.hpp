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
			: coord_{ x, y } // Point{x, y}
		{
		}

		Shape(const Point& pt)
			: coord_{ pt } // Point{pt} -> copy constructor
		{
		}

		virtual ~Shape() = default;

		const Point& get_coord() const
		{
			return coord_;
		}

		virtual void move(int dx, int dy)
		{
			coord_.translate(dx, dy);
		}

		virtual void draw() const = 0; // pure virtual method - abstract method
	};

	class Rectangle : public Shape /* BaseClass */
	{
		int width_;
		int height_;
	public:
		Rectangle(int x = 0, int y = 0, int w = 0, int h = 0)
			: Shape{ x, y }, // constructor of a base class - the same as super() in Python
			width_{ w }, height_{ h }
		{
		}

		Rectangle(const Point& pt, int w = 0, int h = 0)
			: Shape{ pt }, width_{ w }, height_{ h }
		{}

		void draw() const;
	};

	class Circle : public Shape
	{
		int radius_;
	public:
		Circle(int x = 0, int y = 0, int r = 0)
			: Shape{ x, y }, radius_{ r }
		{}

		Circle(const Point& pt, int r = 0)
			: Shape{ pt }, radius_{ r }
		{}

		void draw() const override;
	};

	class Line : public Shape
	{
		Point end_of_line_;
	public:
		Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
			: Shape{ x1, y1 }, end_of_line_{ x2, y2 }
		{}

		Line(const Point& start, const Point& end)
			: Shape{ start }, end_of_line_{ end }
		{}

		void draw() const override;

		void move(int dx, int dy) override;
	};
} // namesapce Drawing

