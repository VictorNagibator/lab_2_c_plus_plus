#include <iostream>
#include <windows.h>  
#include "LaptopFix.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//пример работы с динамическим массивом "Order"
	Order* ordersArray = new Order[2];
	for (int i = 0; i < 2; i++)
	{
		ordersArray[i].Input();
		ordersArray[i].Print();
	}
	ordersArray[0].SetStatus(FINISHED);
	ordersArray[0].Print();
	delete[] ordersArray;

	//пример работы с массивом динамических объектов "Laptop"
	Laptop* laptopsArray[2];
	laptopsArray[0] = new Laptop();
	laptopsArray[0]->Input();
	laptopsArray[0]->Print();
	(*laptopsArray[0]).BoostRAM();
	laptopsArray[0]->BoostCPU();
	laptopsArray[0]->Print();
	laptopsArray[1] = new Laptop();
	laptopsArray[1]->Print();
	for (size_t i = 0; i < 2; i++) delete laptopsArray[i];
}