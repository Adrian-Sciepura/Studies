#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
private:
    static constexpr double PI = 3.14f;

public:
    Calculator();
    ~Calculator();

    float sum(float a, float b);
};

#endif