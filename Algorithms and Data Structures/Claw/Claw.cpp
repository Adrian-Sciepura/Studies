#include <iostream>

using std::cout;
using std::cin;

int main()
{
    int numberOfLines = 0;
    cin >> numberOfLines;

    for (int i = 0; i < numberOfLines; i++)
    {
        int matrixSize = 0;
        cin >> matrixSize;

        bool isClawFree = true;
        char** matrix = new char* [matrixSize];
        for (int j = 0; j < matrixSize; j++)
            matrix[j] = new char[matrixSize];

        char key = NULL;
        for (int j = 0; j < matrixSize; j++)
        {
            for (int k = 0; k < matrixSize; k++)
            {
                key = getchar();
                if (key == ' ')
                    key = getchar();

                matrix[j][k] = key;
            }
        }


        int counter = 0;
        for (int j = 0; j < matrixSize; j++)
        {
            counter = 0;
            for (int k = 0; k < matrixSize; k++)
            {
                if (matrix[j][k] == '1')
                    counter++;
            }
            
            if (counter == 3)
            {
                isClawFree = false;
                break;
            }
        }


        if (isClawFree)
            cout << "1\n";
        else
            cout << "0\n";


        for (int j = 0; j < matrixSize; j++)
            delete[] matrix[j];
    
        delete[] matrix;
    }
}