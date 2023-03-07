#include <iostream>
#define QUANTITY 10
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
                int temp = numbers[j-1];
                numbers[j - 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    cout << endl;

    int pos = 1;
    cout << pos << ' ' << numbers[0] << endl;
    for (int i = 1; i < QUANTITY; i++)
    {
        if (numbers[i - 1] != numbers[i])
        {
            pos++;
        }
        cout << pos << ' ' << numbers[i] << endl;
    }


}
