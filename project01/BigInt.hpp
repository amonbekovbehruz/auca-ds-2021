#ifndef BIGINT_HPP
#define BIGINT_HPP

#pragma once

#include <vector>
#include <iosfwd>
#include <stdexcept>
#include <cctype>
#include <string>
#include <algorithm>

class BigInt
{
    void makeVector(const std::string &str, std::vector<int> &v)
    {
        for (char num : str)
        {
            if (!(num >= '0' && num <= '9'))
            {
                throw std::runtime_error("BigInt: invalid input");
            }
            v.push_back((int)num - '0');
        }
    }

    static int cmpAbs(const BigInt &a, const BigInt &b)
    {
        if (a.mDigits.size() > b.mDigits.size())
        {
            return 1;
        }
        if (a.mDigits.size() < b.mDigits.size())
        {
            return -1;
        }
        for (size_t i = 0; i < a.mDigits.size(); ++i)
        {
            if (a.mDigits[i] != b.mDigits[i])
            {
                return a.mDigits[i] - b.mDigits[i];
            }
        }
        return 0;
    }

    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {

        mDigits.push_back(0);
    }

    BigInt(const std::string &value)
        : mIsNegative(false)
    {
        if (value.empty())
        {
            throw std::runtime_error("BigInt: empty string");
        }
        size_t i = 0;
        if (value[i] == '-' || value[i] == '+')
        {
            mIsNegative = value[i] == '-';
            ++i;
        }

        while (i + 1 != value.size() && value[i] == '0')
        {
            ++i;
        }

        for (; i != value.size(); ++i)
        {
            if (!isdigit(value[i]))
            {
                throw std::runtime_error("BigInt: Incorrect string value");
            }

            mDigits.push_back(value[i] - '0');
        }

        if (mDigits.empty())
        {
            throw std::runtime_error("BigInt: Incorrect string value");
        }
    }

    BigInt(long long x)
    {
        string s = std::to_string(x);
        for (int i = 0; i < (int)s.size(); i++)
        {
            mDigits.push_back(s.at(i));
        }
    }

    const std::vector<int> getVector() const
    {
        return mDigits;
    }
    std::vector<int> getVector()
    {
        return mDigits;
    }
}

#endif