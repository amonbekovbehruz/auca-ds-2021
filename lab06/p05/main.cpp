#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
#include <tuple>
#include "../../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(string name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};
struct CmpByGpa
{
    bool operator()(const Student &a, const Student &b) const
    {
        return a.mGpa < b.mGpa;
    }
};

void p1()
{

    vector<Student> v;
    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        v.emplace_back(name, gpa);
    }

    // min by GPA
    cout << "BY GPA" << endl;
    auto it = min_element(begin(v), end(v), CmpByGpa());

    if (it != end(v))
    {
        cout << "index : " << it - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    // min by NAME
    cout << "BY NAME" << endl;
    auto itA = min_element(begin(v), end(v), [](Student a, Student b)
                           { return a.mName < b.mName; });
    if (itA != end(v))
    {
        cout << "index : " << itA - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p2()
{
    vector<Student> v1;

    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        v1.emplace_back(name, gpa);
    }

    // min by GPA
    cout << "BY GPA" << endl;
    auto it = auMinElement(begin(v1), end(v1), [](Student a, Student b)
                           { return a.mGpa < b.mGpa; });
    if (it != end(v1))
    {
        cout << "index: " << it - begin(v1) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    // min by NAME
    cout << "BY NAME" << endl;
    auto itA = auMinElement(begin(v1), end(v1), [](Student a, Student b)
                            { return a.mName < b.mName; });
    if (itA != end(v1))
    {
        cout << "index: " << itA - begin(v1);
    }
    else
    {
        cout << "not found" << endl;
    }
}
int main()
{
    p1();
}