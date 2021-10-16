#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    int cases; cin >> cases;
    bool isOrdered(true), isReverseOrdered(true);
        
    cout << "Lumberjacks:\n";
    for(int i = 0; i < cases; i++) {
        vector<int> lumberjacks;
        
        if(i == 0) {
            int s;
            cin >> s;
            lumberjacks.push_back(s);
        }  // Ovnocode      
        
        int beardLength;
        string str;
        getline(cin, str);
        istringstream iss(str);

        while (iss >> beardLength) {
            lumberjacks.push_back(beardLength);
        }

        for(int j = 1; j < (int)lumberjacks.size(); j++) {
            if(!(lumberjacks[j] > lumberjacks[j - 1])) {
                isOrdered = false;
            }
        }

        for(int j = 1; j < (int)lumberjacks.size(); j++) {
            if(!(lumberjacks[j] < lumberjacks[j - 1])) {
                isReverseOrdered = false;
            }
        }

        if(isOrdered) {
            cout << "Ordered\n";
        } else if(isReverseOrdered){
            cout << "Ordered\n";
        } else if(!isOrdered){
            cout << "Unordered\n";
        }

        isOrdered = true;
        isReverseOrdered = true;
    }
}