#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    getline(cin, line);

    int test;
    cin >> test;
    cin >> ws;
    for (int i = 0; i < test; i++)
    {
        getline(cin, line);
        istringstream sinp(line);

        int M = 0;
        int F = 0;
        int count = 0;

        for (string l; sinp >> l;)
        {
            M += l[0] == 'M';
            M += l[1] == 'M';

            F += l[0] == 'F';
            F += l[1] == 'F';
            count++;
        }

        cout << (count > 1 && F == M ? "LOOP\n" : "NO LOOP\n");
    }
}