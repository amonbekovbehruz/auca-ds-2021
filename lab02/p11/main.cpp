#include <bits/stdc++.h>
#include <string>

using namespace std;

void convert(string& s) {
    for(int i = 0; i < (int)s.length(); i++) {
        s[i]  = tolower(s[i]);
    }
}

int main() {
    string frst;
    string scnd;

    while (cin >> frst >> scnd)
    {
        convert(frst);
        convert(scnd);
        int sumOfFrst = 0;
        int sumOfScnd = 0; 

        for (int i = 0; i < (int)frst.length(); i++)
        {
            sumOfFrst+=((frst[i]) - 96);
        }

        for (int i = 0; i < (int)(scnd.length()); i++)
        {
            sumOfScnd+=((scnd[i]) - 96);
        }

        float numerator = (sumOfFrst/10) + (sumOfFrst%10);
        float denominator = (sumOfScnd/10) + (sumOfScnd%10); 
        float ratio = (numerator / denominator) * 100.0f;
        cout << sumOfFrst << '\n' << sumOfScnd << '\n' << numerator <<'\n' << denominator << '\n';
        cout << ratio <<'\n';        
    }   
}