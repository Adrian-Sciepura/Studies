#include <iostream>
#define SIZE 6

using namespace std;

int main()
{
	int arr1[SIZE], arr2[SIZE], join[2 * SIZE], i, j, k;
	for (i = 0; i < SIZE; i++)
		cin >> arr1[i];
	for (i = 0; i < SIZE; i++)
		cin >> arr2[i];
	for (k = 0; k < 2 * SIZE; k++) 
	{
		if(k < SIZE)
		{
			join[k] = arr1[k];
		}
		else
		{
			join[k] = arr2[k - SIZE];
		}
	}
	for (k = 0; k < 2 * SIZE; k++)
		cout << join[k] << " ";
	return 0;
}