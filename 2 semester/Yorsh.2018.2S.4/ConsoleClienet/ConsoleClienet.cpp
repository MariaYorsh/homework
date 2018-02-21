// ConsoleClienet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "L4.h"
#include <iostream>


int main()
{
	int n;

	std::cout << "Enter number of elemens: " << std::endl;
	std::cin >> n;
	

	int* array = Array::AllocateMemory(n);
	Array::InitArray(array, n);
	std::cout << "Our array: " << std::endl;
	Array::DisplayArray(array, n);
	std::cout << std::endl;

	int S = Array::CountingElements(array, n);
	std::cout << "Count of special elements S =" << S << std::endl;

	int* OldArray = Array::AllocateMemory(n - S);
	int* NewArray = Array::AllocateMemory(S);

	Array::SeparateArray(array, OldArray, NewArray, n, S);
	std::cout << "Old array: " << std::endl;
	Array::DisplayArray(OldArray, n - S);
	std::cout << std::endl;
	std::cout << "New array: " << std::endl;
	Array::DisplayArray(NewArray, S);
	std::cout << std::endl;

	int a;
	std::cout << "Enter remainder a= " << std::endl;
	std::cin >> a;
	Array::BubleSortByRemainder(OldArray, n-S, a);
	std::cout << "Sorted old array: " << std::endl;
	Array::DisplayArray(OldArray, n-S);
	std::cout << std::endl;

	Array::FreeMemory(array);



    return 0;
}

