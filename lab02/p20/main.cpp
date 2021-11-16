#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    bool isFirst = true;
    for (int nPeople; cin >> nPeople;)
    {
        vector<string> names(nPeople);
        for (auto &n : names)
        {
            cin >> n;
        }

        vector<int> lostMoney(nPeople);
        vector<int> receiveMoney(nPeople);

        for (int i = 0; i < nPeople; ++i)
        {
            string name;
            cin >> name;

            int sum;
            cin >> sum;

            int nRecievers;
            cin >> nRecievers;

            int index = find(begin(names), end(names), name) - begin(names);

            for (int j = 0; j < nRecievers; ++j)
            {
                string friendName;
                cin >> friendName;
                int indexFriend = find(begin(names), end(names), friendName) - begin(names);
                receiveMoney[indexFriend] += sum / nRecievers;
            }

            if (nRecievers != 0)
            {
                lostMoney[index] = sum - sum % nRecievers;
            }
        }
    }
}