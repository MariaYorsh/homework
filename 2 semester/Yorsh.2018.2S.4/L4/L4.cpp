// L4.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "L4.h"
#include <stdexcept>
#include <iostream>

L4_API int * Array::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	int* a = new int[n];

	return a;
}

L4_API void Array::InitArray(int * const a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int* p = a; p < a + n; p++)
	{
		*p = rand() % 100;
	}
}

L4_API void Array::FreeMemory(int * const a)
{
	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	delete[] a; 
}

L4_API void Array::DisplayArray(const int * a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (const int* p = a; p < a + n; p++)
	{
	    std::cout << *p << " ";
	}
}

L4_API void Array::RemoveElement(int * const a, int & n, int k)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (k < 0 || k > n)
	{
		throw std::out_of_range("Position  of array must be more than  zero and less then!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = k; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}

	n--;
}

L4_API int Array::CountingElements(int * const a, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (a == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	int S = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && i % 2 == 0)
		{
			S++;
		}
	}
	return S;
}

L4_API void Array::SeparateArray(int * const a, int * const oldA, int * const newA, int n, int S)
{
	int j = 0, k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && i % 2 == 0)
		{
			newA[k] = a[i];
			k++;
		}
		else
		{
			oldA[j] = a[i];
			j++;
		}
	}
}

L4_API void Array::Swap(int & a, int & b)
{
	int t = a;
	a = b;
	b = t;
}

L4_API void Array::BubleSortByRemainder(int * const A, int P, int a)
{
	for (int i = 1; i < P; i++)
	{
		for (int j = 0; j < P - i; j++)
		{
			if (A[j] % a < A[j + 1] % a)
			{
				Swap(A[j], A[j + 1]);
			}
		}
	}
}
