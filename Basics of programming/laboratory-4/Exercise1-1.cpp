#include <iostream>
using namespace std;

int main() {
	int i;
	int arr[10];
	for (i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < 10; i++) {
		cout << arr[(sizeof(arr) / sizeof(arr[0]) - i - 1)];
	}
	return 0;
}