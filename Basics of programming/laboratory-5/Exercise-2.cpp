#include <iostream>
using namespace std;

//Zadanie 2. Zaimplementuj i przetestuj funkcj�, kt�ra wypisuje podany �a�cuch znak�w
//podan� liczb� razy.Funkcja nie powinna zwraca� �adnej warto�ci. Lista parametr�w
//powinna zawiera� dwa elementy oddzielone przecinkiem.

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
