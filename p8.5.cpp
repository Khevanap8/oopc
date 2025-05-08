#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void displayDirectory(const map<string, vector<string>>& directory)
{
    cout << "\n--- Project Directory Structure ---\n";
    for (const auto& folder : directory)
    {
        cout << "[" << folder.first << "]" << endl;
        for (const auto& file : folder.second)
        {
            cout << " - " << file << endl;
        }
    }
}

int main()
{
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\n--- Directory Management System ---\n";
        cout << "1. Add New Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory Structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string folder;
            cout << "Enter new folder name: ";
            getline(cin, folder);

            if (directory.find(folder) == directory.end())
            {
                directory[folder] = vector<string>();
                cout << "Folder '" << folder << "' created.\n";
            }
            else
            {
                cout << "Folder already exists.\n";
            }

        }
        else if (choice == 2)
        {
            string folder, file;
            cout << "Enter folder name: ";
            getline(cin, folder);

            if (directory.find(folder) != directory.end())
            {
                cout << "Enter file name to add: ";
                getline(cin, file);
                directory[folder].push_back(file);
                cout << "File '" << file << "' added to folder '" << folder << "'.\n";
            }
            else
            {
                cout << "Folder '" << folder << "' does not exist. Create it first.\n";
            }

        }
        else if (choice == 3)
        {
            displayDirectory(directory);
        }

    }

    while (choice != 4);

    cout << "Exiting Directory Manager.\n";
    return 0;
}
