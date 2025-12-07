/* A factorial of an integer N (written N!) is defined as the product 
   (multiplication) of all the numbers between 1 and N (0! = 1). Write a 
   recursive function called factorial that returns the factorial of the input.
   Test it with the first 7 factorials. */
   
#include <iostream>

// could be optimized for recursion depth with vector memoization
constexpr int factorial(int input)	{
	if (input <= 0) return 0;
	if (input == 1) return 1;
	
	return (factorial(input - 1) * input);
}

int main()	{
	for (int i = 0; i <= 7; ++i)	{
		std::cout << factorial(i) << std::endl;
	}

	return 0;
}
