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
        for (auto &e : numbers)
        {
            cin >> e;
        }

        sort(begin(numbers), end(numbers));

        int mid = numbers[n / 2];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += abs(numbers[i] - mid);
        }
        cout << ans << "\n";
    }
}