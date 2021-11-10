#include <iostream>
#include <vector>

using namespace std;

struct BlockWorld
{
    vector<vector<int>> mData;

    void findBlock(int a, int &x, int &y)
    {
        for (int i = 0; i < int(mData.size()); i++)
        {
            for (int j = 0; j < int(mData[i].size()); ++j)
            {
                if (mData[i][j] == a)
                {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
    }

    void putBack(int x, int a)
    {
        while (!mData.empty() && mData[x].back() != a)
        {
            mData[mData[x].back()].push_back(mData[x].back());
            mData[x].pop_back();
        }
    }

    void pileBlocks(int d, int x, int y)
    {
        int c = 0;
        for (int i = y; i < int(mData[x].size()); i++, c++)
        {
            mData[d].push_back(mData[x][i]);
        }
        for (int i = 0; i < c; i++)
        {
            mData[x].pop_back();
        }
    }

    BlockWorld(int n)
        : mData(n) // initialization
    {
        for (int i = 0; i < n; i++)
        {
            mData[i].push_back(i);
        }
    }
}

int
main()
{
}