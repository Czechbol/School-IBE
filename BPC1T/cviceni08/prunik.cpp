// prunik.cpp : This file contains the 'main' function. Program execution begins and ends there.
//xjedli24

#include "pch.h"
#include "xjedli24.h"
#include <windows.h>
#include <iostream>
int main() {
	double vysl_zacatek;
	double vysl_konec;

	double a, b, c, d;
	int e;
	printf("napiste prvni interval: ");
	scanf_s("%lf %lf", &a, &b);
	printf("napiste druhy interval: ");
	scanf_s("%lf %lf", &c, &d);
	e = prunik(a, b, c, d, &vysl_zacatek, &vysl_konec);


	if (a == c && e == true)
	{
		if (b == d)
		{
			printf("<%lf %lf>\n", vysl_zacatek, vysl_konec);
			vypis(a,b,c,d);
		}
		else
		{
			printf("<%lf %lf)\n", vysl_zacatek, vysl_konec);
			vypis(a, b, c, d);
		}
	}
	else if (e == true && b == c)
	{
		printf("<%lf %lf>\n", vysl_zacatek, vysl_konec);
		vypis(a, b, c, d);
	}
	else if (e == true)
	{
		if (b == d)
		{
			printf("(%lf %lf>\n", vysl_zacatek, vysl_konec);
			vypis(a, b, c, d);
		}
		else
		{
			printf("(%lf %lf)\n", vysl_zacatek, vysl_konec);
			vypis(a, b, c, d);
		}
	}
	else if (e == 0)
	{
		printf("mezi cisli neexistuje prunik\n");
		vypis(a, b, c, d);
	}

	else
	{
		printf("neco se nepodarilo");
		Sleep(30);
		exit(0);
	}
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
