/* 1: Write a class named Ball. Ball should have two private member variables, 
   one to hold a color (default value: black), and one to hold a radius 
   (default value: 10.0). 

   Add 4 constructors, one to handle each case in main */

/* 2: Reduce the number of constructors in the above program by using default 
   arguments and delegating constructors. */

#include <iostream>
#include <string>
#include <string_view>

class Ball	{
public:
/* ex1 constructors
	Ball()	{ this->printBall(); }
	Ball(std::string_view col)
		: colour { col } { this->printBall(); }
	Ball(double rad)
		: radius { rad } { this->printBall(); }
	Ball(std::string_view col, double rad)
		: colour { col }
		, radius { rad }
		{
			this->printBall();
		}
*/
	Ball(std::string_view col = defcol, double rad = defrad)
		: colour { col }
		, radius { rad }
		{
			this->printBall();
		}
	Ball(double rad) : Ball{ defcol, rad } {  }

	void printBall()	{
		std::cout << "Ball(" << this->colour << ", " << this->radius << ")\n";
	}

private:
	static constexpr char defcol[] { "black" };
	static constexpr double defrad { 10.0 };

	std::string colour { defcol };
	double radius { defrad };
	//std::string colour { "black" }; // again, could/should do as enum but w/e
	//double radius { 10.0 };
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
