#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of transaction IDs: ";
    cin >> n;

    set<int> transactionIDs;
    cout << "Enter " << n << " transaction IDs (integers):\n";
    for (int i = 0; i < n; ++i)
    {
        int id;
        cin >> id;
        transactionIDs.insert(id);
    }

    cout << "\n--- Unique Transaction IDs ---\n";
    for (auto id : transactionIDs)
    {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
