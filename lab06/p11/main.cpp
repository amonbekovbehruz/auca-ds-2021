
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
#include <tuple>
#include "../../au/algol.hpp"

using namespace std;

void p1()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};
    int x;
    while (cin >> x)
    {
        auto it = lower_bound(begin(v), end(v), x);

        if (it == end(v))
        {
            cout << "no elements equal or greater than " << x << endl;
        }
        else if (*it == x)
        {
            cout << "index of the first element equal to " << x << " is " << it - begin(v) << endl;
        }
        else
        {

            cout << "index of the first element greater than " << x << " is " << it - begin(v) << endl;
        }
    }
}

int main()
{
    p1();
}