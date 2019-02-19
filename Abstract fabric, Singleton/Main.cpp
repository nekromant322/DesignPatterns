#include "BusStation.h"
#include <vector>
#include <iostream>
#include<ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	auto BS = new BusStation();
	auto BF = BusFactory();
	auto TF = TaxiFactory();
	auto CF = CarryFactory();
	BoardAnyCar* BBus = BS->createBoard(BF);
	BoardAnyCar* BTaxi = BS->createBoard(TF);
	BoardAnyCar* BCarry = BS->createBoard(CF);
	std::cout<< BBus->isReady() << std::endl;
	std::cout << BTaxi->isReady() << std::endl;
	std::cout << BCarry->isReady() << std::endl;

	system("pause");
	delete BS;
	delete BBus;
	delete BTaxi;
	delete BCarry;
	return 0;
}