#include <bits/stdc++.h>

using namespace std;

void read(vector<vector<char>> &figureOnBoard, const int &height, const int &width)
{
    for (int i = 0; i < height; i++)
    {
        string line;
        cin >> line;
        for (int k = 0; k < (int)width; k++)
        {
            figureOnBoard[i][k] = line.at(k);
        }
    }
}

void checkForMax(const vector<char> &figureOnBoard, int &maxValues, const int width)
{
    for (int i = width - 1; i >= 0; i--)
    {
        if ((figureOnBoard[i] == 92 || figureOnBoard[i] == 47))
        {
            maxValues = i;
            break;
        }
    }
}

void checkForMin(const vector<char> &figureOnBoard, int &minValues, const int width)
{
    for (int i = 0; i < (int)width; i++)
    {
        if ((figureOnBoard[i] == 92 || figureOnBoard[i] == 47))
        {
            minValues = i;
            break;
        }
    }
}

double sum(const int &minValue, const int &maxValue, const vector<char> &figureOnLine, const int &width)
{
    double sum = 0;

    for (int i = 0; i < width; i++)
    {
        if ((figureOnLine[i] == 92) || (figureOnLine[i] == 47))
        {
            sum += 0.5;
        }
        else if (figureOnLine[i] == 46 && i > minValue && i < maxValue)
        {
            sum += 1;
        }
    }

    return sum;
}

int main()
{
    int height, width;
    vector<int> minValues;
    vector<int> maxValues;
    vector<vector<char>> figureOnBoard;

    while (cin >> height >> width)
    {
        minValues = vector<int>(height, 0);
        maxValues = vector<int>(height, 0);
        figureOnBoard = vector<vector<char>>(height, vector<char>(width, '.'));

        read(figureOnBoard, height, width);

        for (int i = 0; i < height; i++)
        {
            checkForMin(figureOnBoard[i], minValues[i], width);
            checkForMax(figureOnBoard[i], maxValues[i], width);
        }

        double sumOfFigure = 0;

        for (int i = 0; i < width; i++)
        {
            sumOfFigure += sum(minValues[i], maxValues[i], figureOnBoard[i], width);
        }

        cout << sumOfFigure << '\n';
    }
}