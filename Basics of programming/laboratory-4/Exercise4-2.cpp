#include <iostream>
#define SIZE 15
using namespace std;

//Wypełnij tablicę, tak że gwiazdki i spacje pojawiają się na przemian (szachownica).
int main() {
	char tab[SIZE][SIZE];
	char first = '*';
	char second = '#';
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (j % 2)
			{
				cout << first;
			}
			else
			{
				cout << second;
			}
		}
		cout << endl;
		char temp = first;
		first = second;
		second = temp;
	}
	return 0;
}