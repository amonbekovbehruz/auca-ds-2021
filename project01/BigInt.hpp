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

    static BigInt multiplication(const BigInt &a, const BigInt &b)
    {
        BigInt result;

        result.mDigits.resize(a.mDigits.size() + b.mDigits.size());
        int shift = 0;
        for (auto i = b.mDigits.rbegin(); i != b.mDigits.rend(); ++i)
        {
            int carry = 0;
            int currShift = shift;
            for (auto j = a.mDigits.rbegin(); j != a.mDigits.rend(); ++j)
            {
                int total = *i * *j + carry;
                addDigit(r, total % 10, currShift);
                carry = total / 10;
                ++currShift;
            }
            if (carry != 0)
            {
                addDigit(result, carry, currShift);
            }
            ++shift;
        }
        if (result.mDigits.front() == 0)
        {
            result.mDigits.erase(r.mDigits.begin());
        }

        return result;
    }

    static BigInt add(const BigInt &a, const BigInt &b)
    {
        BigInt r;
        r.mDigits.clear();

        auto i = a.mDigits.rbegin();
        auto j = b.mDigits.rbegin();

        int carry = 0;
        while (i != a.mDigits.rend() || j != b.mDigits.rend())
        {
            int sum = carry;

            if (i != a.mDigits.rend())
            {
                sum += *i;
                ++i;
            }
            if (j != b.mDigits.rend())
            {
                sum += *j;
                ++j;
            }
            r.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0)
        {
            r.mDigits.push_back(carry);
        }

        std::reverse(r.mDigits.begin(), r.mDigits.end());

        return r;
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