#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        int numbersOfStudents;
        cin >> numbersOfStudents;
        int sum = 0;
        vector<int> percentage(numbersOfStudents, 0);

        for (int j = 0; j < numbersOfStudents; ++j)
        {
            int result;
            cin >> result;
            sum += result;
            percentage[j] = result;
        }

        double average = sum * 1.0 / numbersOfStudents;
        int aboveAverage = 0;

        for (int j = 0; j < numbersOfStudents; j++)
        {
            if (percentage[j] > average)
            {
                aboveAverage++;
            }
        }

        double aboveAverageInPercents = (aboveAverage * 100.0 / numbersOfStudents);

        cout << fixed << setprecision(3) << aboveAverageInPercents << "%" << '\n';
    }
}