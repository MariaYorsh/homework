// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "L6.h"
#include <math.h>

# define pi          3.14159265358979323846 
using namespace Integral;

int main()
{
	double BeginSegm = 0, EndSegm = pi/2, PreviosIntegral = 0, NextIntegral = 1, Epsilon;
	int n;

	while (true)
	{
		//std::cout << "Enter the value of regs of segment" << std::endl;
		//std::cin >> BeginSegm >> EndSegm;
		std::cout << "Enter accuracy and partitions number: " << std::endl;
		std::cin >> Epsilon >> n;


		if ((BeginSegm < EndSegm) && (n > 0) &&
			(Epsilon < 1) && (Epsilon > 0))
		{
			break;
		}
		else
		{
			std::cout << "Parameters are incorrect!!!Try again!" << std::endl;
		}
	}

			while (fabs(PreviosIntegral - NextIntegral) >
				Epsilon)
			{
				PreviosIntegral = LeftRectangle(BeginSegm,
					EndSegm, n);
				NextIntegral = LeftRectangle(BeginSegm,
					EndSegm, 2 * n);
				n = 2 * n;
			}
	
			std::cout << NextIntegral << std::endl;

			std::cout << "Enter accuracy and partitions number: " << std::endl;
			std::cin >> Epsilon >> n;


			while (fabs(PreviosIntegral - NextIntegral) >
				Epsilon)
			{
				PreviosIntegral = RightRectangle(BeginSegm,
					EndSegm, n);
				NextIntegral = RightRectangle(BeginSegm,
					EndSegm, 2 * n);
				n = 2 * n;
			}

			std::cout << NextIntegral << std::endl;
			
    return 0;
}

