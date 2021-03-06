// cv09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "complexMath.h"
#include <ctype.h>            
#include <stdlib.h>             
#include <string.h> 
#include <iostream>

int main()
{
	typOperace d;
	formatZobrazeni e;
	int x = 0;
	struct complex *cl1;
	struct complex *cl2;
	struct complex clm;
	cl1 = (struct complex *) malloc(sizeof(complex));
	cl2 = (struct complex *) malloc(sizeof(complex));
	printf("input 1st number with space between real and complex part: ");
	scanf_s("%lf%lf", &cl1->real, &cl1->imag);
	printf("input 2st number with space between real and complex part: ");
	scanf_s("%lf%lf", &cl2->real, &cl2->imag);
	while (x<5)
	{
		printf("press 1 for addition, 2 for subtraction, 3 multiplication and 4 division or 99 for end program: ");
		scanf_s("%d", &d);
		if (d == 1 || d == 2 || d == 3 || d==4)
		{
			clm = operace(*cl1, *cl2, d);
			x = 0;
			break;
		}
		else if (d == 99)
		{
			exit(99);
		}
		else
		{
			x++;
		}
		if (x == 5)
		{
			exit(98);
		}
	}
	while(x<5)
	{
		printf("press 0 for algebraic form and 1 geometric form or 99 for end program: ");
		scanf_s("%d", &e);
		if (e == 0 || e == 1)
		{
			tisk(clm, e);
			break;
		}
		else if (d == 99)
		{
		exit(99);
		}
		else
		{
		x++;
		}
		if (x == 4)
		{
			exit(98);
		}
	}

	//printf("%lf	%lf		%lf	%lf",cl1->real, cl1->imag, cl2->real, cl2->imag);

	free(cl1);
	free(cl2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
