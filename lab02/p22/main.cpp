#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> numbers(n);
        int ans = 0;
        for (auto &e : numbers)
        {
            cin >> e;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (numbers[j] <= numbers[i])
                    ans++;
            }
        }
        cout << ans << "\n";
    }
}
