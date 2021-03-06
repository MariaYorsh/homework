// L7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <math.h>

#define TRUE 1

using namespace std;


double ModifiedNewtonMethod(double Previous, double Epsilon, int a);
double Derivative(double x,int a);
double Function(double x,int a);
double DerivativeTwo(double x, int a);
double SecantMethod(double Previous, double PreviousTwo, double Epsilon, int a);

int main()
{
	double Root, Epsilon;
	while (TRUE)
	{
		cout << "Enter the initial approximation and accuracy" << endl;
		cin >> Root;
		cin >> Epsilon;
		if ((Epsilon < 1) && (Epsilon > 0))
		{
			break;
		}
		else
		{
		   cout << " Accuracy is incorrect!!! Try  again!!!" << endl;
		}
	}
	cout << " Modified Newton Method: " << endl;
			for (int i = 1; i <= 5; i++)
			{
				double x = ModifiedNewtonMethod(Root, Epsilon, i);
				cout  << " a = " << i << "   x = " << x << endl;
			}
			cout << " Secant Method: " << endl;
			for (int i = 1; i <= 5; i++)
			{
				double x = SecantMethod(Root, Root + 0.1 , Epsilon, i);
				cout <<  "a = " << i << "   x = " << x << endl;
			}

	
    return 0;
}


 double ModifiedNewtonMethod(double Previous, double Epsilon, int a)
{
	double Following = Previous -
		Function(Previous, a) / Derivative(Previous, a ) -
		Function(Previous,a)*Function(Previous,a)* DerivativeTwo(Previous, a) /
		(2 * (Derivative(Previous,a)*Derivative(Previous,a)));
	while (fabs(Previous - Following) >= Epsilon)
	{
		Previous = Following;
		Following = Previous - Function(Previous,a) / Derivative(Previous,a) -
			Function(Previous,a)*Function(Previous,a)* DerivativeTwo(Previous,a) /
			(2 * (Derivative(Previous,a)*Derivative(Previous,a)));
	}
	return Following;
}

 double Derivative(double x,int a)
{
	return 3 - a * exp(a*x);
}

 double Function(double x,int a)
{
	return 3 * x - exp(a*x);
}
 double DerivativeTwo(double x, int a)
 {
	 return -a * a * exp(a*x);
 }

 double SecantMethod(double Previous, double PreviousTwo, double Epsilon, int a)
 {
	 double Follow;
	 while (fabs(Previous - PreviousTwo) >= Epsilon)
	 {
		Follow = Previous;
		Previous = Previous - ((Previous - PreviousTwo)*Function(Previous, a)) / (Function(Previous, a) - Function(PreviousTwo, a));
		 PreviousTwo = Follow;
	 }

	 return Follow;
 }