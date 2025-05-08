#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << "Enter two integers (numerator and denominator): ";
    int numerator, denominator;

   if (!(cin >> numerator >> denominator))
    {
        cerr << "Error: Invalid input. Please enter integers only." << endl;
        return 1;
    }

    try {
        if (denominator == 0)
            throw runtime_error("Error: Division by zero is not allowed.");

            double result = static_cast<double>(numerator) / denominator;
            cout << "Result: " << result << endl;

        }
        catch (const runtime_error& e)
        {
            cerr << e.what() << endl;
            return 1;
        }

    return 0;
}
