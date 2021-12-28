#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    vector<string> names;
    string name;
    int t;

    while (cin >> t)
    {
        cin.ignore();

        for (int i = 0; i < t; i++)
        {
            cin >> name;
            names.push_back(name);
        }
        stable_sort(begin(names), end(names), [](string first, string second)
                    {
            if(first[0] != second[0])
            {
                return first[0] < second [0]; 
            }
            else 
            {
               return first[1] < second [1];  
            } });

        for (auto &i : names)
        {
            cout << i << endl;
        }
        names.clear();
    }
}
