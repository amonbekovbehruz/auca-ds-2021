#include <bits/stdc++.h>

using namespace std;

void p09()
{
    using Employee = tuple<string, int, double>;

    vector<tuple<string, int, double>> v;
    string name;
    int age;
    double salary;

    while (cin >> name >> age >> salary)
    {
        v.emplace_back(name, age, salary);
    }

    sort(begin(v), end(v), [](const Employee &e1, const Employee &e2)
         { return get<1>(e1) < get<1>(e2); });

    for (const auto &e : v)
    {
        cout << get<0>(e) << ", " << get<1>(e) << ", " << get<2>(e) << endl;
    }
}

int main()
{
    p09();
}