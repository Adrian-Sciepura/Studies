#include <stdio.h>

extern void przestaw(int* tab, int ilosc_elementow);

int main()
{
	int tab[10] = { 9, 1, 12, 78, 4, 15, 92, 4, 22, 8 };

	for (int i = 0; i < 9; i++)
		przestaw(tab, 10 - i);

	for (int i = 0; i < 10; i++)
		printf("%d ", tab[i]);
}