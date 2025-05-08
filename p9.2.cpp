#include <iostream>
#include <cmath>
#include <exception>

using namespace std;

class NegativeNumberException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Cannot calculate square root of a negative number.";
    }
};

double calculateSquareRoot(double number)
{
    if (number < 0)
    {
        throw NegativeNumberException();
    }
    return sqrt(number);
}

int main()
{
    double input;
    cout << "Enter a number to calculate its square root: ";
    cin >> input;

    try
    {
        double result = calculateSquareRoot(input);
        cout << "Square root of " << input << " is " << result << endl;
    }
    catch (const NegativeNumberException& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
