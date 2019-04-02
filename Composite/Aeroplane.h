#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <memory>
using namespace std;
typedef unsigned int uint;
//Component
class Unit
{
protected:
	map<pair<uint,uint>, Unit*> uvec;
	uint mutable weight;
	uint row;
	uint position;
public:
	virtual uint getWeight() const = 0;
	virtual	void addUnit(Unit*) {};
	virtual void deleteUnit(pair<uint, uint>) {};
	virtual uint getRow() const { return row; }
	virtual uint getPos() const { return position; }
	virtual const map<pair<uint, uint>, Unit*> &getUnits() const {}
};

//Primitives
class Passenger : public Unit
{
public:
	Passenger(int) = delete;
	Passenger() = delete;
	Passenger(uint weight, pair<uint,uint> place)
	{
		row = place.first;
		position = place.second;
		/*
		if (weight == 0)
			cout << endl << "\tBaggage dropped" << endl;
		else
			cout << " with weight=" << weight << endl;
			*/
		this->weight = weight;
	};
	uint getWeight() const override { return weight; }
	void setWeight(uint weight) { this->weight = weight; }
};

class Pilot : public Unit
{
public:
	Pilot() { cout << "Pilot is added\n"; }
	uint getWeight() const override { return 0; }
};

class Stewardess : public Unit
{
public:
	Stewardess() { cout << "Stewardess is added\n"; }
	uint getWeight() const override { return 0; }
};

enum MaxPassengers { EconomPass = 150, BusinessPass = 20, FirstPass = 10 };
enum MaxWeight { EconomWeight = 20, BusinessWeight = 35, AllWeight = 60, MinWeight = 5 };

class CompositeFirstClass : public Unit
{
public:
	CompositeFirstClass(pair<uint,uint> size) 
	{ 
		row = size.first;
		position = size.second;
	}
	uint getWeight() const override
	{
		weight = 0;
		for (const auto& v : uvec)
			weight += v.second->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (uvec.size() <= MaxPassengers::FirstPass)
			uvec[make_pair(u->getRow(), u->getPos())] = u;
		//else
			//throw new UnitOverflowException();
	}
	~CompositeFirstClass()
	{
		for (const auto &c : uvec)
			delete c.second;
	}
	const map<pair<uint, uint>, Unit*> &getUnits() const override { return uvec; }
};

class CompositeEconomClass : public Unit
{
public:
	CompositeEconomClass(pair<uint, uint> size)
	{
		row = size.first;
		position = size.second;
	}
	uint getWeight() const override
	{
		weight = 0;
		for (const auto& v : uvec)
			weight += v.second->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (uvec.size() < MaxPassengers::EconomPass)
			uvec[make_pair(u->getRow(), u->getPos())] = u;
		//else
			//throw new UnitOverflowException();
	}
	~CompositeEconomClass()
	{
		for (const auto &c : uvec)
			delete c.second;
	}
	const map<pair<uint, uint>, Unit*> &getUnits() const override { return uvec; }
};

class CompositeBusinessClass : public Unit
{
public:
	CompositeBusinessClass(pair<uint, uint> size)
	{
		row = size.first;
		position = size.second;
	}
	uint getWeight() const override
	{
		weight = 0;
		for (const auto& v : uvec)
			weight += v.second->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (uvec.size() < MaxPassengers::BusinessPass)
			uvec[make_pair(u->getRow(), u->getPos())] = u;
		//else
		//	throw new UnitOverflowException();
	}
	~CompositeBusinessClass()
	{
		for (const auto &c : uvec)
			delete c.second;
	}
	const map<pair<uint, uint>, Unit*> &getUnits() const override { return uvec; }
};

enum Ticket {Row = 50, Position = 6};

class Aeroplane : public Unit
{
	unique_ptr<CompositeBusinessClass> business;
	unique_ptr<CompositeEconomClass> econom;
	unique_ptr<CompositeFirstClass> first;
	vector<Stewardess*> stewardesses;
	vector<Pilot*> pilots;
	static const uint maxWeight = 500;
public:
	Aeroplane(size_t economPass, size_t businessPass, size_t firstPass)
	{
		weight = 0;
		uint r = 0; uint p = 0;
		cout << "Aeroplane is created\n";
		for (size_t i = 0; i < 2; i++)
			pilots.push_back(new Pilot());
		for (size_t i = 0; i < 6; i++)
			stewardesses.push_back(new Stewardess());
		first = make_unique<CompositeFirstClass>(make_pair<uint, uint>(Ticket::Row, Ticket::Position));
		for (size_t i = 0; i < firstPass; i++) 
		{
			p = p++ % Ticket::Position + 1;
			first->addUnit(new Passenger(				
				rand() % (MaxWeight::AllWeight - MaxWeight::MinWeight) + MaxWeight::MinWeight),
				make_pair<uint, uint>(
					p == 0 ? ++r : r, 
					p)
			);
		}
		business = make_unique<CompositeBusinessClass>(make_pair<uint, uint>(Ticket::Row, Ticket::Position));
		for (size_t i = 0; i < businessPass; i++)
			business->addUnit(new Passenger(rand() % (MaxWeight::BusinessWeight - MaxWeight::MinWeight) + MaxWeight::MinWeight));
		weight = business->getWeight() + first->getWeight();

		econom = make_unique<CompositeEconomClass>(make_pair<uint, uint>(Ticket::Row, Ticket::Position));
		if (weight >= maxWeight)
		{
			for (size_t i = 0; i < economPass; i++)
				econom->addUnit(new Passenger(0));
		}
		else
		{
			static uint rnd = 0;
			for (size_t i = 0; i < economPass; i++)
			{
				rnd = rand() % (MaxWeight::EconomWeight - MaxWeight::MinWeight) + MaxWeight::MinWeight;
				if (weight + rnd > maxWeight)
				{
					econom->addUnit(new Passenger(0));
				}
				else
				{
					weight += rnd;
					econom->addUnit(new Passenger(rnd));
				}

			}
		}
	}
	uint getWeight() const override
	{
		return weight;
	}
	~Aeroplane()
	{
		for (auto &c : stewardesses)
			delete c;
		stewardesses.clear();
		stewardesses.shrink_to_fit();
		for (auto &c : pilots)
			delete c;
		pilots.clear();
		pilots.shrink_to_fit();
	}
};