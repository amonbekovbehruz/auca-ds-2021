#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct GreaterThan
{
    int mData;
    GreaterThan(int data)
        : mData(data)
    {
    }
    bool operator()(int value) const
    {
        return value > mData;
    }
};

struct isEven
{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};

struct CmpByGpa
{
    bool operator()(const Student &s1, const Student &s2) const
    {
        return s1.mGpa < s2.mGpa;
    }
};

void p0101()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = find(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "20 is not found." << endl;
    }

    auto itB = find(begin(v), end(v), -1);
    if (itB != end(v))
    {
        cout << "position of 20 is " << itB - begin(v) << endl;
    }
    else
    {
        cout << "20 is not found." << endl;
    }
}

void p0102()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto itA = auFind(begin(a), end(a), 20);
    if (itA != end(a))
    {
        cout << "position of 20 is " << itA - begin(a) << endl;
    }
    else
    {
        cout << "20 is not found.";
    }

    auto itV = auFind(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "position of -1 is " << itV - begin(v) << endl;
    }
    else
    {
        cout << "-1 is not found." << endl;
    }
}

void p0201()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    isEven functor;
    // auto it = auFindIf(begin(v), end(v), functor);
    auto it = auFindIf(begin(v), end(v), isEven());

    if (it != end(v))
    {
        cout << "position of 20 is " << it - begin(v) << endl;
        cout << "the number is " << *it << endl;
    }
    else
    {
        cout << "even number are not found. " << endl;
    }
    // labda expression
    auto it2 = auFindIf(begin(v), end(v), [](int value)
                        { return value % 2 == 0; });
    if (it2 != end(v))
    {

        cout << "position of 20 is " << it2 - begin(v) << endl;
        cout << "the number is " << *it2 << endl;
    }
    else
    {
        cout << "even number are not found. " << endl;
    }
}

void p0202()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    // auto it = find_if(begin(v), end(v), isEven());

    // if (it != end(v))
    // {
    //     cout << "position of 20 is " << it - begin(v) << endl;
    //     cout << "the number is " << *it << endl;
    // }
    // else
    // {
    //     cout << "even number are not found. " << endl;
    // }
    // labda expression
    auto it = find_if(begin(v), end(v), [](int value)
                      { return value % 2 == 0; });
    if (it != end(v))
    {

        cout << "position of 20 is " << it - begin(v) << endl;
        cout << "the number is " << *it << endl;
    }
    else
    {
        cout << "even number are not found. " << endl;
    }
}

void p0201()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    isEven functor;

    auto itV = find(begin(v), end(v), functor);

    if (itA != end(v))
    {
        cout << "position of -1 is: " << itV - begin(V) << endl;
    }
    else
    {
        cout << "-1 is not found" << endl;
    }
}

int main()
{
    p0101();
}