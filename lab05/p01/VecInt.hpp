#ifndef VECINT_HPP
#define VECINT_HPP

#include <stddef.h>
#include <cstddef>
#include <iostream>

#ifdef AUCA_DEBUG
#include <string>
#endif

class VecInt
{
    int *data;
    size_t sz;
    size_t cp;

public:
    using Iter = int *;
    using CIter = const int *;

    // default constructor
    VecInt()
        : data(nullptr), sz(0), cp(0)
    {
    }

    //сonstructor
    VecInt(size_t aSz, int initValue)
        : data(new int[aSz]), sz(aSz), cp(aSz)
    {

        for (size_t i = 0; i < sz; ++i)
        {
            data[i] = initValue;
        }
    }

    ~VecInt()
    {

        std::cout << "~VecInt: " << sz << " integers released" << std::endl;
        delete[] data;
    }

    std::size_t size() const
    {
        return sz;
    }

    Iter begin()
    {
        return data;
    }
    CIter begin() const
    {
        return data;
    }

    Iter end()
    {
        return data + sz;
    }

    CIter end() const
    {
        return data + sz;
    }

    const int &operator[](std::size_t index) const
    {

#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            throw std::runtime_error("VecInt: incorrect index:" + std::to_string(index));
        }
#endif
        return data[index];
    }
    int &operator[](std::size_t index)
    {
        return data[index];
    }

    void pushBack(int x);
};

#endif
