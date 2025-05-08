#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string currencySymbol = "$";

ostream& currency(ostream& os)
{
    os << currencySymbol;
    return os;
}
int main()
{
    const int numStudents = 5;
    string names[numStudents] = {"Alice", "Bob", "Catherine", "David", "Emily"};
    float marks[numStudents] = {89.5, 76.0, 93.25, 65.75, 82.0};
    double fees[numStudents] = {1500.00, 1600.50, 1450.75, 1700.00, 1550.25};

    cout << fixed << setprecision(2);
    cout << setfill(' ');
    cout << left << setw(15) << "Name"<< right << setw(10) << "Marks"<< right << setw(15) << "Tuition Fee" << endl;
    cout << string(40, '-') << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        cout << left << setw(15) << names[i]<< right << setw(10) << marks[i]<< right << setw(5) << currency << setw(10) << fees[i] << endl;
    }
    return 0;
}
