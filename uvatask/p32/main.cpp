#include <bits/stdc++.h>
#include <string>

using namespace std;

void print(const vector<int> &occurences)
{
    for (int i = 0; i < (int)occurences.size(); i++)
    {
        if (i != (int)occurences.size() - 1)
        {
            cout << occurences[i] << ' ';
        }
        else
        {
            cout << occurences[i] << '\n';
        }
    }
}

int main()
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int sequence;
        cin >> sequence;
        string num;
        vector<int> occurences(10, 0);

        for (int j = 1; j <= sequence; j++)
        {
            num += to_string(j);
        }

        for (int j = 0; j < (int)num.length(); j++)
        {
            char number = num.at(j);
            switch (number)
            {
            case 48:
                occurences[0]++;
                break;
            case 49:
                occurences[1]++;
                break;
            case 50:
                occurences[2]++;
                break;
            case 51:
                occurences[3]++;
                break;
            case 52:
                occurences[4]++;
                break;
            case 53:
                occurences[5]++;
                break;
            case 54:
                occurences[6]++;
                break;
            case 55:
                occurences[7]++;
                break;
            case 56:
                occurences[8]++;
                break;
            case 57:
                occurences[9]++;
                break;
            }
        }

        print(occurences);
    }
}