#include "Board.h"
#include "Driver.h"
#include <iostream>
class ChildAloneException {};
class BoardBuilder
{
protected:
	BoardAnyCar* p;
public:
	BoardBuilder(): p(nullptr) {}
	virtual void createBoard() = 0;
	virtual void buildAdult() = 0;
	virtual void buildSocial() = 0;
	virtual void buildChild() = 0;
	virtual void buildDriver() = 0;
	BoardAnyCar* getBoard() { return p; }
};

class BoardTaxiBuilder : public BoardBuilder
{
public:
	void createBoard() { p = new BoardTaxi; }
	void buildDriver() { p->BoardDriver(); }
	void buildAdult() { p->BoardPassenger(new Adult()); }
	void buildChild() { p->BoardPassenger(new Child()); p->childSafetySeat++; }
	void buildSocial() {};
};

class BoardBusBuilder : public BoardBuilder
{
public:
	void createBoard() { p = new BoardBus; }
	void buildDriver() { p->BoardDriver(); }
	void buildAdult() { p->BoardPassenger(new Adult()); }
	void buildChild() { p->BoardPassenger(new Child()); }
	void buildSocial() { p->BoardPassenger(new Social());	}
};
class BoardMotoBuilder : public BoardBuilder
{
public:
	void createBoard() { p = new BoardMoto; }
	void buildDriver() { p->BoardDriver(); }
	void buildAdult() { p->BoardPassenger(new Adult()); }
	void buildChild() { std::cout << "No child on the moto,sry" << std::endl; }
	void buildSocial() { }
};


class Director
{
public:
	BoardAnyCar* createBoard(BoardBuilder& builder, int AdultNum=1, int ChildNum=1, int SocialNum=0)
	{
		if (AdultNum == 0 && ChildNum != 0)
			throw ChildAloneException();
		builder.createBoard();
		builder.buildDriver();
		for (int i = 0; i < AdultNum; i++)
			builder.buildAdult();
		for (int i = 0; i < ChildNum; i++)
			builder.buildChild();
		for (int i = 0; i < SocialNum; i++)
			builder.buildSocial();
		return builder.getBoard();
	}
};