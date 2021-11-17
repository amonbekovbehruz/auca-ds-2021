#include <bits/stdc++.h>

using namespace std;

int main()
{
    int counter = 0;
    for (char c; cin.get(c);)
    {
        if (c == '\"')
        {
            counter++;
            if (counter % 2 != 0)
            {
                cout.put('`');
                cout.put('`');
            }
            else
            {
                cout.put('\'');
                cout.put('\'');
            }
        }
        else
        {
            cout.put(c);
        }
    }
}