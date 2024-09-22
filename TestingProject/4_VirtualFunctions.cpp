#include <iostream>

int add(int a, int b)
{
	return a + b;
}

int substract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}
/*int main()
{
	int a;
	std::cout << "Enter a number: ";
	std::cin >> a;

	int b;
	std::cout << "Enter another number: ";
	std::cin >> b;

	int op;
	do
	{
		std::cout << "Enter an operation (0 = add, 1 = substract, 2 = multiply): ";
		std::cin >> op;
	} while (op < 0 || op > 2);
	
	//int result = 0;
	//switch (op)
	//{
	// это примые вызовы функции (или еще их называют ранее св€зывание или статическа€ прив€зка)
	//case 0: result = add(a,b); break;
	//case 1: result = substract(a, b); break;
	//case 2: result = multiply(a, b); break;
	//}

	// непр€мой или косвенный вызов (или еще его называют позднее св€зывание или динамическа€ прив€зка)
	int (*pFcn)(int, int) = nullptr;

	switch (op)
	{
	case 0: pFcn = add; break;
	case 1: pFcn = substract; break;
	case 2: pFcn = multiply; break;
	}

	std::cout << "The answer is: " << pFcn(a, b) << std::endl;

}*/
