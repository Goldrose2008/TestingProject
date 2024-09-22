#include <iostream>
#include <vector>
#include <functional>

class Vehicle
{
public:
	virtual std::ostream& print(std::ostream& out) = 0;
	
	virtual ~Vehicle() = default;

	friend std::ostream& operator<<(std::ostream& out, Vehicle& object)
	{
		return object.print(out);
	}
};

class Wheel
{
private:
	float Diameter;
public:
	Wheel(float initDiameter) : Diameter(initDiameter) {}

	friend std::ostream& operator<<(std::ostream& out, Wheel& wheel)
	{
		out << wheel.Diameter;
		return out;
	}
};

class Engine
{
private:
	float Power;
public:
	Engine(float initPower) : Power(initPower) {}
	float getPower() const { return Power; }

	friend std::ostream& operator<<(std::ostream& out, Engine& engine)
	{
		out << engine.Power;
		return out;
	}
};

class WaterVehicle : virtual public Vehicle
{
private:
	float Draught;
public:
	WaterVehicle(float initDraught) : Draught(initDraught){}
	
	virtual ~WaterVehicle() 
	{ std::cout << "destructor WaterVehicle" << '\n'; }

	std::ostream& print(std::ostream& out) override
	{
		out << "WaterVehicle Draught: " << Draught;
		return out;
	}
};

class RoadVehicle : virtual public Vehicle
{
private:
	float RideHeight;
public:
	RoadVehicle(float initRideHeight) : RideHeight(initRideHeight){}

	virtual ~RoadVehicle() { std::cout << "destructor RoadVehicle" << '\n'; }

	float getRideHeight() const { return RideHeight; }
};

class Bicycle : public RoadVehicle
{
private:
	Wheel wheell_1;
	Wheel wheell_2;
public:
	Bicycle(Wheel initWheell_1, Wheel initWheell_2, float initRideHeight)
		: wheell_1(initWheell_1), wheell_2(initWheell_2), RoadVehicle(initRideHeight){}

	virtual ~Bicycle() { std::cout << "destructor Bicycle" << '\n'; }

	std::ostream& print(std::ostream& out) override
	{
		out << "Bicycle Wheels: " << wheell_1 << " " << wheell_2 << " Ride height: " << RoadVehicle::getRideHeight();
		return out;
	}
};

class Car : public RoadVehicle
{
private:
	Wheel wheell_1;
	Wheel wheell_2;
	Wheel wheell_3;
	Wheel wheell_4;
	Engine engine;
public:
	Car(Engine initEngine, Wheel initWheell_1, Wheel initWheell_2, Wheel initWheell_3, Wheel initWheell_4, float initRideHeight)
		: wheell_1(initWheell_1), wheell_2(initWheell_2), wheell_3(initWheell_3), wheell_4(initWheell_4), engine(initEngine), RoadVehicle(initRideHeight){}

	virtual ~Car() { std::cout << "destructor Car" << '\n'; }

	Engine getEngine() const { return engine; }

	std::ostream& print(std::ostream& out) override
	{
		out << "Car Engine: " << engine << " Wheels: " << wheell_1 << " " << wheell_2 << " " << wheell_3 << " " << wheell_4 << " Ride height: " << RoadVehicle::getRideHeight();
		return out;
	}
};

float getHighestPower(std::vector<Vehicle*> vector)
{
	float Power = 0;
	float currentPower = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		if (dynamic_cast<Car*>(vector[i]))
		{
			currentPower = dynamic_cast<Car*>(vector[i])->getEngine().getPower();
			if (currentPower > Power)
			{
				Power = currentPower;
			}
		}
	}
	return Power;
}

int main()
{
	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	std::cout << c << '\n';

	Bicycle t(Wheel(20), Wheel(20), 300);
	std::cout << t << '\n';
	
	std::vector<Vehicle*> v;
	
	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));
	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));
	v.push_back(new WaterVehicle(5000));

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << (*v[i]) << '\n';
	}

	std::cout << "The highest power is " << getHighestPower(v) << '\n';

	
	for (int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}
};