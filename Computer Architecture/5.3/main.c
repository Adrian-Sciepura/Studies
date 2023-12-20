#include <stdlib.h>

extern void sumy(char* tab_a, char* tab_b, char* wynik);

int main()
{
	char liczby_A[16] = { -128, -127, -126, -125, -124, -123, -122,
		-121, 120, 121, 122, 123, 124, 125, 126, 127 };
	
	char liczby_B[16] = { -3, -3, -3, -3, -3, -3, -3, -3,
		3, 3, 3, 3, 3, 3, 3, 3 };

	char wynik[16];

	sumy(liczby_A, liczby_B, wynik);
}