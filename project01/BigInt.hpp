#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend BigInt operator+(const BigInt &a, const BigInt &b);
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

    static BigInt addAbsValues(const BigInt &first, const BigInt &second)
    {
        BigInt result;
        result.mDigits.clear();

        auto i = first.mDigits.rbegin();
        auto j = second.mDigits.rbegin();

        int carry = 0;
        while (i != first.rend() || j != second.rend())
        {
            int sum = carry;

            if (i != first.mDigits.rend())
            {
                sum += *i;
                i++;
            }
            if (j != second.mDigits.rend())
            {
                sum += *j;
                j++;
            }
            result.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }
    }

    static BigInt subAbsValues(const BigInt &first, const BigInt &second)
    {
    }

    bool isNegative = false;
    std::vector<int> mDigits;

public:
    BigInt()
    {
        mDigits = std::vector<int>(1, 0);
        isNegative = false;
    };

    BigInt(const std::string &nums)
    {
        nums.at(0) == '-' ? isNegative = true : isNegative = false;
        applyToVector(nums, mDigits);
    }

    BigInt(const std::vector<int> &res)
    {
        mDigits = res;
    }

    BigInt(const long long &num)
    {
        if (num < 0)
        {
            isNegative = true;
        }
        std::string str = std::to_string(num);

        applyToVector(str, mDigits);
    }

    const std::vector<int> getVector() const
    {
        return mDigits;
    }

    const int size() const
    {
        return (int)mDigits.size();
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

inline BigInt operator+(const BigInt &first, const BigInt &second)
{
    if (first.isNegative == second.isNegative)
    {
        BigInt result;
        result = BigInt::addAbsValues(first, second);
        return result;
    }
    int compare = BigInt::compare(first, second);
}

inline BigInt operator-(const BigInt &first, const BigInt &second)
{
}