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

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

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

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << ' ' << v.X << ' ' << v.Y << ' ' << v.Z;
	return out;
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

	v3 = v1 + v2;

	std::cout << v3 << '\n';
	std::cout << "v3 length " << float(v3);


}