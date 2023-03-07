#include <iostream>
#define QUANTITY 5
using namespace std;

bool already_exist(int tab[], int num)
{
    for (int j = 0; j < QUANTITY; j++)
    {
        if (tab[j] == num)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int numbers[QUANTITY];
    int index = 0;
    for (int i = 0; i < QUANTITY; i++)
    {
        int number;
        cin >> number;

        if (!already_exist(numbers, number))
        {
            numbers[index] = number;
            index++;
        }
    }

    cout << endl;

    for (int i = 0; i < index; i++)
    {
        cout << numbers[i] << ' ';
    }

}
