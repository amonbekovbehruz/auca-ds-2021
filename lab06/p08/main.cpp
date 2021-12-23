#include <bits/stdc++.h>

using namespace std;

struct Student
{
    string mName;
    double mGpa;

    Student(string name, double gpa) : mName(name), mGpa(gpa)
    {
    }
};

void p08()
{
    vector<pair<string, double>> students;

    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }
    sort(begin(students), end(students));

    for (const auto &s : students)
    {
        cout << s.first << ", " << s.second << endl;
    }
}

int main()
{
    p08();
}