#include <iostream>
using namespace std;

/*
	Zadanie 3. Zaimplementuj funkcje max3, max4, max5.W ich implementacji wywo³ywaæ
	funkcjê max2. Dodaæ nag³ówki tych funkcji.
*/

int max2(int a, int b);
int max3(int arr[]);
int max4(int arr[]);
int max5(int arr[]);

int main()
{
	int tab[] = {4, 5, 2, 1 ,7};
	cout << max5(tab);
}

int max2(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

int max3(int arr[])
{
	return max2(max2(arr[0], arr[1]), arr[2]);
}

int max4(int arr[])
{
	return max2(max2(arr[0], arr[1]), max2(arr[2], arr[3]));
}

int max5(int arr[])
{
	return max2(max2(max2(arr[0], arr[1]), max2(arr[2], arr[3])), arr[4]);
}