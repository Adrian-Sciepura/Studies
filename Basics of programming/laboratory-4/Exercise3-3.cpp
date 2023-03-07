#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 250
using namespace std;

//oblicz proszę średnią wylosowanych ocen oraz ile ocen jest powyżej średniej.
int main() {
	const double ratings[] = { 2, 3, 3.5, 4, 4.5 , 5, 5.5 };
	int results[SIZE], stat[7] = { }, i;
	int sum = 0, how_many = 0;
	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
		results[i] = rand() % 7;
	for (i = 0; i < SIZE; i++)
		stat[results[i]]++;
	for (i = 0; i < 7; i++)
	{
		cout << ratings[i] << " " << stat[i] << endl;
		sum += stat[i]*ratings[i];
	}

	double average = (double)sum / SIZE;
	cout << "Srednia ocen: " << average << endl;

	for (i = 0; i < 7; i++)
	{
		if (ratings[i] > average)
		{
			how_many += stat[i];
		}
	}
	cout << "Ilosc ocen powyzej sredniej: " << how_many;
	return 0;
}