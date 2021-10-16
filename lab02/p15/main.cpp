#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCases;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i) {
        int max = 0;
        vector<string> s(10);
        vector<int> v(10);
        
        for (int j = 0; j < sz(s); ++j) {
            cin >> s[j];
            cin >> v[j];
            if (v[j] > max) {
                max = v[j];
            }
        }

        auto posMax = max_element(begin(v), end(v));

        cout << "Case " << i << ":\n";

        for (int j = 0; j < sz(s); ++j) {
            if (v[j] == *posMax) {
                cout << s[j] << " " << "\n";
            }
        }
    }
}