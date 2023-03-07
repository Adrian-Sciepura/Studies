#include <iostream>
using namespace std;

int sum_diagonal(int number_array[4][4], int size, char corner)
{
	int result = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (corner == 'l')
		{
			result += number_array[i][i];
		}
		else if (corner == 'r')
		{
			result += number_array[i][size-i-1];
		}
	}

	return result;
}

int sum_line(int number_array[4][4], int size, int line, char orientation)
{
	int result = 0;

	for (int i = 0; i < size; i++)
	{
		if (orientation == 'h')
		{
			result += number_array[line][i];
		}
		else if (orientation == 'v')
		{
			result += number_array[i][line];
		}
	}

	return result;
}

bool is_magic(int number_array[4][4], int size)
{
	int* line_sums = (int*)malloc((size * 2 + 2) * sizeof(int));
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		line_sums[index] = sum_line(number_array, size, i, 'h');
		index++;
	}

	for (int i = 0; i < size; i++)
	{
		line_sums[index] = sum_line(number_array, size, i, 'v');
		index++;
	}

	line_sums[index] = sum_diagonal(number_array, size, 'l');
	index++;
	line_sums[index] = sum_diagonal(number_array, size, 'r');
	
	int first = line_sums[0];
	for (int i = 0; i < size * 2 + 2; i++)
	{
		if (line_sums[i] != first)
		{
			free(line_sums);
			return false;
		}
	}

	free(line_sums);
	return true;
}

int main()
{
	int magic_square[4][4] = {2, 16, 13, 3, 11, 5, 8, 10, 7, 9, 12, 6, 14, 4, 1, 15};
	if (is_magic(magic_square, 4))
	{
		cout << "Magic Square";
	}
	else
	{
		cout << "Not Magic Square";
	}
}