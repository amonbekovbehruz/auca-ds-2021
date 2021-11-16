#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    bool isFirst = true;
    for (int numberOfPeople; cin >> numberOfPeople;)
    {
        vector<string> names(numberOfPeople);
        for (auto &n : names)
        {
            cin >> n;
        }

        vector<int> lostMoney(numberOfPeople);
        vector<int> receiveMoney(numberOfPeople);

        for (int i = 0; i < numberOfPeople; ++i)
        {
            string name;
            cin >> name;

            int sum;
            cin >> sum;

            int numberOfReceivers;
            cin >> numberOfReceivers;

            int index = find(begin(names), end(names), name) - begin(names);

            for (int j = 0; j < numberOfReceivers; ++j)
            {
                string friendName;
                cin >> friendName;
                int indexFriend = find(begin(names), end(names), friendName) - begin(names);
                receiveMoney[indexFriend] += sum / numberOfReceivers;
            }

            if (numberOfReceivers != 0)
            {
                lostMoney[index] = sum - sum % numberOfReceivers;
            }
        }
        if (!isFirst)
        {
            cout << "\n";
        }

        for (int i = 0; i < sz(names); ++i)
        {
            cout << names[i] << " " << receiveMoney[i] - lostMoney[i] << "\n";
        }
        isFirst = false;
    }
}