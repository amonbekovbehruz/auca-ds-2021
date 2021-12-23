#include <bits/stdc++.h>

using namespace std;

void p01()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    auto itA = find(begin(a), end(a), 20);
    if (itA == end(a))
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "index of 20 is " << (itA - begin(a)) << endl;
    }
}

int main()
{
    p01();
}