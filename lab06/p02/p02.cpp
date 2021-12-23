#include <bits/stdc++.h>
#include "../../au/algol.hpp"

using namespace std;

struct isEven
{
    bool operator()(int value)
    {
        return value % 2 == 0;
    }
};

void p02()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    isEven functor;
    auto itA = find_if(begin(a), end(a), functor);
    if (itA != end(a))
    {
        cout << "index of first even number is " << (itA - begin(a)) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    auto itB = find_if(begin(a), end(a), [](int value)
                       { return value % 2 == 0; });

    if (itB == end(a))
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "index of first even number is " << (itB - begin(a)) << endl;
    }

    auto itC = auFindIf(begin(a), end(a), [](int value)
                        { return value % 2 == 0; });

    if (itC == end(a))
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "index of first even number is " << (itC - begin(a)) << endl;
    }
}

int main()
{
    p02();
}