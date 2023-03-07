#include <iostream>
#define QUANTITY 6
using namespace std;

int main()
{
	int numbers[QUANTITY];
	for (int i = 0; i < QUANTITY; i++)
	{
		int number;
		cin >> number;
		numbers[i] = number;
	}

    for (int i = 0; i < QUANTITY; i++)
    {
        for (int j = 1; j < QUANTITY - i; j++)
        {
            if (numbers[j - 1] < numbers[j])
            {
                int temp = numbers[j - 1];
                numbers[j - 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    double median = 0;
    if (QUANTITY % 2)
    {
        median = numbers[QUANTITY / 2];
    }
    else
    {
        median = (double)(numbers[(QUANTITY / 2)-1] + numbers[QUANTITY / 2])/2;
    }

    cout << endl;
    cout << median;
}
