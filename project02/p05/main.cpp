#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct ASCII
{
    int ascii;
    int value;

    ASCII(char aAscii, int aValue)
        : ascii(aAscii), value(aValue)
    {
    }
};

int main()
{
    int tests;

    for (string str; getline(cin, str);)
    {
        if (tests != 0)
        {
            cout << endl;
        }
        tests++;

        vector<ASCII> vec;
        vector<int> counter(100, 0);

        for (auto a : str)
        {
            counter[a]++;
        }

        for (int i = 0; i < counter.size(); i++)
        {
            if (counter[i] != 0)
            {
                vec.push_back(ASCII(i, counter[i]));
            }
        }

        sort(vec.begin(), vec.end(), [](ASCII a, ASCII b)
             {
            if (a.value == b.value)
            {
                return a.ascii > b.ascii;
            }
            return a.value < b.value; });

        for (auto i : vec)
        {
            cout << i.ascii << " " << i.value << endl;
        }
    }
}