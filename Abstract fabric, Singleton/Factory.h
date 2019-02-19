#pragma once
#include "Driver.h"
#include "Board.h"
#include <iostream>

class AbstractFactory
{
public:
	virtual Driver* createDriver() = 0;
	
	/*Something* createSomething()
	{
		return new Something();
	}*/
	
	
	Passenger* createPassenger() 
	{
		return new Passenger(); 
	}
	Carry* createCarry()
	{
		return new Carry();
	}
	virtual ~AbstractFactory() {}
	virtual BoardAnyCar* createBoard() = 0;
};

class BusFactory: public AbstractFactory
{
public:
	BusDriver* createDriver() override
	{
		return new BusDriver();
	}
	BoardBus* createBoard() override
	{
		return new BoardBus();
	}
};

class TaxiFactory : public AbstractFactory
{
public:
	TaxiDriver* createDriver() override
	{
		return new TaxiDriver();
	}
	BoardTaxi* createBoard() override
	{
		return new BoardTaxi();
	}

};
class CarryFactory : public AbstractFactory
{
public:
	CarryDriver* createDriver() override
	{
		return new CarryDriver();
	}
	BoardCarry* createBoard() override
	{
		return new BoardCarry();
	}

};