#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseWithIterators(vector<int>& sequence)
{
    auto front = sequence.begin();
    auto back = sequence.end() - 1;

    while (front < back)
    {
        iter_swap(front, back);
        ++front;
        --back;
    }
}

void display(const vector<int>& sequence)
{
    for (auto it = sequence.begin(); it != sequence.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> sequence;
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        sequence.push_back(val);
    }

    cout << "\nOriginal Sequence:\n";
    display(sequence);

    vector<int> reversed1 = sequence;
    reverse(reversed1.begin(), reversed1.end());
    cout << "\nReversed using std::reverse:\n";
    display(reversed1);

    vector<int> reversed2 = sequence;
    reverseWithIterators(reversed2);
    cout << "\nReversed using manual iterators:\n";
    display(reversed2);

    return 0;
}
