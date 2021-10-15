#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
   string line;
   char chosen;

    while (cin >> line) {
        int length = (int) line.length();

        for (int i = 0; i < length; i++) {
            cin.get(chosen);           
            cout << chosen; 
        }
        
    }
}