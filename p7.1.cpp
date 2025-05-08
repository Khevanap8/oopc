#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s[50];
    string u[50];
    int c[50] = {0};
    int n = 0;
    int uniqCount = 0;

    string input;
    cout << "Enter a paragraph:\n";
    getline(cin, input);


    int i = 0, start = 0,f=0;
    while (i <= input.length())
        {
            if (input[i] == ' ' || i == input.length())
            {
                s[n] = input.substr(start, i - start);
                for (int j = 0; j < s[n].length(); j++)
                    {
                        if (s[n][j] >= 'A' && s[n][j] <= 'Z')
                        {
                            s[n][j] = s[n][j] + 32;
                        }
                    }
                for (int j = 0; j < uniqCount; j++)
                    {
                        if (u[j] == s[n])
                            {
                                c[j]++;
                                f = 1;
                                break;
                            }
                    }

                if (f == 0)
                    {
                        u[uniqCount] = s[n];
                        c[uniqCount] = 1;
                        uniqCount++;
                    }

                n++;
                start = i + 1;
                if (n >= 50) break;
            }
            i++;
        }
        cout << "\nWord Frequency:\n";
        for (int i = 0; i < uniqCount; i++)
        {
            string* k = &u[i];
            cout << *k << ": " << c[i] << endl;
        }
        return 0;
}

