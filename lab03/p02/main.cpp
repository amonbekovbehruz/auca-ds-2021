#include <bits/stdc++.h>

using namespace std;

void printPuzzle(const vector<vector<int>> &puzzle) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << puzzle[i][j] << ' ';
        }
        cout << '\n';
    }    
}

void horizontalManipulation(int vctr, vector<vector<int>> &puzzle, int &x, int &y) {
    if(vctr == 1) {
        if((x + 1) <= 4) {
            x++;
            char temp = puzzle[x][y];
            puzzle[x][y] = ' ';
            puzzle[x-1][y] = temp;
        }
    } else {
        if(x - 1 >= 0) {
            x--;
            char temp = puzzle[x][y];
            puzzle[x][y] = ' ';
            puzzle[x+1][y] = temp;
        }
    }
}

void verticalManipulation(int vctr, vector<vector<int>> &puzzle, int &x, int &y) {
    if(vctr == 1) {
        if(y + 1 <= 4) {
            y++; 
            char temp = puzzle[x][y];
            puzzle[x][y] = ' ';
            puzzle[x][y-1] = temp;
        }
        
    } else {
        if(y - 1 >= 0) {
            y--;    
            char temp = puzzle[x][y];
            puzzle[x][y] = ' ';
            puzzle[x][y+1] = temp;
        }
    }
}

void operations(string line, vector<vector<int>> &puzzle, int &x, int &y) {
    vector<char> manipulations;

    for(int i = 0; i < (int)line.size(); i++) {
        if(line.at(i) != '0'){
            manipulations.push_back((char)line.at(i));
        }
    }

    for(int i = 0; i < manipulations.size(); i++) {
        if(manipulations[i] == 'A') {
            verticalManipulation(1 , vector<vector<int>> &puzzle, int &x, int &y);
        } else if(manipulations[i] == 'D') {
            verticalManipulation(-1 , vector<vector<int>> &puzzle, int &x, int &y);
        } else if(manipulations[i] == 'R') {
            horizontalManipulation(1 , vector<vector<int>> &puzzle, int &x, int &y)
        } else if(manipulations[i] == 'A') {
            horizontalManipulation(-1 , vector<vector<int>> &puzzle, int &x, int &y)            
        }   
    }
}

vector<char> addLineToPuzzle(string line, int &x, int &y, int iteration) {
    const vector<char> lineArray;
    int length = line.size();            
    
    if(length > 5) {
        throw out_of_range;
    }

    for(int i = 0; i < (int)line.size(); i++) {
        line[i] = line.at(i);
        if(line.at(i) == ' ') {
            x = i;
            y = iteration;
        } 
    }

    return lineArray;    
}

vector<vector<char>> createPuzzle() {
    vector<vector<char>> result(5, vector<char>(5, ' '));
    return result;
}

int main() {
    int x, y;
    vector<vector<char>> puzzle;
    bool isComplete = true;
    int numberOfPuzzles = 0;

    while (true) {
        puzzle = createPuzzle();
        numberOfPuzzles++;

        while(true){   
            for(int i = 0; i < 6; i++) {
                if(i < 5) {
                    string line;
                    cin >> line;
                    int iteration = i;

                    try{
                        puzzle[i] = addLineToPuzzle(line, &x, &y, iteration);
                    } catch(out_of_range& e) {
                        isComplete = false;
                    }
                } else {
                    string line;
                    cin >> line;
                    operations(puzzle);
                }
            }

            printPuzzle(puzzle);
        } 
    }      
}