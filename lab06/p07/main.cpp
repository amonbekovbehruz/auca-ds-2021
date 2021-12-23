#include <bits/stdc++.h>

using namespace std;

struct Student
{
    string mName;
    double mGpa;

    Student(string name, double gpa) : mName(name), mGpa(gpa){
    }
};


void p07()
{
    vector<Student> students = {
        {"C", 3.45},
        {"X", 3.45},
        {"Z", 2.45},
        {"K", 3.45},
        {"L", 1.45},
        {"M", 3.45},
        {"V", 2.30},
        {"D", 2.45},
        {"A", 4.00},
    };

    cout << "regular sort:" << endl;
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });
    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
    cout << "- - - -" << endl;
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa < s2.mGpa; });
    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "stable sort:" << endl;

    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mName < s2.mName; });
    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
    cout << "- - - -" << endl;
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mGpa < s2.mGpa; });
    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

int main()
{
    p07();
}