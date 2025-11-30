/* a) Write a class named Point2d. Point2d should contain two member variables 
      of type double: m_x, and m_y, both defaulted to 0.0.

	  Provide a constructor and a print() function.

   b) Now add a member function named distanceTo() that takes another Point2d 
      as a parameter, and calculates the distance between them. Given two 
	  points (x1, y1) and (x2, y2), the distance between them can be calculated
	  using the formula std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). 
	  The std::sqrt function lives in header cmath.	*/

#include <cmath>
#include <iostream>

inline constexpr double sq(double x)	{
	return x * x;
}

class Point2d	{
public:
	Point2d()
		: Point2d(0.0, 0.0) {}

	Point2d(double px, double py)
		: m_x { px }
		, m_y { py } {}

	constexpr double distanceTo(const Point2d& p2) const	{
		return std::sqrt(sq(this->m_x - p2.m_x) + sq(this->m_y - p2.m_y));  
	}

	void print() const	{
		std::cout << "Point2d(" << this->m_x << ", " << this->m_y << ")\n";
	}

private:
	double m_x {}; 
	double m_y {};
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
