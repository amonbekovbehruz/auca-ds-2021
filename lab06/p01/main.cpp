#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
#include <tuple>
#include "../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

struct isEven
{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};

struct CmpByGpa
{
    bool operator()(const Student &s1, const Student &s2) const
    {
        return s1.mGpa < s2.mGpa;
    }
};


void p0101()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = find(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "20 is not found." << endl;
    }

    auto itB = find(begin(v), end(v), -1);
    if (itB != end(v))
    {
        cout << "position of 20 is " << itB - begin(v) << endl;
    }
    else
    {
        cout << "20 is not found." << endl;
    }
}

void p0102()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = auFind(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "20 is not found.";
    }

    auto itV = auFind(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "position of -1 is " << itV - begin(v) << endl;
    }
    else
    {
        cout << "-1 is not found." << endl;
    }
}

void p0201()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    isEven functor;
    // auto it = auFindIf(begin(v), end(v), functor);
    auto it = auFindIf(begin(v), end(v), isEven());

    if (it != end(v))
    {
        cout << "position of 20 is " << it - begin(v) << endl;
        cout << "the number is " << *it << endl;
    }
    else
    {
        cout << "even number are not found. " << endl;
    }
    // labda expression
    auto it2 = auFindIf(begin(v), end(v), [](int value)
                        { return value % 2 == 0; });
    if (it2 != end(v))
    {

        cout << "position of 20 is " << it2 - begin(v) << endl;
        cout << "the number is " << *it2 << endl;
    }
    else
    {
        cout << "even number are not found. " << endl;
    }
}

void p0202()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    // auto it = find_if(begin(v), end(v), isEven());

    // if (it != end(v))
    // {
    //     cout << "position of 20 is " << it - begin(v) << endl;
    //     cout << "the number is " << *it << endl;
    // }
    // else
    // {
    //     cout << "even number are not found. " << endl;
    // }
    // labda expression
    auto it = find_if(begin(v), end(v), [](int value)
                      { return value % 2 == 0; });
    if (it != end(v))
    {

        cout << "position of 20 is " << it - begin(v) << endl;
        cout << "the number is " << *it << endl;
    }
    else
    {
        cout << "even number are not found. " << endl;
    }
}

struct GreaterThan
{
    int mData;
    GreaterThan(int data)
        : mData(data)
    {
    }
    bool operator()(int value) const
    {
        return value > mData;
    }
};

void p03()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    cout << "x = ";
    int x;
    cin >> x;

    auto it = find_if(begin(v), end(v), GreaterThan(x));
    if (it != end(v))
    {
        cout << "the index: " << it - begin(v) << endl;
        cout << "the value: " << *it << endl;
    }
    else
    {
        cout << "value greater than " << x << " not found" << endl;
    }

    auto it2 = find_if(begin(v), end(v), [x](int value)
                       { return value > x; });
    if (it2 != end(v))
    {
        cout << "the index: " << it2 - begin(v) << endl;
        cout << "the value: " << *it2 << endl;
    }
    else
    {
        cout << "value greater than " << x << " not found" << endl;
    }
}

void p06()
{
    vector<Student> stud;

    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        // stud.push_back(Student(name, gpa));
        stud.emplace_back(name, gpa);
    }

    sort(begin(stud), end(stud), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &s : stud)
    {
        cout << "{ " << s.mName << ", " << s.mGpa << "}" << endl;
    }

    sort(begin(stud), end(stud), CmpByGpa());

    for (const auto &s : stud)
    {
        cout << "{ " << s.mName << ", " << s.mGpa << "}" << endl;
    }
}

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

void p09()
{
    using Employee = tuple<string, int, double>;

    vector<Employee> employess;

    string name;
    int age;
    double salary;
    while (cin >> name >> age >> salary)
    {
        employess.emplace_back(name, age, salary);
    }
    sort(begin(employess), end(employess), [](const Employee &e1, const Employee &e2)
         { return get<1>(e1) < get<1>(e2); });

    for (const auto &e : employess)
    {
        cout << get<0>(e) << ", " << get<1>(e) << get<2>(e) << endl;
    }
}

void p1001()
{
    vector<int> v = {1, 4, 5, 10, 12, 20, 25, 40};
    for (int x; cin >> x;)
    {
        cout << (binary_search(begin(v), end(v), x) ? "yes" : "no") << endl;
    }
}

void p11()
{
    vector<int> v = {1, 4, 5, 10, 12, 20, 25, 40};
    for (int x; cin >> x;)
    {
        auto it = lower_bound(begin(v), end(v), x);
        if (it == end(v))
        {
            cout << "no element is equal or greater than " << x << endl;
        }
        else if (*it == x)
        {
            cout << "index of " << x << " is " << it - begin(v) << endl;
        }
        else
        {
            cout << "index of the first element greater than " << x << " is " << it - begin(v) << endl;
        }
    }
}
void p12()
{
    vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 25, 25, 25, 40};
    for (int x; cin >> x;)
    {
        auto p = equal_range(begin(v), end(v), x);
        cout << "number of ecirrence of " << x << " is " << p.second - p.first << endl;
    }
}

int main()
{
    // p0101();
    // p0102();
    // p0201();
    // p0202();
    // p06();
    // p03();
    // p07();
    // p08();
    // p1001();
    // p11();
    // p12();
}