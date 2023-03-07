#include <iostream>
using namespace std;

void array_reverse(int numbers_array[], int current_index, int array_size)
{
	if (current_index == array_size/2)
	{
		return;
	}
	int temp = numbers_array[current_index];
	int second_index = array_size - 1 - current_index;
	numbers_array[current_index] = numbers_array[second_index];
	numbers_array[second_index] = temp;
	array_reverse(numbers_array, current_index + 1, array_size);
}


int main()
{
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	array_reverse(arr, 0, 6);
	for (int x : arr)
	{
		cout << x << ' ';
	}
}