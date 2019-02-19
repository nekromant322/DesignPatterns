#pragma once
#include <vector>
#include <string>
#include "Driver.h"

class BoardException{};
class NullException{};

class BoardAnyCar
{
protected:
	Driver *driver = nullptr;
	std::vector<Passenger*> passengers;
	
	
public:
	string type;
	vector<int> count_types = { 0,0,0,0 };
	unsigned maxPassengers = 0;
	unsigned maxWeight;
	int current_weight = 0;
	~BoardAnyCar()
	{
		if(driver)
			delete driver;
		for(auto p : passengers)
			delete p;
	}
	bool isReady()
	{
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1)
			return false;
		return true;
	}
	void BoardPassenger(Passenger* p) 
	{
		if (passengers.size() == maxPassengers)
		{
		
			throw BoardException();
		}
		else
		{
			passengers.push_back(p);
			count_types[(int) p[0].sc]++;
		}
	}
	void BoardCarry(Carry* p)
	{

			/*if (current_weight + p[0].weight < maxWeight)
			{

				throw BoardException();
			}
			else
			{
				*/
				current_weight = current_weight + p[0].weight;
			
	}
	void BoardDriver(Driver* d)
	{
		if (d)
			driver = d;
		else
			throw NullException();
	}
};

class BoardTaxi: public BoardAnyCar
{
public:
	BoardTaxi() 
	{ 
		type = "Taxi";
		maxPassengers = 4;
		std::cout << "BoardTaxi создан\n";
	}	
	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCar
{
public:
	BoardBus() 
	{ 
		type = "Bus";
		maxPassengers = 30;
		std::cout << "BoardBus создан\n";
	}
	~BoardBus() {};
};
class BoardCarry : public BoardAnyCar
{
public :
	//int maxweight;
	//int current_weight;
public:
	BoardCarry()
	{
		type = "Carry";
		//maxPassengers = 30;
		maxWeight = 1000;
		current_weight = 0;
		std::cout << "BoardBus создан\n";
	}
	~BoardCarry() {};
};
