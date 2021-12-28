#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct specialString
{
    string s;
    int msr;
};

int measure(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] > str[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int number;
    cin >> number;

    while (number--)
    {
        int length;
        int elements;
        cin >> length >> elements;
        bool isEmpty = false;

        vector<specialString> vec(elements);

        for (int i = 0; i < elements; i++)
        {
            cin >> vec[i].s;
            vec[i].msr = measure(vec[i].s);
        }

        stable_sort(vec.begin(), vec.end(), [](specialString x, specialString y) {
            return x.msr < y.msr;
        });

        if (isEmpty)
        {
            cout << endl;
        }
        isEmpty = true;

        for (int i = 0; i < elements; i++)
        {
            cout << vec[i].s << endl;
        }
    }
}


