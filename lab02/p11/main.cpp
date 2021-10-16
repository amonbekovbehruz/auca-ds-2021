#include <bits/stdc++.h>
#include <string>

using namespace std;

void convert(string& s) {
    for(int i = 0; i < (int)s.length(); i++) {
        s[i]  = tolower(s[i]);
    }
}

void sumOfChars(string s, int& sum) {
    for (int i = 0; i < (int)s.length(); i++)
    {
            sum+=((s[i]) - 96);
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

        sumOfChars(frst, sumOfFrst);
        sumOfChars(scnd, sumOfScnd);

        float numerator = (sumOfFrst%100)/10 + (sumOfFrst%10);
        float denominator = (sumOfScnd%100)/10 + (sumOfScnd%10); 
        float ratio = (numerator / denominator) * 100.0f;
        cout << sumOfFrst << '\n' << sumOfScnd << '\n' << numerator <<'\n' << denominator << '\n';
        cout << ratio <<'\n';        
    }   
}