#include <iostream>

class Parent
{
public:
	Parent() {}

	virtual std::ostream& print(std::ostream& out) const 
	{
		out << "Parent";
		return out;
	}

	friend std::ostream& operator<<(std::ostream& out, const Parent& p)
	{
		return p.print(out);
	}
};

class Child : public Parent
{
public:
	Child() {}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Child";
		return out;
	}
};

/*int main()
{
	Child child;
	Parent& parent = child;
	Parent parent1;

	std::cout << "parent is a " << parent << '\n';

	std::cout << "parent1 is a " << parent1 << '\n';
	
	return 0;
}*/