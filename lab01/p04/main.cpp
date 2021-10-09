#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> 
using namespace std;

int main() {
    for(string line; getline(cin, line));
    {
        string buff = line;
        cout << line << endl;
        for (auto c: line) 
        {
            if (isalpha(c))
            {
                buff += tolower(c);
            }   
        }

        string temp = buff;
        reverse(temp.begin, temp.end);

        cout << (buff == temp ? "palindrome\n": "not a palindrome\n");
    }
}