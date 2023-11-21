#include <stdio.h>

extern void liczba_przeciwna(int* liczba);

int main()
{
	int x = 10;
	liczba_przeciwna(&x);
	printf("%d", x);
}