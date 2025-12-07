/* Write a recursive function that takes an integer as input and returns the 
   sum of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). 
   Print the answer for input 93427 (which is 25). Assume the input values are
   positive */

#include <iostream>

// probably a more efficient way to do this but whatever
constexpr int sumdigits(int input)	{
	if (input < 10) return input;
	int inshift = input % 10;	
	return inshift + sumdigits((input - inshift) / 10);		
}

int main()	{
	std::cout << sumdigits(93427) << std::endl;
//	std::cout << sumdigits(11) << std::endl;
	return 0;
}
