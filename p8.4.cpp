#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int score;
};

bool compareByScoreDesc(const Student& a, const Student& b)
{
    return a.score > b.score;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students;
    students.reserve(n);

    cout << "Enter student names and scores:\n";
    for (int i = 0; i < n; ++i)
    {
        Student s;
        cout << "Student " << i + 1 << " name: ";
        cin >> ws;
        getline(cin, s.name);
        cout << "Score: ";
        cin >> s.score;
        students.push_back(s);
    }

    sort(students.begin(), students.end(), compareByScoreDesc);


    cout << "\n--- Student Rankings ---\n";
    cout << left << setw(6) << "Rank" << setw(20) << "Name" << setw(10) << "Score" << "\n";
    cout << string(40, '-') << "\n";

    int rank = 1;
    for (const auto& student : students)
    {
        cout << left << setw(6) << rank++ << setw(20) << student.name << setw(10) << student.score << "\n";
    }

    return 0;
}
