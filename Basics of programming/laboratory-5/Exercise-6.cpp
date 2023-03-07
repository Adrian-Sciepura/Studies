#include <iostream>
using namespace std;

/*
	Zadanie 6. Napisz funkcjê, która oblicza n-t¹ liczbê ci¹gu podobnego do Fibonacciego:
	F(n+3) = a * F(n+2) + b * F(n), F(0) = 0, F(1) = 0, F(2) = 1
*/

double f_star(int n, double a, double b)
{
	double f0 = 0, f1 = 0, f2 = 1, result = 0;
	for (int i = 3; i < n; i++)
	{
		result = a * f2 + b * f0;
		f0 = f1;
		f1 = f2;
		f2 = result;
	}
	return result;

}

int main()
{
	cout << f_star(5, 2, 4);
	return 0;
}