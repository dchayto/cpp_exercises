/* Create a struct to hold a fraction. The struct should have an integer 
   numerator and an integer denominator member.

   Write a function to read in a Fraction from the user, and use it to read-in 
   two fraction objects. Write another function to multiply two Fractions 
   together and return the result as a Fraction (you don’t need to reduce the 
   fraction). Write another function that prints a fraction. */

 
#include <iostream>
#include <limits>
#include <cmath>

struct Fraction	{
	int num {};
	int den {1};
};

const std::istream& operator>>(std::istream& in, Fraction& f)	{
	// assumes fraction is in the form num den
	// i fucking hate handling user input so i'm going to be really lazy here
	in >> f.num >> f.den;	
	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)	{
	out << f.num << "/" << f.den;
	return out;
}

inline constexpr int findGCF(const int a, const int b)	{
	using std::abs;
	int gcf {abs( (abs(a) < abs(b) ? a : b) )}; // start with magnitude of lower of two numbers
	if (gcf == 0) return 1;
	for (int div = 1; div <= gcf; ++div)	{
		gcf /= div;	
		if (a % gcf == 0 && b % gcf == 0) break;
	}
	return gcf;
}

constexpr Fraction operator*(const Fraction f1, const Fraction f2)	{
	// multiply fractions, store in frac inst
	Fraction fout {f1.num * f2.num, f1.den * f2.den };
	// find GCF of new fraction
	int gcf = findGCF(fout.num, fout.den);
	return { fout.num / gcf, fout.den / gcf };
}

inline void getFraction(Fraction& fin)	{
	std::cout << "Enter a fraction in the form [numerator denominator]: ";
	std::cin >> fin;
}

int main()	{
	Fraction f1 {}, f2 {};
	getFraction(f1);
	getFraction(f2);
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	return 0;  
}
