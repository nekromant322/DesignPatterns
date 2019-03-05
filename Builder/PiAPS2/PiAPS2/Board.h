#include <vector>
#include "Driver.h"
#ifndef _BOARD
#define _BOARD

class BoardException{};

class BoardAnyCar
{
protected:
	Driver *driver;
	std::vector<Passenger*> passengers;
	unsigned maxPassengers;
public:
	unsigned childSafetySeat = 0;
	~BoardAnyCar()
	{
		if(!driver)
			delete driver;
		passengers.clear();
		passengers.shrink_to_fit();
	}
	bool isReady()
	{
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1)
			return false;
		return true;
	}
	void BoardPassenger(Passenger* p) {
		if (passengers.size() == maxPassengers)
			throw new BoardException{};
		else
			passengers.push_back(p);
	}
	virtual void BoardDriver() = 0;
};

class BoardTaxi: public BoardAnyCar
{
public:
	BoardTaxi() 
	{ 
		maxPassengers = 4;
		std::cout << "BoardTaxi is created\n";
	}
	void BoardDriver() {driver = new TaxiDriver();}
	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCar
{
public:
	BoardBus() 
	{ 
		maxPassengers = 30;
		std::cout << "BoardBus is created\n";
	}
	void BoardDriver() {driver = new BusDriver();}
	~BoardBus() {};
};
class BoardMoto : public BoardAnyCar
{
public:
	BoardMoto()
	{
		maxPassengers = 1;
		std::cout << "BoardMoto is created\n";
	}
	void BoardDriver() { driver = new MotoDriver(); }
	~BoardMoto() {};
};



#endif // !_BOARD