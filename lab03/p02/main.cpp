#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

void horizontalManipulation(int vctr, vector<vector<char>> &puzzle, int &x, int &y) {
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

void verticalManipulation(int vctr, vector<vector<char>> &puzzle, int &x, int &y) {
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

void operations(string line, vector<vector<char>> &puzzle, int &x, int &y) {
    vector<char> manipulations;

    for(int i = 0; i < (int)line.size(); i++) {
        if(line.at(i) != '0'){
            manipulations.push_back((char)line.at(i));
        }
    }

    for(int i = 0; i < (int)manipulations.size(); i++) {
        if(manipulations[i] == 'A') {
            verticalManipulation(1 , puzzle, x, y);
        } else if(manipulations[i] == 'D') {
            verticalManipulation(-1 , puzzle, x, y);
        } else if(manipulations[i] == 'R') {
            horizontalManipulation(1 , puzzle, x, y);
        } else if(manipulations[i] == 'L') {
            horizontalManipulation(-1 , puzzle, x, y);            
        }   
    }
}

vector<char> addLineToPuzzle(string line, int &x, int &y, int iteration) {
    const vector<char> lineArray;
    int length = line.size();            
    
    if(length > 5) {
        throw out_of_range("blah");
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

void printPuzzle (const vector<vector<char>> &puzzle) {
    string stringPuzzle;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (j < 4) {
                stringPuzzle += (char)puzzle[i][j];
                stringPuzzle += ' ';
            } else {
                stringPuzzle += (char)puzzle[i][j];
            }
        }   

        cout << stringPuzzle << '\n';
    }    
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

                    if(line == "Z") {
                        return(0);
                    }

                    try{
                        puzzle[i] = addLineToPuzzle(line, x, y, iteration);
                    } catch(out_of_range& e) {
                        isComplete = false;
                    }
                } else {
                    string line;
                    cin >> line;
                    operations(line, puzzle, x, y);
                }
            }
        } 
        printPuzzle(puzzle);
        if(!isComplete) {
            break;
        }
    }      
}