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

	Vector(float x, float y, float z)
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
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
	Vector v1(0, 1, 2);
	Vector v2(3, 4, 5);
	Vector v3;
	Vector v4;
	Vector v5;
	int Value = 5;

	v3 = v2 - v1;
	v4 = v2 * Value;

	std::cout << v3 << '\n';
	std::cout << "v3 length " << float(v3) << '\n';
	std::cout << v4 << '\n';
	std::cin >> v5;
	std::cout <<v5;
}