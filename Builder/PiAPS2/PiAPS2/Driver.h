#include <iostream>
#ifndef _PASS
#define _PASS

class Passenger
{
public:
	Passenger() { /*std::cout << "Passenger is created\n";*/ };
	//Passenger &operator=(Passenger&) {};
};

class Adult : public Passenger
{
public:
	Adult() { std::cout << "Adult is created\n"; }
};

class Social : public Passenger
{
public:
	Social() { std::cout << "Social is created\n"; }
};

class Child : public Passenger
{
public:
	Child() { std::cout << "Child is created\n"; }
};

enum Licenze { ACategory,BCategory, DCategory };

class Driver
{
public:
	Licenze licenze;
	Driver() {};
};

class TaxiDriver : public Driver
{
public:
	TaxiDriver()
	{
		std::cout << "TaxiDriver is created\n";
		licenze = BCategory;
	}
};
class BusDriver : public Driver
{
public:
	BusDriver()
	{
		std::cout << "BusDriver is created\n";
		licenze = DCategory;
	}
};
class MotoDriver : public Driver
{
public:
	MotoDriver()
	{
		std::cout << "MotoDriver is created\n";
		licenze = ACategory;
	}
};
#endif // !_PASS