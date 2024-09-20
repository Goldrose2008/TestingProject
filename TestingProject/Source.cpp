#include <iostream>
#include <cmath>

class Vector
{
public:
	Vector()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}

	explicit Vector(float num)
	{
		X = num;
		Y = num;
		Z = num;
	}

	Vector(float x, float y, float z)
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
		//Info = new std::string("important!");
	}

	Vector(const Vector& other)
	{
		std::cout << "\n Copy constructor \n";
		X = other.X;
		Y = other.Y;
		Z = other.Z;
		//Info = new std::string(*(other.Info));
	}

	~Vector()
	{
		std::cout << "destructor calling \n";
		delete Info;
	}

	Vector& operator=(Vector& other)
	{
		std::cout << "operator =\n";
		X = other.X;
		Y = other.Y;
		Z = other.Z;

		if (other.Info)
		{
			if (Info) delete Info;
			Info = new std::string(*(other.Info));
		}

		return (*this);
	}

	operator float()
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	friend Vector operator+(const Vector& A, const Vector& B);

	friend Vector operator-(const Vector& A, const Vector& B);

	friend Vector operator*(const Vector& A, int B);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

	friend std::istream& operator>>(std::istream& in, Vector& v);

	friend bool operator>(const Vector& A, const Vector& B);

	float operator[](int index)
	{
		switch (index)
		{case 0:
			return X;
			break;
		case 1:
			return Y;
			break;
		case 2:
			return Z;
			break;
		default:
			std::cout << "index error ";
			return 0;
			break;
		}
	}

private:
	float X;
	float Y;
	float Z;
	std::string* Info;
};

Vector operator+(const Vector& A, const Vector& B)
{
	return Vector(A.X + B.X, A.Y + B.Y, A.Z + B.Z);
}

Vector operator-(const Vector& A, const Vector& B)
{
	return Vector(A.X - B.X, A.Y - B.Y, A.Z - B.Z);
}

Vector operator*(const Vector& A, int B)
{
	return Vector(A.X * B, A.Y * B, A.Z * B);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << ' ' << v.X << ' ' << v.Y << ' ' << v.Z;
	return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
	in >> v.X >> v.Y >> v.Z;
	return in;
}

bool operator>(const Vector& A, const Vector& B)
{
	return false;
}

int main()
{
	Vector v1(1, 1, 1);
	Vector v2(2, 2, 2);
	Vector v3;
	std::cout << v2<< "\n";
	v3 = v2 = v1;
	std::cout << v3 << "\n";
}