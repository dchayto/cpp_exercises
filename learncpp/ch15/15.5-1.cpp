/* Write a class template named Triad that has 3 private data members with 
   independent type template parameters. The class should have a constructor, 
   access functions, and a print() member function that is defined outside the 
   class. */

#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad	{
public:
	constexpr Triad(const T& t_in, const U& u_in, const V& v_in) 
	: m_1{ t_in}
	, m_2 { u_in }
	, m_3 { v_in }
	{}

	constexpr T first() const		{ return m_1; }
	constexpr U second() const	{ return m_2; }
	constexpr V third() const		{ return m_3; }
	void print() const;
private:
	T m_1;
	U m_2;
	V m_3; 
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const	{
	std::cout << "[" << m_1 << ", " << m_2 << ", " << m_3 << "]"; 
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}
