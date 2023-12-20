#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


extern float srednia_harm(float* tablica, unsigned int n);

int main()
{
	int n;
	float* tablica;

	scanf("%d", &n);

	tablica = malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++)
		scanf("%f", &tablica[i]);

	float wynik = srednia_harm(tablica, n);

	printf("\nWynik: %f", wynik);
}