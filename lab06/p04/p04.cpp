#include <bits/stdc++.h>
#include "../../au/algol.hpp"

using namespace std;

void p04()
{
    // part 2
    vector<int> v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }

    auto it = min_element(begin(v), end(v));
    if (it != end(v))
    {
        cout << "Index of min element: " << it - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    auto it2 = auMinElement(begin(v), end(v));
    if (it2 != end(v))
    {
        cout << "Index of min element: " << it2 - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

int main()
{
    p04();
}
