#pragma once
#include <iostream>

using namespace std;
enum Licenze { BCategory,CCategory ,DCategory };
enum Social { standart, kid, student, old, carry };

class Something
{
public:
	Something()
	{
		cout << "Создано нечто для погрузки" << endl;
	}


};
class Carry : Something
{
public:
	int weight;
	Carry()
	{
		weight = rand() % 100;
		std::cout << "Груз создан, его масса: " << weight << endl;
	}

};


class Passenger : Something
{
	
public:
	Social sc;
	Passenger()
	{
		
		
		if (rand() % 3 == 0)
		{
			sc = kid;
		}
		else if (rand() % 6 == 0)
		{
			sc = old;
		}
		else if (rand() % 5 == 0)
		{
			sc = student;
		}
		else
		{
			sc = standart;
		}
		std::cout << "Пассажир создан, тип пассажира: " << sc << endl;
		
	};
	//Passenger &operator=(Passenger&) {};
};


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
		
		std::cout << "Водитель такси создан\n";
		licenze = BCategory;
	}
};
class BusDriver : public Driver
{
public:
	BusDriver()
	{
		
		std::cout << "Водитель автобуса создан\n";
		licenze = DCategory;
	}
};
class CarryDriver : public Driver
{
public:
	CarryDriver()
	{

		std::cout << "Водитель грузовика создан создан\n";
		licenze = CCategory;
	}
};
