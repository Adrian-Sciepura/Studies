#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int numberOfGraphs;
	int size;
	

	cin >> numberOfGraphs;
	for (int i = 0; i < numberOfGraphs; i++)
	{
		bool isCycle = true;
		int numberOfIterations = 0;

		cin >> size;
		char** graph = new char*[size];
		for (int j = 0; j < size; j++)
		{
			graph[j] = new char[size];
			for (int k = 0; k < size; k++)
				cin >> graph[j][k];
		}


		for (int j = 0; j < size; j++)
		{
			int counter = 0;
			for (int k = 0; k < size; k++)
			{
				if (graph[j][k] == '1')
					counter++;
			}

			if (counter != 2)
			{
				isCycle = false;
				break;
			}
		}


		int currentRow = 0;
		for(int k = 0; k < size*size; k++)
		{
			for (int j = 0; j < size; j++)
			{
				if (graph[currentRow][j] == '1')
				{
					graph[currentRow][j] = '0';
					graph[j][currentRow] = '0';
					currentRow = j;
					numberOfIterations++;
				}
			}
			if (currentRow == 0)
				break;
		}

		if (numberOfIterations != size)
			isCycle = false;

		if (isCycle)
			cout << '1' << '\n';
		else
			cout << '0' << '\n';

		for (int j = 0; j < size; j++)
			delete[] graph[j];
		delete[] graph;
	}
}