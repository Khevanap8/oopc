#include <iostream>
#include <cmath>
using namespace std;
const int MAX_TEMPS = 100;
class Fahrenheit;
class Celsius
{
private:
    double temp;
public:
    Celsius(double t = 0.0) : temp(t) {}
    operator Fahrenheit();

    bool operator==(const Celsius& other) const
    {
        return abs(temp - other.temp) < 0.0001;
    }
    double getTemp() const { return temp; }
    void display() const
    {
        cout << temp << " °C";
    }
};
class Fahrenheit
{
private:
    double temp;
public:
    Fahrenheit(double t = 32.0) : temp(t) {}

    operator Celsius()
    {
        return Celsius((temp - 32) * 5.0 / 9.0);
    }

    bool operator==(const Fahrenheit& other) const
    {
        return abs(temp - other.temp) < 0.0001;
    }
    double getTemp() const { return temp; }
    void display() const
    {
        cout << temp << " °F";
    }
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit((temp * 9.0 / 5.0) + 32);
}

void processConversions()
{
    Celsius celsiusTemps[MAX_TEMPS];
    Fahrenheit fahrenheitTemps[MAX_TEMPS];
    int count = 0;

    int n;
    cout << "Enter number of Celsius temperatures to convert (max " << MAX_TEMPS << "): ";
    cin >> n;
    if (n <= 0 || n > MAX_TEMPS)
    {
        cout << "Invalid count.\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        double temp;
        cout << "Enter temperature #" << (i + 1) << " in Celsius: ";
        cin >> temp;
        celsiusTemps[i] = Celsius(temp);
        fahrenheitTemps[i] = static_cast<Fahrenheit>(celsiusTemps[i]);
        ++count;
    }

    cout << "\nConverted Temperatures (FIFO Order):\n";
    for (int i = 0; i < count; ++i)
    {
        celsiusTemps[i].display();
        cout << " = ";
        fahrenheitTemps[i].display();
        cout << endl;
    }

    if (count >= 2)
    {
        cout << "\nComparing Temperature #1 and #2:\n";
        if (celsiusTemps[0] == static_cast<Celsius>(fahrenheitTemps[1]))
        {
            cout << "They are equal.\n";
        }
        else
        {
            cout << "They are NOT equal.\n";
        }
    }
}

int main()
{
    processConversions();
    return 0;
}
