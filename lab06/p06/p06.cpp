#include <bits/stdc++.h>
#include <string>

using namespace std;

struct Student
{
    string mName;
    double mGpa;

    Student(string name, double gpa) : mName(name), mGpa(gpa)
    {
    }
};

struct cmpByGpa
{
    bool operator()(Student &s1, Student &s2)
    {
        return s1.mGpa < s2.mGpa;
    }
};

struct cmpByName
{
    bool operator()(Student &s1, Student &s2)
    {
        return s1.mName < s2.mName;
    }
};

void p06()
{
    string name;
    double gpa;
    vector<Student> student;

    while (cin >> name >> gpa)
    {
        student.emplace_back(name, gpa);
    }

    auto itA = min_element(begin(student), end(student), [](Student s1, Student s2)
                           { return s1.mGpa < s2.mGpa; });

    if (itA != end(student))
    {
        cout << "Index of the minimum student with GPA is " << itA - begin(student) << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    auto it2 = min_element(begin(student), end(student), [](Student s1, Student s2)
                           { return s1.mName < s2.mName; });

    if (it2 != end(student))
    {
        cout << "Index of the student with smallest name is " << it2 - begin(student) << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main()
{
    p06();
}