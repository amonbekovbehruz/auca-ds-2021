#include <bits/stdc++.h>

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string name, const double gpa)
    {
        this->mName = name;
        this->mGpa = gpa;
    }
};

void p08()
{
    vector<pair<string, double>> Students;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        Students.emplace_back(make_pair(name, gpa));
    }

    sort(begin(Students), end(Students));

    for (int i = 0; i < (int)Students.size(); i++)
    {
        cout << "Student: " << Students[i].first << " GPA: " << Students[i].second << endl;
    }
}

int main()
{
    p08();
}
