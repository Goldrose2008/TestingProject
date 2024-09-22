#include <iostream>

class Point
{
private:
	int Rows;
	int Cols;
	int** Points;
	std::string* Name;

public:
	Point(int newRows, int newCols)
	{
		std::cout << "constructor \n";
		Rows = newRows;
		Cols = newCols;
		Points = new int* [Rows];
		Name = new std::string("Points1");
		for (int i = 0; i < Rows; i++)
		{
			Points[i] = new int[Cols];
			for (int j = 0; j < Cols; j++)
			{
				Points[i][j] = rand() % 100;
			}
		}
		std::cout << "Name array: " << *Name << "\n";
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				std::cout << Points[i][j] << ", ";
			}
			std::cout << "\n";
		}
	}

	Point(const Point& other)
	{
		std::cout << "\n Copy constructor \n";
		Rows = other.Rows;
		Cols = other.Cols;

		if (Points) delete[] Points;
		Points = new int* [Rows];
		for (int i = 0; i < Rows; i++)
		{
			Points[i] = new int[Cols];
			for (int j = 0; j < Cols; j++)
			{
				Points[i][j] = other.Points[i][j];
			}
		}

		if (other.Name)
		{
			if (Name) delete Name;
			Name = new std::string(*(other.Name));
		}

		std::cout << "Name array: " << *Name << "\n";
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				std::cout << other.Points[i][j] << ", ";
			}
			std::cout << "\n";
		}
	}

	~Point()
	{
		std::cout << "destructor calling \n";

		for (int i = 0; i < Rows; i++)
		{
			delete[] Points[i];
		}
		delete[] Points;
		delete Name;
	}

	Point& operator=(Point& other)
	{
		Rows = other.Rows;
		Cols = other.Cols;
		
		if (Points) delete [] Points;
		Points = new int* [other.Rows];
		for (int i = 0; i < other.Rows; i++)
		{
			Points[i] = new int[other.Cols];
			for (int j = 0; j < other.Cols; j++)
			{
				Points[i][j] = other.Points[i][j];
			}
		}

		if (other.Name)
		{
			if (Name) delete Name;
			Name = new std::string(*(other.Name));
		}

		return (*this);
	}
};

/*int main()
{
	Point P(3, 4);
	Point V(P);

	return 0;
}*/