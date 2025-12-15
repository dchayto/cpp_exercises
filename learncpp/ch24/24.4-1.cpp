/* Create a Fruit base class that contains two private members: a name 
   (std::string), and a color (std::string). Create an Apple class that 
   inherits Fruit. Apple should have an additional private member: fiber 
   (double). Create a Banana class that also inherits Fruit. Banana has no 
   additional members */

#include <iostream>
#include <string>

class Fruit	{
public:
	Fruit(const std::string& name, const std::string& colour)
	  : m_name{ name }
	  , m_col	{ colour}
	{
	}

	const std::string& getName() const 	{ return m_name; }
	const std::string& getCol() const 	{ return m_col; }

private:
	std::string m_name 	{ };
	std::string m_col	{ };
};

class Apple : public Fruit	{
	public:
		Apple(const std::string& name, const std::string& colour, double fibre)
		  : Fruit{ name, colour }
		  , m_fibre {fibre }
		{
		}
	friend std::ostream& operator<<(std::ostream& out, const Apple& a)	{
		out << "Apple(" << a.getName() << ", " << a.getCol() << ", "
			<< a.m_fibre << ")\n"; 
		return out;
	}
	private:
		double m_fibre { 0 };
}; // apple

class Banana : public Fruit	{
	public:
		Banana(const std::string& name, const std::string& colour)
		  : Fruit{ name, colour }
		{
		}
	friend std::ostream& operator<<(std::ostream& out, const Banana& b)	{
		out << "Banana(" << b.getName() << ", " << b.getCol() << ")\n"; 
		return out;
	}
	private:
}; // banana

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
