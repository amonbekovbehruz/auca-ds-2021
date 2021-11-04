#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> readShuffle();
vector<int> createDeck();
void applyShuffleToDeck(vector<int>& deck, const vector<int>& shuffle);
void printDeck(const vector<int>& deck);

int main() 
{
    int testCases;
    cin >> testCases;

    for(int test = 0; test < testCases; ++test) 
    {
        auto shuffles = readShuffle();
        auto deck = createDeck();

        for(string line; getline(cin, line) && !line.empty();) {
            int c = stoi(line);
            applyShuffleToDeck(deck, shuffles[c-1]);
        }

        if(test != 0) {
        cout << '\n';
        }

        printDeck(deck);
    }    
}

vector<vector<int>> readShuffle() {
    int n;
    cin >> n;

    vector<vector<int>> r(n, vector<int>(52));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 52; j++) {
            cin >> r[i][j];
        }
    }

    cin.ignore(1024, '\n');
    return r;
}

vector<int> createDeck()
{
    vector<int> result(52);

    for(int i = 0; i < 52; ++i)
    {
        result[i] = i;
    }

    return result;
}

void printDeck(const vector<int> &deck) 
{
    static vector<string> ranks = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    static vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
    
    for(auto card: deck) 
    { 
        cout << ranks[card%13] << " of " << suits[card/13] << endl;
    }
}

void applyShuffleToDeck (vector<int>& deck, const vector<int>& shuffle) {
    auto v1 = deck;

    for(int i = 0; i < 52; i++) 
    {
        deck[i] = v1[shuffle[i] - 1];
    }    
}