#include <iostream>
using namespace std;

int find(int numbers_array[], int array_size, int number_to_find)
{
    if (numbers_array[array_size] == number_to_find)
    {
        return array_size;
    }
    if (array_size == 0)
    {
        return -1;
    }
    find(numbers_array, array_size - 1, number_to_find);

}


int main()
{
    int arr[5] = { 1, 3, 5, 6, 7 };
    cout << find(arr, 5, 6);
}
