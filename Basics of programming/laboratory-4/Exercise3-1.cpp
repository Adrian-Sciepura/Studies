#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#define SIZE 250

//Zaproponuj sposób losowania ocen z prawdopodobieństwami 2 - 20 %, 3 - 15 %, 3,5
//- 25 %, 4 - 20 %, 4,5 - 10 %, 5 - 10 %, 5,5 - 5 % .


using namespace std;
int main() {
	const double ratings[] = { 2, 3, 3.5, 4, 4.5, 5, 5.5 };
	int results[SIZE], stat[7] = {}, i;
	srand (time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		results[i] = rand() % 100 + 1;
	}
	for (i = 0; i < SIZE; i++)
	{
		int temp = results[i];

		if (temp >= 1 && temp <= 20)
		{
			stat[0]++;
		}
		else if (temp > 20 && temp <= 35)
		{
			stat[1]++;
		}
		else if (temp > 35 && temp <= 60)
		{
			stat[2]++;
		}
		else if (temp > 60 && temp <= 80)
		{
			stat[3]++;
		}
		else if (temp > 80 && temp <= 90)
		{
			stat[4]++;
		}
		else if (temp > 90 && temp <= 95)
		{
			stat[5]++;
		}
		else if (temp > 95 && temp <= 100)
		{
			stat[6]++;
		}
	}
		
	for (i = 0; i < 7; i++)
		cout << ratings[i] << setw(15) << stat[i] << endl;
	return 0;
}