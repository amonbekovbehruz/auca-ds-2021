#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    for(int i = 0; i < test_cases; i++) {
        double n;
        cin >> n;

        n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
        
        n = abs(fmod(n, 100));
        
        cout << (int)n/10 << '\n';
    }
}