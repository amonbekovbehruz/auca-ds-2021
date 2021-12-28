#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct F
{
    char letter;
    int count;

    F(char aLetter, int aCount)
        : letter(aLetter), count(aCount)
    {
    }
};

int main()
{
    int nTest;
    cin >> nTest;

    for (int caseN = 1; caseN <= nTest; caseN++)
    {
        int R, C, M, N;
        cin >> R >> C >> M >> N;

        vector<F> vec;
        vector<int> counter(100, 0);
        for (int j = 0; j < R; j++)
        {
            string str;
            cin >> str;
            for (auto i : str)
            {
                counter[i]++;
            }
        }

        for (int i = 0; i < counter.size(); i++)
        {
            if (counter[i] != 0)
            {
                vec.push_back(F(i, counter[i]));
            }
        }
        sort(vec.begin(), vec.end(), [](F x, F y)
             { return y.count < x.count; });

        int maxN = vec[0].count;

        int result = M * maxN;

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].count == maxN)
            {
                result += M * maxN;
            }
            else
            {
                result += N * vec[i].count;
            }
        }
        cout << "Case " << caseN << ": " << result << endl;
    }
}