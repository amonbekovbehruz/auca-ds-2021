#include <bits/stdc++.h>
#include <string>

using namespace std;

int sumOfDigits(string& s, int& sum) {
    for (int i = 0; i < (int)s.length(); i++)
    {
        int character = s[i] - 48;
        sum += character;
    }

    return(sum);
}

int main() {
    string s;

    while (cin >> s)
    {
        int sum = 0;

        if(s == "0") {
            return(0);
        }

        sum = sumOfDigits(s, sum);

        while (sum >= 10)
        {
            sum = sum/100 + sum/10 + sum%10;
        }
        
        cout << sum;
    }   
}