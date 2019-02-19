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
		cout << "������� ����� ��� ��������" << endl;
	}


};
class Carry : Something
{
public:
	int weight;
	Carry()
	{
		weight = rand() % 100;
		std::cout << "���� ������, ��� �����: " << weight << endl;
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
		std::cout << "�������� ������, ��� ���������: " << sc << endl;
		
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
		
		std::cout << "�������� ����� ������\n";
		licenze = BCategory;
	}
};
class BusDriver : public Driver
{
public:
	BusDriver()
	{
		
		std::cout << "�������� �������� ������\n";
		licenze = DCategory;
	}
};
class CarryDriver : public Driver
{
public:
	CarryDriver()
	{

		std::cout << "�������� ��������� ������ ������\n";
		licenze = CCategory;
	}
};
