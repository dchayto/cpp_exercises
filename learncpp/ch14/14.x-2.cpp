/* In lesson 13.10 -- Passing and returning structs, we wrote a short program 
   using a Fraction struct. Convert Fraction from a struct to a class. Convert
   all of the functions to (non-static) member functions. */

#include <iostream>
#include <cmath>

class Fraction	{
public:
	Fraction()
		: Fraction(DEFAULT_NUM, DEFAULT_DEN) {};
	
	Fraction(int num, int den)
		: m_num { num }
		, m_den { den }
		{
			if (m_den == 0) m_den = DEFAULT_DEN;

			int gcf = findGCF();
			this->m_num /= gcf;
			this->m_den /= gcf;
		}
	
	Fraction multiply(const Fraction& f) const	{
		return { (*this) * f }; // this is silly 
	}

	Fraction operator*(const Fraction& f) const	{
		return { this->m_num * f.m_num, this->m_den * f.m_den };
	}

	// why tf is this a member function
	void getFraction() {
		std::cout << "Enter a value for numerator: ";
		std::cin >> this->m_num;
		std::cout << "Enter a value for denominator: ";
		std::cin >> this->m_den;
		if (this->m_den == 0) this->m_den = DEFAULT_DEN;
		int gcf = findGCF();
	}

	void printFraction() const	{
		std::cout << this->m_num << '/' << this->m_den << '\n';
	}
	
	// idk if this should have getters/setters - doesn't ask for them, so eh

private:
	static constexpr int DEFAULT_NUM { 0 };
	static constexpr int DEFAULT_DEN { 1 };
	int m_num {};
	int m_den {};

	constexpr int findGCF() const	{
		if (this->m_num == 0) return 1;

		using std::abs;
		int gcf { abs(abs(this->m_num) < abs(this->m_den) 
			? this->m_num : this->m_den) };
		for (int div = 1; div <= gcf; ++div)	{
			gcf /= div;
			if (this->m_num % gcf == 0 && this->m_den % gcf == 0) break;
		}
		return gcf;
	}
};


int main()	{
	Fraction f1{};
	f1.getFraction();

	Fraction f2{};
	f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

	(f1.multiply(f2)).printFraction();

	return 0;
}
