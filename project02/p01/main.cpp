#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

struct Job
{
    string mDs;
    int mCost;
    Job(string ds, int cost)
        : mDs(ds), mCost(cost)
    {
    }
};
int main()
{

    iostream::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    vector<Job> v;
    while (m--)
    {
        string ds;
        int cost;

        cin >> ds >> cost;
        v.push_back(Job(ds, cost));
    }

    sort(begin(v), end(v), [](const Job &a, const Job &b)
         { return a.mDs < b.mDs; });
    while (n--)
    {
        string str;
        int ans = 0;

        while (cin >> str && str != ".")
        {
            auto it = lower_bound(begin(v), end(v), Job(str, 0), [](const Job &a, const Job &b)
                                  { return a.mDs < b.mDs; });

            for (auto e : v)
            {
                if (str == e.mDs)
                {
                    ans += e.mCost;
                }
            }
        }
        cout << ans << "\n";
    }
}
