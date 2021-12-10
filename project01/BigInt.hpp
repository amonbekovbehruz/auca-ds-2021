#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

class BigInt
{
    void applyToVector(const std::string &str, std::vector<int> &vector)
    {
        for (char num : str)
        {
            if (!(num >= 48 && num <= 57))
            {
                throw std::runtime_error("BigInt: invalid input");
            }

            vector.push_back((int)num - 48);
        }
    }

    bool isNegative = false;
    std::vector<int> numbers;

public:
    BigInt()
    {
        numbers = std::vector<int>(1, 0);
        isNegative = false;
    };

    BigInt(const std::string &nums)
    {
        nums.at(0) == '-' ? isNegative = true : isNegative = false;
        applyToVector(nums, numbers);
    }

    BigInt(const std::vector<int> &res)
    {
        numbers = res;
    }

    BigInt(const long long &num)
    {
        if (num < 0)
        {
            isNegative = true;
        }
        std::string str = std::to_string(num);

        applyToVector(str, numbers);
    }

    const std::vector<int> getVector() const
    {
        return numbers;
    }

    const int size() const
    {
        return (int)numbers.size();
    }

    const bool checkForNegativity() const
    {
        return isNegative;
    }
};

std::ostream &operator<<(std::ostream &sout, const BigInt &r)
{
    if (r.checkForNegativity())
    {
        sout << '-';
    }
    for (auto c : r.getVector())
    {
        sout << c;
    }

    return sout;
}

BigInt operator+(const BigInt &first, const BigInt &second)
{
    std::vector<int> firstVector = first.getVector();
    std::vector<int> secondVector = second.getVector();

    int minSize = firstVector.size() > secondVector.size() ? secondVector.size() : firstVector.size();

    std::reverse(firstVector.begin(), firstVector.end());
    std::reverse(secondVector.begin(), secondVector.end());

    std::vector<int> result = firstVector;
    bool toAddDigit = false;
    for (int i = 0; i < (int)minSize; i++)
    {
        if (firstVector[i] + secondVector[i] > 9)
        {
            result[i] = firstVector[i] + secondVector[i] % 10;
            if (toAddDigit)
            {
                result[i] += 1;
            }
            toAddDigit = true;
        }
        else
        {
            result[i] = firstVector[i] + secondVector[i];
            if (toAddDigit)
            {
                result[i] += 1;
                toAddDigit = false;
            }
            if (result[i] > 9)
            {
                result[i] %= 10;
                toAddDigit = true;
            }
        }
    }

    std::reverse(result.begin(), result.end());
    return BigInt(result);
}
