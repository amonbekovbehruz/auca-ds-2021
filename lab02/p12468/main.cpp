#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b; 
    int answer = 0;
    int answer2 = 0;

    while (cin >> a >> b)
    {
        if (a == -1 && b == -1){
            break;
        }
        if (a > b){ // 20 84
            swap(a, b);
            answer = abs(b - a); // 64
            answer2 = abs(100 - b + a); //36
        } else {
            answer = abs(b - a); // 64
            answer2 = abs(100 - b + a); //36
        }

        
        if (answer2 > answer){
            cout << answer << '\n';
        } else {
            cout << answer2 << '\n';
        }
    }
}