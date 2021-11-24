#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

class BigInt
{
    std::vector<int> numbers;

public:
    BigInt()
    {
        numbers = std::vector<int>(1, 0);
    };

    BigInt(const std::string &nums)
    {
        for (char num : nums)
        {
            if (!(num >= 48 && num <= 57))
            {
                throw std::runtime_error("BigInt: invalid input");
            }

            numbers.push_back((int)num - 48);
        }
    }

    BigInt(const long long &num) {
        
    }
    
    const std::vector<int> getVector() const
    {
        return numbers;
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
