#include <iostream>
#include "../../au/algol.hpp"
#include "VecInt.hpp"
#include "stdexcept"

using namespace std;

void printVector(const VecInt &v)
{
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << "\n";

    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void p01()
{

    cout << "the size of array: ";
    int n;

    cin >> n;

    VecInt v(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    auReverse(v.begin(), v.end());

    printVector(v);
}

void p02()
{

    // vector<int> v;
    VecInt v;

    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    printVector(v);
    auReverse(v.begin(), v.end());
    // printArray(v.data, v.data + v.sz); // functions(), begin() inlined
    v[0] = 100;
    printVector(v);
}

int main()
{
    p02();
}