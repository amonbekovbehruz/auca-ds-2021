#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    for(int i = 0; i < test_cases; i++) {
        long num_of_soldiers;
        cin >> num_of_soldiers;
        
        long rows = (long)(sqrt(8*num_of_soldiers+1) - 1)/2;

        cout << rows << '\n';
    }
}