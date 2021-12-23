#include <bits/stdc++.h>
#include "../../au/algol.hpp"

using namespace std;

void p1001()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    auto itA = binary_search(begin(v), end(v), 0);
    auto itB = binary_search(begin(v), end(v), 4);
    auto itC = binary_search(begin(v), end(v), 5);
    auto itD = binary_search(begin(v), end(v), 10);
    auto itE = binary_search(begin(v), end(v), 12);
    auto itF = binary_search(begin(v), end(v), 20);
    auto itG = binary_search(begin(v), end(v), 20);
    auto itH = binary_search(begin(v), end(v), 40);

    if (itA != end(v))
    {
        cout << "index is " << itA - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itB != end(v))
    {
        cout << "index is " << itB - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itC != end(v))
    {
        cout << "index is " << itC - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itD != end(v))
    {
        cout << "index is " << itD - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itE != end(v))
    {
        cout << "index is " << itE - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itF != end(v))
    {
        cout << "index is " << itF - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itG != end(v))
    {
        cout << "index is " << itG - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    if (itH != end(v))
    {
        cout << "index is " << itH - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p1002()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    auto itA = auBinarySearch(begin(v), end(v), 5);
    if (itA != end(v))
    {
        cout << "index is " << itA - begin(v) << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

int main()
{
    // p1001();
}