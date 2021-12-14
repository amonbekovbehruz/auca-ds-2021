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

    static int compare(const BigInt &a, const BigInt &b)
    {
        if (a.mDigits.size() > b.mDigits.size())
        {
            return 1;
        }
        if (a.mDigits.size() < b.mDigits.size())
        {
            return -1;
        }
        for (int i = 0; i < a.mDigits.size(); ++i)
        {
            if (a.mDigits[i] != b.mDigits[i])
            {
                return (a.mDigits[i] - b.mDigits[i]);
            }
        }

        return 0;
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

bool operator==(const BigInt &first, const BigInt &second)
{
    if (first.checkForNegativity == second.checkForNegativity && first.getVector == second.getVector)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const BigInt &first, const BigINt &second)
{
    return !(first == second);
}

BigInt operator+(BigInt &first, BigInt &second)
{
}