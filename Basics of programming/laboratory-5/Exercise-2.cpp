#include <iostream>
using namespace std;

//Zadanie 2. Zaimplementuj i przetestuj funkcjê, która wypisuje podany ³añcuch znaków
//podan¹ liczbê razy.Funkcja nie powinna zwracaæ ¿adnej wartoœci. Lista parametrów
//powinna zawieraæ dwa elementy oddzielone przecinkiem.

void repeat_string(char text[], int how_many_times)
{
	for (int i = 0; i < how_many_times; i++)
	{
		cout << text;
	}
}

int main()
{
	char t[] = "SIMPLE_TEXT";
	repeat_string(t, 5);
	
	return 0;
}
