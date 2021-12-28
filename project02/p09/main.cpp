#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; ++j)
    {
        int n;
        cin >> n;
        vector<int> r, b;

        for (int i = 0; i < n; ++i)
        {

            int num;
            char s;
            cin >> num >> s;
            num--;

            if (s == 'B')
            {
                b.push_back(num);
            }
            else
            {
                r.push_back(num);
            }
        }

        sort(r.rbegin(), r.rend());
        sort(b.rbegin(), b.rend());
        int ans = 0;

        int a = accumulate(begin(r), begin(r) + min(sz(r), sz(b)), 0);
        int c = accumulate(begin(b), begin(b) + min(sz(r), sz(b)), 0);

        ans = a + c;
        cout << "Case #" << j << ": ";
        cout << ans << endl;
    }
}
