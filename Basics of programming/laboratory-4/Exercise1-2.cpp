﻿#include <iostream>
using namespace std;

int main() {
	int i;
	int arr[10];
	for (i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (i = 0; i < 10; i+=2) {
		cout << arr[i];
	}
	return 0;
}