#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int life_cycle(int a, int b) {
    int start; 
    int finish;
    
    if(a > b) {
        start = b;
        finish = a;
    } else {
        start = a;
        finish = b;
    }

    int longest_counter = 0;
    
    while (start <= finish)
    {
        int num = start; 
        int counter = 0;
        
        while (num != 1)
        {
            if(num % 2 == 0) {
                num/=2;
            } else {
                num = num*3 + 1;
            }

            counter++;
        }

        if(num == 1) {
            counter++; // including last digit
        }
        
        if(counter > longest_counter) {
            longest_counter = counter;
        }

        start++;
   }
        
    return longest_counter;
}

int main()
{
    int a;
    int b;

    while(cin >> a >> b) {
        cout << a << " " << b << " " <<  life_cycle(a, b) << '\n';
    }
}