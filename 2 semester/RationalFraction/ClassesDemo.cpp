// ClassesDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RationalFraction.h"
#include <iostream>

using namespace std;

void DisplayFraction(const RationalFraction&);


int main()
{
	RationalFraction fraction(-2, -4), fraction1(-4, 8), fraction2(10, -5);
	//DisplayFraction(fraction);
	//DisplayFraction(fraction1);
	//DisplayFraction(fraction2);
	//fraction.SetFraction(1,33);
	//RationalFraction fr(fraction);
	//fraction1 = fr = fraction2;
	RationalFraction sum = fraction + fraction1;// fraction.operator+(fraction1);
	cout << fraction << " + " << fraction1 << " = " << sum << endl;
	RationalFraction temp = -fraction2;
	//cout << fraction2 << " -> - " << temp << endl;
	RationalFraction sub = fraction - fraction1;
	cout << fraction << " - " << fraction1 << " = " << sub << endl;
	RationalFraction mul = fraction * fraction1;
	cout << fraction << " * " << fraction1 << " = " << mul << endl;
	RationalFraction dev = fraction / fraction1;
	cout << fraction << " : " << fraction1 << " = " << dev << endl;

	return 0;
}

void DisplayFraction(const RationalFraction& fraction)
{
	if (fraction.GetDenominator() == 1)
	{
		cout << fraction.GetNumerator() << endl;
	}
	else
	{
		cout << fraction.GetNumerator() << " / " << fraction.GetDenominator() << endl;
	}
}

