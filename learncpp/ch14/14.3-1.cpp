/* 14.3-1: Create a struct called IntPair that holds two integers. Add a member 
   function named print that prints the value of the two integers. */

/* 14.3-2: Add a new member function to IntPair named isEqual that returns a 
   Boolean indicating whether one IntPair is equal to another. */

#include <iostream>

struct IntPair {
	int i1 {};
	int i2 {};
	void print()	{ std::cout << "Pair(" << i1 << ", " << i2 << ")\n"; }
	constexpr bool isEqual(IntPair p2) { return (i1 == p2.i1 && i2 == p2.i2);}
};


int main()	{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " 
		<< (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " 
		<< (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
