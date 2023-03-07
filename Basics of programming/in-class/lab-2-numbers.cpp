#include <iostream>
using namespace std;

int replace(int arr[], int value_to_change, int new_value, int len)
{
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == value_to_change)
        {
            arr[i] = new_value;
            counter++;
        }
    }
    return counter;
}

int sum(int arr[], int start_index, int last_index)
{
    int result = 0;
    for (int i = start_index; i < last_index; i++)
    {
        result += arr[i];
    }
    return result;
}

int min_value(int arr[], int start_index, int last_index)
{
    int min = arr[start_index];

    for (int i = start_index; i < last_index; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int numbers[1000], how_many_numbers, how_many_operations;
    cin >> how_many_numbers;

    for (int i = 0; i < how_many_numbers; i++)
    {
        cin >> numbers[i];
    }

    cin >> how_many_operations;

    for(int i = 0; i < how_many_operations; i++)
    {
        char operation;
        cin >> operation;
        switch (operation)
        {
            case 'c':
            {
                int value_to_change, new_value;
                cin >> value_to_change >> new_value;
                cout << replace(numbers, value_to_change, new_value, how_many_numbers) << '\n';
                break;
            }
            case 's':
            {
                int how_many_to_add_up;
                cin >> how_many_to_add_up;

                int how_many_pairs = how_many_numbers / how_many_to_add_up;
                int how_many_left = how_many_numbers - how_many_pairs * how_many_to_add_up;

                for (int j = 0; j < how_many_pairs; j++)
                {
                    cout << sum(numbers, how_many_to_add_up * j, how_many_to_add_up * (j + 1)) << ' ';
                }
                
                if (how_many_left > 0)
                {
                    cout << sum(numbers, how_many_numbers - how_many_left, how_many_numbers);
                }

                cout << '\n';

                break;
            }
            case 'm':
            {
                int start_index, last_index;
                cin >> start_index >> last_index;

                if (start_index > last_index || start_index > how_many_numbers+1 || last_index < 1)
                {
                    cout << '#' << '\n';
                    break;
                }

                if (start_index < 1)
                {
                    start_index = 1;
                }

                if (last_index > how_many_numbers + 1)
                {
                    last_index = how_many_numbers + 1;
                }

                cout << min_value(numbers, start_index - 1, last_index) << '\n';
                break;
            }
        }
    }
}