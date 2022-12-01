#pragma once
#include <iostream>

namespace Drawing
{
	struct Point
	{
		int x, y;

		void translate(int dx, int dy)
		{
			x += dx;
			y += dy;
		}

		friend std::ostream& operator<<(std::ostream& out, const Point& pt)
		{
			out << "Point{" << pt.x << ", " << pt.y << "}";
			return out;
		}
	};
}

