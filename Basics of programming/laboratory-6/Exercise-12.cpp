#include <iostream>
using namespace std;

void change_first(int numbers_array[], int current_index, int array_size, int value_to_change, int new_value)
{
	if (current_index == array_size)
	{
		return;
	}
	if (numbers_array[current_index] == value_to_change)
	{
		numbers_array[current_index] = new_value;
		return;
	}
	change_first(numbers_array, current_index + 1, array_size, value_to_change, new_value);


}

int main()
{
	int arr[5] = {3, 7, 3, 5, 9};
	change_first(arr, 0, 5, 3, 8);

	for (int x : arr)
	{
		cout << x << ' ';
	}
}
