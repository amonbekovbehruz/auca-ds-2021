#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, c;

    while (cin >> l >> c)
    {
        if (l == 0 && c == 0)
        {
            break;
        }
        vector<string> v;
        v.resize(c, "");

        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                char text;
                cin >> text;
                v[j].push_back(text);
            }
        }

        stable_sort(begin(v), end(v), [&](string a, string b)
                    {
            for (auto &c : a)
            {
               c = tolower(c);
            }
            for (auto &c : b)
            {
                c = tolower(c);
            }
            return a < b; });

        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cout << v[j][i];
            }
            cout << "\n";
        }
    }
}
