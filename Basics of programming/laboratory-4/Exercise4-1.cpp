#include <iostream>
#define SIZE 15
using namespace std;

//Wypełnij tablicę, tak że granice są oznaczone gwiazdkami
int main() {
	char tab[SIZE][SIZE];
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 || i == SIZE - 1)
			{
				cout << '*';
			}
			else if (j == 0 || j == SIZE - 1)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}

		}
		cout << endl;
	}

	return 0;
}