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

    BigInt(const long long &num)
    {
        std::string str = std::to_string(num);

        applyToVector(str, numbers);
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
