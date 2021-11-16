#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int first;
        cin >> first;
        if (first == 0) {
            break;
        }
        
        int second;
        cin >> second;

        vector<int> n(first);
        vector<int> m(second);

        for (int i = 0; i < (int)n.size(); i++)
        {
            int e;
            cin >> e;
            n[i] = e;
        }
        for (int i = 0; i < (int)m.size(); i++)
        {
            int e;
            cin >> e;
            m[i] = e;
        }

        vector<double> d;

        for (int i = 0; i < first; i++)
        {
            for (int j = 0; j < second; j++)
            {
                double num = (double)n[i] / ((double)m[j]);
                d.push_back(num);
            }
        }

        sort(begin(d), end(d));

        double mx = 0;

        for (int i = 1; i < (int)d; i++)
        {
            double val = d[i] / d[i - 1];
            mx = max(val, mx);
        }
        printf("%.2lf\n", mx);
    }
}