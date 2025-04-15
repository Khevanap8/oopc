#include <iostream>
using namespace std;

int countDigits(int number)
{
    int digitCount = 0;
    if (number == 0) return 1;
    while (number != 0)
    {
        digitCount++;
        number /= 10;
    }
    return digitCount;
}

long long repeatDigits(int num, int times)
{
    long long combined = num;
    int digits = countDigits(num);

    for (int i = 1; i < times; i++)
    {
        long long temp = num;
        for (int j = 0; j < digits; j++)
        {
            combined *= 10;
        }
        combined += temp;
    }
    return combined;
}

int calculateSuperDigit(long long value)
{
    if (value < 10)
        return value;

    long long total = 0;
    while (value > 0)
    {
        total += value % 10;
        value /= 10;
    }
    return calculateSuperDigit(total);
}

int main()
{
    int inputNumber, repeatCount;
    cout << "Enter number: ";
    cin >> inputNumber;
    cout << "Enter repeat count: ";
    cin >> repeatCount;

    long long fullValue = repeatDigits(inputNumber, repeatCount);
    cout << "Super Digit: " << calculateSuperDigit(fullValue) << endl;

    return 0;
}
