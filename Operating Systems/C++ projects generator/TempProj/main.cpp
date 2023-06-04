#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
    int a = 12;
    int b = 10;
    int c;
    int d = 7;
    c = 48;

    cout << a + b + c + d << endl;
    Calculator calculator;
    cout << calculator.sum(10, 20) << endl;

    return 0;
}