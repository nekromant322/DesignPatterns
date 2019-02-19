#pragma once
#include "Factory.h"
#include <string>
class KidAloneException {};

class BusStation
{
	public:
	BoardAnyCar* createBoard(AbstractFactory& factory)
	{
		BoardAnyCar * Board = factory.createBoard();
		Board->BoardDriver(factory.createDriver());
		if (Board->type == "Taxi" || Board->type == "Bus")
		{
			for (size_t i = 0; i < Board->maxPassengers; i++)
			{
				Board->BoardPassenger(factory.createPassenger());
			}
			cout << "Обычных:" << Board->count_types[0] << endl << "Детей:" << Board->count_types[1] << endl << "Студентов:" << Board->count_types[2] << endl << "Пенсионеров:" << Board->count_types[3] << endl;
			if (Board->count_types[0] == 0 && Board->count_types[1] != 0 && Board->count_types[2] == 0 && Board->count_types[3] == 0)
			{
				throw KidAloneException();
			}
		}
		else
		{
			while(Board->current_weight < Board->maxWeight)
			{
				Board->BoardCarry(factory.createCarry());

			}
		}
		return Board;
	}
};