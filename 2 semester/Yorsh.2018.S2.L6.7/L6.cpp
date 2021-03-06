// L6.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "L6.h"
#include <cmath>
#include <iostream>

L6_API double Integral::SineDividedByValue(double value)
{
	double d; 
	if (value == 0)
	{
		d = 1;
	}
	else 
	{
        d = sin(value) / value;
	}
		
	return d;
}

L6_API double Integral::LeftRectangle(double LowerLimit, double UpperLimit, int k)
{
	double Step = (LowerLimit + UpperLimit) / k;
	double Integral = 0;
	double t = LowerLimit;
	while (t < UpperLimit)
	{
		Integral = Integral + SineDividedByValue(t);
		t = t + Step;
	}
	Integral = Step * Integral;
	return Integral;
}

L6_API double Integral::RightRectangle(double LowerLimit, double UpperLimit, int k)
{
	double Step = (LowerLimit + UpperLimit) / k;
	double Integral = 1;
	double t = LowerLimit + Step;
	while (t <= UpperLimit)
	{
		Integral = Integral + SineDividedByValue(t);
		t = t + Step;
	}
	Integral = Step * Integral;
	return Integral;
}

