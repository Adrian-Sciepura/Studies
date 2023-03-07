#include <iostream>
#include <math.h>
using namespace std;

//BASE64 Encoding program

void encode(bool binary_triplet[24])
{
	const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int result = 0;
	for (int i = 0; i < 24; i++)
	{
		if (i % 6 == 0 && i != 0)
		{
			cout << symbols[result];
			result = 0;
		}

		if (binary_triplet[i])
		{
			result += pow(2, 5 - (i % 6));
		}
	}
	cout << symbols[result];
}

bool* convert_char_ASCII_to_binary(char x)
{
	int ASCII = x;
	bool result[8];
	for (int i = 7; i >= 0; i--)
	{
		result[7-i] = ((x & (1U << i)) > 0);
	}
	return result;
}

int main() 
{
	char input[101];
	cin.get(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	i += 3 - i % 3;
	
	for (int j = 0; j < i / 3; j++)
	{
		bool binary_triplet[24];
		for (int k = 0; k < 3; k++)
		{
			bool* binary = convert_char_ASCII_to_binary(input[j*3+k]);
			for (int m = 0; m < 8; m++)
			{
				binary_triplet[k*8+m] = binary[m];
			}
		}

		encode(binary_triplet);
	}

	return 0;
};