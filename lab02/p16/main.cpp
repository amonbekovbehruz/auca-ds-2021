#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you",
                           "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you!"};

    
    int n;
    cin >> n;
    vector<string> names;
    
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    int i = 0;
    int j = 0;
    bool isComplete = false;
    while (true)
    {
        cout << names[i] << ": " << song[j] << "\n";
        if (i == n - 1)
        {
            isComplete = true;
        }

        if (j == sz(song) - 1 && isComplete)
        {
            break;
        }

        ++i;
        ++j;

        if (i == n)
        {
            i = 0;
        }
        if (j == sz(song))
        {
            j = 0;
        }
    }
}