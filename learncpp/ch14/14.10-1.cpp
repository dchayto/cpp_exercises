/* Write a class named Ball. Ball should have two private member variables, 
   one to hold a color, and one to hold a radius. Also write a function to 
   print out the color and radius of the ball */

#include <iostream>
#include <string>
#include <string_view>


class Ball	{
public:
	Ball(std::string_view colour, double radius)
		: m_colour {colour}, m_radius {radius}
		{
			; // could set up enum for colour and make sure is valid - eh
		}
	std::string_view getColour()	{ return m_colour; }
	double& getRadius()				{ return m_radius; }
	// no need for setters - how would this change

private:
	std::string m_colour;	
	double m_radius {1.0}; // ball radius, mm
};


void print(Ball ball)	{
	std::cout << "Ball(" << ball.getColour() << ", " 
		<< ball.getRadius() << ")\n";
}

int main()	{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}
