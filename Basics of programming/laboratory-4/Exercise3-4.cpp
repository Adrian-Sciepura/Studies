#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 250
using namespace std;

//Przy założeniu, że studenci zostali podzieleni na grupy po 25 osób i grupa składa
//się zawsze z kolejnych osób, oblicz proszę, która grupa uzyskała średnio najlepszy
//wynik, a która najgorszy.

int main() {
	const double ratings[] = { 2, 3, 3.5, 4, 4.5 , 5, 5.5 };
	int results[SIZE], stat[7] = { }, i;
	int groups[SIZE / 25]={};
	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
		results[i] = rand() % 7;
	for (i = 0; i < SIZE; i++)
		stat[results[i]]++;
	for (i = 0; i < 7; i++)
		cout << ratings[i] << " " << stat[i] << endl;

	int group = 0;
	for (i = 0; i < SIZE; i++)
	{
		group = i / 25;
		groups[group] += results[i];
	}

	int min = groups[0];
	int min_index = 0;

	int max = 0;
	int max_index = 0;
	for (i = 0; i < (sizeof groups / sizeof groups[0]); i++)
	{
		if (groups[i] > max)
		{
			max = groups[i];
			max_index = i;
		}

		if (groups[i] < min)
		{
			min = groups[i];
			min_index = i;
		}
	}

	cout << "Grupa z najgorszym wynikiem: " << min_index << ", grupa z najlepszym wynikiem: " << max_index;
	


	return 0;
}