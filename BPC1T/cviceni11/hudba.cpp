// hudba.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "hudbadb.h"
#include <ctype.h>              // tolower
#include <stdlib.h>				// system

struct t_auto * prvni = NULL; // globalni ukazatel na prvni auto

void OnAdd()
{
	char album_name[ZNACKA_SIZE];
	char interpret_name[ZNACKA_SIZE];
	int my_year;

	printf("\ninterpret : ");         // dotazeme se na polozky
	scanf_s("%s", interpret_name, sizeof(interpret_name));
	while (getchar() != '\n');
	printf("\nalbum : ");         // dotazeme se na polozky
	scanf_s("%s", album_name, sizeof(album_name));
	while (getchar() != '\n');
	printf("\nRok : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	add(interpret_name, album_name, my_year, &prvni);         // volame pridavaci funkci
}

void OnDel()
{
	char interpret_name[ZNACKA_SIZE];

	printf("\ninterpret : ");
	scanf_s("%s", interpret_name, sizeof(interpret_name));
	//while (getchar() != '\n');
	del(interpret_name, &prvni);         // volame mazaci funkci
}

void ShowCars()
{
	struct t_auto * aktAuto = prvni; // ukazatel na aktualni auto
	printf("\n\n");
	while (aktAuto) // prochazeni seznamu
	{
		printf("%d: %s -> %s\n", aktAuto->rok, aktAuto->interpret, aktAuto->album); // tisk radku
		aktAuto = aktAuto->dalsi; // posun na dalsi auto
	}
	getchar();
}


int main()
{
	char  cmd;

	do
	{
		system("cls");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowCars();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
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
