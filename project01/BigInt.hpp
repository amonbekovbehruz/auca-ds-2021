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
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);

    friend std::istream &operator>>(std::istream &inp, BigInt &x);

    friend BigInt operator+(const BigInt &a, const BigInt &b);

    friend BigInt operator*(const BigInt &a, const BigInt &b);

    friend BigInt operator-(const BigInt &a, const BigInt &b);

    friend BigInt operator%(const BigInt &a, const BigInt &b);

    friend BigInt operator/(const BigInt &a, const BigInt &b);

    friend bool operator==(const BigInt &a, const BigInt &b);

    friend bool operator>(const BigInt &a, const BigInt &b);

    friend bool operator!=(const BigInt &a, const BigInt &b);

    friend bool operator<(const BigInt &a, const BigInt &b);

    friend bool operator>=(const BigInt &a, const BigInt &b);

    friend bool operator<=(const BigInt &a, const BigInt &b);

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

    static BigInt add(const BigInt &a, const BigInt &b)
    {
        BigInt result;
        result.mDigits.clear();

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
            result.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0)
        {
            result.mDigits.push_back(carry);
        }

        std::reverse(result.mDigits.begin(), result.mDigits.end());

        return result;
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
                addDigit(result, total % 10, currShift);
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
            result.mDigits.erase(result.mDigits.begin());
        }

        return result;
    }

    static void addDigit(BigInt &result, int d, int shift)
    {
        auto i = result.mDigits.rbegin() + shift;
        *i += d;
        int carry = *i / 10;
        *i %= 10;
        while (carry != 0)
        {
            ++i;
            *i += carry;
            carry = *i / 10;
            *i %= 10;
        }
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

inline std::ostream &
operator<<(std::ostream &out, const BigInt &first)
{
    if (first.mIsNegative)
    {
        out << "-";
    }

    for (auto digit : first.mDigits)
    {
        out << digit;
    }

    return out;
}

bool operator==(const BigInt &a, const BigInt &b)
{
    return a.mIsNegative == b.mIsNegative && a.mDigits == b.mDigits;
}

bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

inline BigInt operator+(const BigInt &first, const BigInt &second)
{
    if (first.mIsNegative == second.mIsNegative)
    {
        BigInt result = BigInt::addAbsValues(first, second);
        result.mIsNegative = first.mIsNegative;
        return result;
    }
    int cmp = BigInt::cmpAbs(first, second);
    if (cmp == 0)
    {
        return BigInt();
    }

    if (cmp > 0)
    {
        BigInt result = BigInt::sub(first, second);
        result.mIsNegative = first.mIsNegative;
        return result;
    }
    else if (cmp < 0)
    {
        BigInt result = BigInt::sub(second, first);
        result.mIsNegative = second.mIsNegative;
        return result;
    }

    return BigInt();
}

inline BigInt operator-(const BigInt &first, const BigInt &second)
{
    if (!first.mIsNegative && second.mIsNegative)
    {
        BigInt result = BigInt::addAbsValues(first, second);
        result.mIsNegative = false;
        return result;
    }

    if (first.mIsNegative && !second.mIsNegative)
    {
        BigInt result = BigInt::addAbsValues(first, second);
        result.mIsNegative = true;
        return result;
    }

    if (first.mIsNegative == second.mIsNegative)
    {
        int cmp = BigInt::cmpAbs(first, second);
        if (cmp == 0)
        {
            return BigInt();
        }

        if (cmp > 0)
        {
            BigInt result = BigInt::sub(first, second);
            result.mIsNegative = first.mIsNegative;
            return result;
        }
        else
        {
            BigInt result = BigInt::sub(second, first);
            result.mIsNegative = true;
            return result;
        }
    }
    return BigInt();
}

BigInt &operator++(BigInt &x)
{
    x += x + 1;
    return x;
}

BigInt &operator--(BigInt &x)
{
    x += x - 1;
    return x;
}

inline bool operator<(const BigInt &first, const BigInt &second)
{
    if (first.mIsNegative && !(second.mIsNegative))
    {
        return true;
    }
    if (!(first.mIsNegative) && second.mIsNegative)
    {
        return false;
    }
    if (!(first.mIsNegative) && !(second.mIsNegative))
    {
        return (BigInt::cmpAbs(first, second)) < 0;
    }

    return (BigInt::cmpAbs(first, second)) > 0;
}

inline bool operator>(const BigInt &a, const BigInt &b)
{
    if (a == b)
    {
        return false;
    }
    return !(a < b);
}

inline bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(b < a);
}

inline bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b);
}

inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    char ch;
    if (!(inp >> ch))
    {
        return inp;
    }

    if (ch != '+' && ch != '-' && !isdigit(ch))
    {
        inp.putback(ch);
        throw std::runtime_error("Wrong input");
        return inp;
    }
    std::string str;
    str += ch;
    while (inp.get(ch) && isdigit(ch))
    {
        str += ch;
    }

    if (inp)
    {
        inp.putback(ch);
    }

    if (str.size() == 1 && (str[0] == '+' || str[0] == '-'))
    {
        throw std::runtime_error("Wrong input");
        return inp;
    }

    x = BigInt(str);

    inp.clear();
    return inp;
}

inline BigInt operator*(const BigInt &first, const BigInt &second)
{
    if (first == 0 || second == 0)
    {
        return BigInt();
    }
    BigInt result = BigInt::multiplication(first, second);
    result.mIsNegative = first.mIsNegative ^ second.mIsNegative;

    return result;
}

inline BigInt operator%(const BigInt &first, const BigInt &second)
{
    BigInt result = first;
    BigInt temp;

    if (first == 0)
    {
        return BigInt();
    }

    if (first < second)
    {
        return result;
    }

    while (first > second)
    {
        result = result - second;
    }

    result = temp;

    return result;
}

#endif