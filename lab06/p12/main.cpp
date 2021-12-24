#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
#include <tuple>
#include "../../au/algol.hpp"

using namespace std;

void p12()
{
    vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 25, 25, 25, 40};

    for (int x; cin >> x;)
    {
        auto p = equal_range(begin(v), end(v), x);
        cout << "occurrences numbers: " << x << " is " << p.second - p.first << endl;
    }
}
int main()
{
    p12();
}