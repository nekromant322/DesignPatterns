#include "Driver.h"
#include "Board.h"
#include <iostream>

template<class BoardAnyCar>
class AbstractFactory
{
protected:
	virtual BoardAnyCar* create() = 0;
	~AbstractFactory() {}
};

class BusFactory: public AbstractFactory<BoardBus>
{
public:
	BoardBus *create()
	{
		return new BoardBus();
	}
};

class TaxiFactory : public AbstractFactory<BoardTaxi>
{
public:
	BoardTaxi *create()
	{
		return new BoardTaxi();
	}
};