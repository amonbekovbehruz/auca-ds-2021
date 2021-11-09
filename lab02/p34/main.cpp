#include <bits/stdc++.h>

using namespace std;

bool isContainingSimilarDigits(const int &number)
{
    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int dozens = (number % 1000 % 100) / 10;
    int digits = number % 1000 % 100 % 10;

    vector<int> numbers = {digits, dozens, hundreds, thousands};

    if (thousands == 0 && hundreds == 0)
    {
        numbers = {digits, dozens};
    }
    else if (thousands == 0)
    {
        numbers = {digits, dozens, hundreds};
    }
    else if (thousands == 0 && hundreds == 0 && dozens == 0)
    {
        numbers = {digits, dozens, hundreds};
    }
    else
    {
        numbers = {digits, dozens, hundreds, thousands};
    }

    for (int i = 0; i < (int)numbers.size(); i++)
    {
        for (int j = 0; j < (int)numbers.size(); j++)
        {
            if (numbers[i] == numbers[j] && i != j)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int first, second;

    while (cin >> first >> second)
    {
        int difference = abs(second - first);

        vector<int> numbers(difference + 1, 0);
        vector<bool> isRepeating(difference + 1, false);

        int counter = 0;
        for (int i = 0; i < (int)numbers.size(); i++)
        {
            numbers[i] += (first + counter);
            counter++;
        }

        for (int i = 0; i < (int)isRepeating.size(); i++)
        {
            isRepeating[i] = isContainingSimilarDigits(numbers[i]);
        }

        int numberOfHouses = 0;
        for (int i = 0; i < (int)isRepeating.size(); i++)
        {
            if (!isRepeating[i])
            {
                numberOfHouses++;
            }
        }

        cout << numberOfHouses << '\n';
    }
}