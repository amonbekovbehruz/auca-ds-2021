#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases; cin >> cases;

    while (cases--)
    {
        int max = 0; int min = 100;

        int shops; cin >> shops; 

        while (shops--)
        {
            int s; cin >> s;

                if(s > max) { 
                    max = s;
                }
                if(s < min) 
                {
                    min = s;
                }
            }
           
        cout << 2 * (max - min) << '\n';
    }
    
}