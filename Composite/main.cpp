#include "Aeroplane.h"

int main()
{
	auto A = new Aeroplane(20, 10, 5);
	std::cout << "\nWeight = " << A->getWeight() << std::endl;
	delete A;
	system("pause");
	return 0;
}