#include <stdlib.h>

extern void zamien2(int* calkowite, float* zmienno_przec);

int main()
{
	int calkowite[2] = { -17, 24 };
	float zmienno_przecinkowe[4];

	zamien2(calkowite, zmienno_przecinkowe);
}