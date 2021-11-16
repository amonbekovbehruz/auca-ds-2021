#include <bits/stdc++.h>

using namespace std;

class Computer
{
    vector<int> registers;
    vector<int> memory;
    int instructionPointer;

    void runCommand2(int d1, int d2)
    {
        registers[d1] = d2;
        instructionPointer++;
    }

    void runCommand3(int &d, int &n)
    {
        registers[d] = (registers[d] + n) % 1000;
        instructionPointer++;
    }

    void runCommand4(int &d, int &n)
    {
        registers[d] = (registers[d] * n) % 1000;
        instructionPointer++;
    }

    void runCommand5(int &d, int &n)
    {
        registers[d] = registers[n];
        instructionPointer++;
    }

    void runCommand6(int &d, int &n)
    {
        registers[d] = (registers[d] + registers[n]) % 1000;
        instructionPointer++;
    }

    void runCommand7(int &d, int &n)
    {
        registers[d] = (registers[d] * registers[n]) % 1000;
        instructionPointer++;
    }
    void runCommand8(int &d, int &n)
    {
        registers[d] = memory[registers[n]];
        instructionPointer++;
    }
    void runCommand9(int &d, int &n)
    {
        memory[registers[n]] = registers[d];
        instructionPointer++;
    }

public:
    Computer()
        : registers(10, 0), memory(1000, 0), instructionPointer(0)
    {
    }

    void readCommands(istream &input)
    {
        int curPos = 0;
        for (string line; getline(input, line) && !line.empty();)
        {
            memory[curPos] = stoi(line);
            ++curPos;
        }
    }

    int run()
    {
        int res = 1;
        while (memory[instructionPointer] != 100)
        {
            int temp = memory[instructionPointer];
            int n = temp % 10;
            temp /= 10;
            int d = temp % 10;
            temp /= 10;
            int cmd = temp;

            switch (cmd)
            {
            case 0:
                if (registers[n] != 0)
                {
                    instructionPointer = registers[d];
                }
                else
                {
                    instructionPointer++;
                }
                break;
            case 2:
                runCommand2(d, n);
                break;
            case 3:
                runCommand3(d, n);
                break;
            case 4:
                runCommand4(d, n);
                break;
            case 5:
                runCommand5(d, n);
                break;
            case 6:
                runCommand6(d, n);

                break;
            case 7:
                runCommand7(d, n);
                break;
            case 8:
                runCommand8(d, n);
                break;
            case 9:
                runCommand9(d, n);
                break;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    int tests;
    cin >> tests >> ws;

    for (int test = 0; test < tests; test++)
    {
        if (test != 0)
        {
            cout << "\n";
        }

        Computer comp;
        comp.readCommands(cin);

        cout << comp.run() << "\n";
    }
}