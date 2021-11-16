#include <bits/stdc++.h>
#include "../../doctest/doctest.h"

template <typename T, T Value>
struct value_as_type { static constexpr const T value { Value }; }; // stolen from github

TEST_CASE_TEMPLATE("Some name", T, value_as_type<T, T first>, value_as_type<T, T second>) {
    code = 5;
}