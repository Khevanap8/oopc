#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

bool isNumber(const string& str)
{
    istringstream iss(str);
    double num;
    return (iss >> num) && iss.eof();
}

void processFile(const string& filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        throw runtime_error("File not found or could not be opened.");
    }

    string line;
    int lineNumber = 1;
    vector<double> numbers;

    while (getline(file, line))
    {
        cout << "Reading line " << lineNumber << ": " << line << endl;
        if (!isNumber(line))
        {
            throw runtime_error("Corrupted data on line " + to_string(lineNumber) + ": Non-numeric value found.");
        }
        double value = stod(line);
        numbers.push_back(value);
        lineNumber++;
    }

    file.close();

    cout << "\n--- Processed Data ---\n";
    for (double num : numbers)
    {
        cout << num << " ";
    }
    cout << "\nTotal numbers read: " << numbers.size() << endl;
}

int main()
{
    string filePath;
    bool success = false;

    while (!success)
    {
        cout << "Enter the path to the input file: ";
        getline(cin, filePath);
        try
        {
            processFile(filePath);
            success = true;
        }
        catch (const exception& e)
        {
            cerr << "Exception: " << e.what() << endl;
            cout << "Please try again.\n\n";
        }
    }

    return 0;
}
