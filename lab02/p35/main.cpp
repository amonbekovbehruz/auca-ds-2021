#include <bits/stdc++.h>

using namespace std;

void print(const vector<string> &words)
{
    for (int i = 0; i < (int)words.size(); i++)
    {
        if ((i + 1) == (int)words.size())
        {
            cout << words[i] << '\n';
        }
        else
        {
            cout << words[i] << ' ';
        }
    }
}

string replacer(string &str, const string &lineQWERTY)
{
    string word;

    for (int i = 0; i < (int)str.length(); i++)
    {
        char letter = str.at(i);

        for (int j = 0; j < (int)lineQWERTY.length(); j++)
        {
            if ((char)letter == (char)lineQWERTY.at(j))
            {
                letter = lineQWERTY.at(j - 2);
                break;
            }
        }
        word += letter;
    }

    return word;
}

int main()
{
    string lineQWERTY = "qwertyuiop[]asdfghjkl;'zxcvbnm,.";
    vector<string> words;
    string line;

    while (cin >> line)
    {
        words.push_back(line);
    }

    for (int i = 0; i < (int)words.size(); i++)
    {
        words[i] = replacer(words[i], lineQWERTY);
    }

    print(words);
}