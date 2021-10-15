#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for(int j = 0; j < T; j++) 
    {
        int numberOfWalls = 0; cin >> numberOfWalls;
        int currentHeight = 0; 
        int totalHighs = 0;
        int totalLows = 0;

        if(numberOfWalls > 1) {
            for(int i = 0; i < numberOfWalls - 2; i++) {
                int height; cin >> height;

                if(currentHeight - height > 0) {
                    totalLows++;
                    currentHeight = height;
                } 
                if (currentHeight - height < 0){
                    totalHighs++;
                    currentHeight = height;  
                }
            }
        }
        cout << "Case " << j + 1 << ": " << totalHighs << " " << totalLows << '\n'; 
    }
}