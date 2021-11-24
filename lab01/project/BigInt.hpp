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

    std::vector<int> numbers;

public:
    BigInt()
    {
        numbers = std::vector<int>(1, 0);
    };

    BigInt(const std::string &nums)
    {
        applyToVector(nums, numbers);
    }

    BigInt(const std::vector<int> &res)
    {
        numbers = res;
    }

    BigInt(const long long &num)
    {
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
};

std::ostream &operator<<(std::ostream &sout, const BigInt &r)
{
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

    if ((int)firstVector.size() < (int)secondVector.size())
    {
        std::vector<int> temp = secondVector;
        secondVector = firstVector;
        firstVector = temp;
    }

    std::reverse(firstVector.begin(), firstVector.end());
    std::reverse(secondVector.begin(), secondVector.end());

    std::vector<int> result = firstVector;
    bool toAddDigit = false;
    for (int i = 0; i < (int)secondVector.size(); i++)
    {
        if (firstVector[i] + secondVector[i] > 9)
        {
            result[i] = firstVector[i] + secondVector[i] % 10;
            toAddDigit = true;
        }
        else
        {
            result[i] = firstVector[i] + secondVector[i];
            if (toAddDigit)
            {
                result[i] += 1;
            }
        }
    }

    std::reverse(result.begin(), result.end());
    return BigInt(result);
}
