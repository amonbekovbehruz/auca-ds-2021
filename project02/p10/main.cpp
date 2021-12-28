#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCases;

    cin >> testCases;
    vector<pair<int, string>> cups;
    cups.resize(testCases);

    for (int i = 0; i < testCases; ++i)
    {
        string radius;
        string diameter;
        cin >> radius >> diameter;

        int a;
        if (isdigit(radius[0]))
        {
            a = stoi(radius);
            a /= 2;
            cups.push_back(make_pair(a, diameter));
        }
        else
        {
            a = stoi(diameter);
            cups.push_back(make_pair(a, radius));
        }
    }

    sort(begin(cups), end(cups), [](const pair<int, string> &l, const pair<int, string> &r)
         { return l.first > r.first; });

    for (int i = testCases - 1; i >= 0; i--)
    {
        cout << cups[i].second << endl;
    }
}