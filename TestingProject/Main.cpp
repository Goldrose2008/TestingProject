#include <iostream>
#include <cmath>
#include <vector>

class Vector
{
private:
	float X;
	float Y;
	float Z;
public:
	Vector() : X(0), Y(0), Z(0) {}

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
	}

	Vector(const Vector& other)
	{
		//std::cout << "\n Copy constructor \n";
		X = other.X;
		Y = other.Y;
		Z = other.Z;
	}

	~Vector()
	{
		//std::cout << "destructor calling \n";
	}

	Vector& operator=(Vector& other)
	{
		//std::cout << "operator =\n";
		X = other.X;
		Y = other.Y;
		Z = other.Z;

		return (*this);
	}

	operator float()
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	friend Vector operator+(const Vector& A, const Vector& B);

	friend Vector operator-(const Vector& A, const Vector& B);

	friend Vector operator*(const Vector& A, float B);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

	friend std::istream& operator>>(std::istream& in, Vector& v);

	friend bool operator>(Vector& A, Vector& B);

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
};

Vector operator+(const Vector& A, const Vector& B)
{
	return Vector(A.X + B.X, A.Y + B.Y, A.Z + B.Z);
}

Vector operator-(const Vector& A, const Vector& B)
{
	return Vector(A.X - B.X, A.Y - B.Y, A.Z - B.Z);
}

Vector operator*(const Vector& A, float B)
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

bool operator>(Vector& A, Vector& B)
{
	return  float(A) > float(B);
}

class Item
{
private:
	std::string ItemName;
public:
	Item() : ItemName("none") {}
	Item(std::string inItemName)
	{
		ItemName = inItemName;
	}

	void ShowNameItem()
	{
		std::cout << ItemName << '\n';
	}
};

class Guild;

class Player
{
private:
	Vector Location;
	Item* MainItem;
	std::string PlayerName;
	std::vector<Guild*> Guilds;
public:
	Player() : PlayerName("none") {}
	Player(std::string inPlayerName, Vector InitialLocation)
	{
		PlayerName = inPlayerName;
		Location = InitialLocation;
	}
	void ShowPlayerInfo()
	{
		std::cout << PlayerName << " is at " << Location << '\n';
		std::cout << PlayerName << " have ";
		if (MainItem)
		{
			MainItem->ShowNameItem();
		}
		else
		{
			std::cout << "none \n ";
		}
	}

	void SetNewItem(Item* newItem)
	{
		MainItem = newItem; // копируем указатель на предмет, а не сам предмет
	}

	void JoinGuild(Guild* guildToJoin)
	{
		Guilds.push_back(guildToJoin);
	}

	friend class Guild;
};

class PlayersParty
{
private:
	Player** players;
	int CurrentPlayersNum;
public:
	PlayersParty() : players(new Player* [4]), CurrentPlayersNum(0) {}

	void AddPlayerToParty(Player* newPlayer)
	{
		players[CurrentPlayersNum] = newPlayer;
		CurrentPlayersNum++;
	}

	void ShowAllPlayerInfo()
	{
		for (int i = 0; i < CurrentPlayersNum; i++)
		{
			players[i]->ShowPlayerInfo();
		}
	}
};

class Guild
{
private:
	std::vector<Player*> Players;
public:
	void AddNewPlayer(Player* newPlayer)
	{
		newPlayer->JoinGuild(this);
		Players.push_back(newPlayer);
	}

	void RemovePlayer(Player* PlayerToRemove)
	{
		//Players.push_back(PlayerToRemove);
	}
};

/*int main()
{
	Item* Sword = new Item("Sword");
	Player* NewPlayerA = new Player("Vasya", Vector(1, 0, 0));
	NewPlayerA->SetNewItem(Sword);
	Player* NewPlayerB = new Player("Petya", Vector(2, 0, 0));
	PlayersParty PlayersAB;
	PlayersAB.AddPlayerToParty(NewPlayerA);
	PlayersAB.AddPlayerToParty(NewPlayerB);
	PlayersAB.ShowAllPlayerInfo();
	
}*/
