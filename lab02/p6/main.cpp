#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        int who_survives = 0;

        vector<int> numbers = {0, 0, 0};
        for (int g = 0; g < (int)numbers.size(); g++)
        {
            cin >> numbers[g];
        }

        sort(numbers.begin(), numbers.end());
        who_survives = numbers[1];

        cout << "Case " << i + 1 << ": " << who_survives << '\n';
        
    }
}