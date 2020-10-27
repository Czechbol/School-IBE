
// cv10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "solution.h"
#include <iostream>

int main()
{
	char str[512];  
	int a=0, n=0, w=0;
	FILE* open;
	errno_t errorCode = fopen_s(&open, "vstup.txt", "r");
	if (open == NULL) {
		perror("Error opening file");
		return(-1);
	}
	while (!feof(open))
	{
		if (fscanf_s(open, "%s", str, 100) > 0)
		{
			a = a + alpha(str);
			n = n + numb(str);
			w = w + numb_of_word(str);
		}
	}


	printf("pocet pismen %d , pocet cisel %d , pocet slov %d\n", a, n, w);

	FILE* end;
	errno_t errorCode1 = fopen_s(&end, "vysledky.txt", "w");
	if (end == NULL) {
		perror("Error opening file");
		return(-1);
	}
	fprintf(end, "number of characters %d and number of digit %d and number of word is %d\n", a, n, w);
	fclose(end);
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
