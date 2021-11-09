#include <bits/stdc++.h>

using namespace std;

void print(const vector<string> &words) {
    for (int i = 0; i < (int) words.size(); i++) {
        if ((i + 1) == (int) words.size()) {
            cout << words[i];
        } else {
            cout << words[i] << ' ';
        }
    }
}

string replacer(string &str, const vector<char> &chars) {
    string word;

    for (int i = 0; i < (int) str.length(); i++) {
        char letter = str.at(i);

        for (int j = 0; j < (int) chars.size(); j++) {
            if (letter == chars[i]) {
                letter = chars[i - 2];
                break;
            }
        }
        word += letter;
    }

    return word;
}

int main() {
    string lineQWERTY = "qwertyuiop[]asdfghjkl;'zxcvbnm";
    vector<char> qwerty;
    vector<string> words;
    string line;

    for (int i = 0; i < (int) lineQWERTY.length(); i++) {
        qwerty.push_back(lineQWERTY.at(i));
    }

    while (cin >> line) {
        words.push_back(line);
    }

    for (int i = 0; i < (int)words.size(); i++) {
        words[i] = replacer(words[i], qwerty);
    }

    print(words);
}