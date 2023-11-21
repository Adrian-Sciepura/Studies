#include <stdio.h>

extern int szukaj4_max(int a, int b, int c, int d);

int main()
{
	int x = szukaj4_max(170, 12, 34, 5);
	printf("%d", x);
}