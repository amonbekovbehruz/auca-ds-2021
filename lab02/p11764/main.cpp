#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; 
    cin >> T;

    for(int i = 0; i < T; i++) {
        int walls; 
        cin >> walls;
        int highs = 0;
        int lows = 0;
        int current = 0;

        for (int j = 0; j < walls; j++)
        {
            int height;
            cin >> height;
            if(current == 0) {
                current = height; 
            }

            if(current - height > 0) {
                lows++;

            } else if(current - height < 0) {
                highs++;
            }
            
            current = height;
       }
        
        cout << "Case " << i+1 << ": " << highs << " " << lows <<'\n';
    }
}