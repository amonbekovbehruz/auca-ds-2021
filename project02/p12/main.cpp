#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void calco(string pos, vector<pair<string, string>> &v);

int main()
{
    iostream::sync_with_stdio(false);
    vector<pair<string, string>> v;
    string pos;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            getline(cin, pos);
            calco(pos, v);
        }

        stable_sort(v.begin(), v.end());
        for (auto &i : v)
        {
            cout << get<1>(i) << endl;
        }
        for (int i = 0; i < 30; i++)
        {
            cout << '=';
        }
        cout << '\n';

        v.clear(); // for next ones
    }
}

void calco(string pos, vector<pair<string, string>> &v)
{
    stack<string> container;
    string name, classes;

    string classtype = "";
    int difference = 0;

    istringstream ss(pos);
    getline(ss, name, ':');

    ss.ignore(); // ignoring the space

    while (getline(ss, classes, '-'))
    {
        if (classes == "upper" || classes == "upper class")
        {
            classes = '1';
        }

        else if (classes == "middle" || classes == "middle class")
        {
            classes = '2';
        }
        else if (classes == "middle" || classes == "middle class")
        {
            classes = '3';
        }
        container.push(classes);
    }
    if (container.size() < 10)
    {
        difference = 10 - container.size();
    }
    while (!container.empty())
    {
        classtype = classtype + container.top();
        container.pop(); // remove the element in the top
    }
    for(int i = 0;  i < difference; ++i)
    {
        classtype = classtype + '2';
    }
    v.push_back(pair<string, string>(classtype, name));

}
