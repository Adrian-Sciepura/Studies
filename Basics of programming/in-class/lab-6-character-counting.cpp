#include <iostream>
using namespace std;

int count_character(const char text_arr[], int text_length, char character_to_find, int current_index = 0, int counter = 0)
{
	if (text_length == 0)
	{
		return 0;
	}
	if (current_index == text_length)
	{
		return counter;
	}

	if (text_arr[current_index] == character_to_find)
	{
		return count_character(text_arr, text_length, character_to_find, current_index + 1, counter + 1);
	}
	
	return count_character(text_arr, text_length, character_to_find, current_index + 1, counter);
	

}

int main()
{
	char text[] = "AABCBDEFB";
	int text_length = sizeof(text) / sizeof(text[0]);

	cout << count_character(text, text_length - 1, 'B');
}
