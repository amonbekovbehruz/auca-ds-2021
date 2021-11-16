#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    while (true)
    {
        int r;
        cin >> r;
        if (r == 0)
            break;
        int f;
        cin >> f;

        vector<int> n(r);
        vector<int> m(f);

        for (int i = 0; i < (int)n.size(); i++)
        {
            int e;
            cin >> e;
            n[i] = e;
        }
        for (int i = 0; i < (int)m.size(); i++)
        {
            int e;
            cin >> e;
            m[i] = e;
        }

        vector<double> d;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < f; j++)
            {
                double num = (double)n[i] / ((double)m[j]);
                d.push_back(num);
            }
        }

        sort(begin(d), end(d));

        double mx = 0;

        for (int i = 1; i < (int)d.size(); i++)
        {
            double val = d[i] / d[i - 1];
            mx = max(val, mx);
        }
        printf("%.2lf\n", mx);
    }
}