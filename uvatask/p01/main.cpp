#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        cin >> k;

        vector<string> names;
        for (string line; getline(cin, line);)
        {
            names.push_back(line);
        }

        int ans = 0;
        sort(names.begin(), names.end());
        auto it = unique(names.begin(), names.end());

        ans += (it == names.end());

        for (auto e : names)
        {
            cout << e << endl;
        }
    }
}