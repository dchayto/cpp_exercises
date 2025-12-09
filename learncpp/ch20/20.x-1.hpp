/* Write function prototypes for the following cases. Use const if/when 
   necessary.
		
		a) A function named max() that takes two doubles and returns 
		   the larger of the two.

		b) A function named swap() that swaps two integers.

		c) A function named getLargestElement() that takes a dynamically 
		   allocated array of integers and returns the largest number in 
		   such a way that the caller can change the value of the element 
		   returned (don’t forget the length parameter). 					*/

constexpr double max(double a, double b);

constexpr void swap(int& a, int&b);

constexpr int* getLargestElement(int& [] intarr, int length);

