#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

string sanitizeWord(const string& word)
{
    string clean;
    for (char ch : word)
    {
        if (isalnum(ch))
        {
            clean += tolower(ch);
        }
    }
    return clean;
}

int main()
{
    string text;
    cout << "Enter a sentence or paragraph:\n";
    getline(cin, text);

    map<string, int> wordFrequency;
    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        string cleanWord = sanitizeWord(word);
        if (!cleanWord.empty())
        {
            ++wordFrequency[cleanWord];
        }
    }

    cout << "\n--- Word Frequency Distribution ---\n";
    for (auto it = wordFrequency.begin(); it != wordFrequency.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
