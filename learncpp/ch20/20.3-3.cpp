/* a. Write a program that asks the user to enter a positive integer, and then
      uses a recursive function to print out the binary representation for 
	  that number

   b. Update your code from 3a to handle the case where the user may enter 0
      or a negative number. */

#include <iostream>

// doesn't handle sign bit, but neither does example...
void printBinary(unsigned int dec)	{
	// not sure if modulo is less efficient than bitshifts w/ loop
	bool LSB = dec % 2; // extract LSB; using bool to save stack space
	if (dec > 1) printBinary(dec >> 1);
	std::cout << LSB;
}

int main()	{
	printBinary(5); // should be 0101
	std::cout << std::endl;
	printBinary(0); // should be 0
	std::cout << std::endl;
	printBinary(static_cast<unsigned int>(-15)); 
	std::cout << std::endl;
}
