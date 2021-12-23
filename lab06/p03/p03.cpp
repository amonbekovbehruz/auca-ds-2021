#include <vector>
#include <bits/stdc++.h>
#include "../../au/algol.hpp"

using namespace std;

struct GreaterThan
{
    int mData;
    GreaterThan(int data)
        : mData(data)
    {
    }

    bool operator()(int number) const
    {
        return number > mData;
    }
};

void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    int x;
    cin >> x;
    GreaterThan functor(x);

    auto it = find_if(begin(a), end(a), functor);

    cout << "index of first element greater than " << x << " is " << it - begin(a) << endl;

    auto itA = find_if(begin(a), end(a), [x](int value)
                       { return value > x; });

    cout << "index of first element greater than " << x << " is " << itA - begin(a) << endl;
}

int main()
{
    p03();
}