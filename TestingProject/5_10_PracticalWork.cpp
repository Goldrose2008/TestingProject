#include <iostream>
#include <exception>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
	{
		if (denominator <= 0)
		{
			throw std::runtime_error("The denominator cannot be zero!");
		}			
	}
};

int main()
{
	try
	{
		std::cout << "Enter two integers: ";
		int a;
		int b;
		if (std::cin >> a && std::cin >> b)
		{
			Fraction fraction(a, b);
			std::cout << "Well done!";
		}
		else
			throw std::exception("You have entered invalid values");
	}
	catch (std::runtime_error& exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
	}
	catch (std::exception& exception)
	{
		std::cerr << "Error: " << exception.what() << '\n';
	}
}

