#include <iostream>
using namespace std;

int check(char arr[10][10], int pos_x, int pos_y)
{
    int counter = 0;
    for (int i = pos_x - 1; i <= pos_x + 1; i++)
    {
        for (int j = pos_y - 1; j <= pos_y + 1; j++)
        {
            if (i == pos_x && j == pos_y)
            {
                continue;
            }
            if (i < 0 || i > 9)
            {
                continue;
            }
            if (j < 0 || j > 9)
            {
                continue;
            }
            if (arr[i][j] == '*')
            {
                counter += 1;
            }
        }
    }
    return counter;
}

void change(char arr[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == '.')
            {
                arr[i][j] = '0' + check(arr, i, j);
            }
        }
    }
}

void print(const char arr[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    char board[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }

    change(board);
    print(board);
}
