#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <sstream>
#include <cstdint>
#include "BigInt.hpp"
#include <stdexcept>
#include <ctype.h>

TEST_CASE("Default constructor")
{
    std::ostringstream out;

    SUBCASE("Default constructor with no entry")
    {
        BigInt bigint;
        out << bigint;

        REQUIRE(out.str() == "0");
    }

    SUBCASE("Default constructor with no entry")
    {
        BigInt bigint("123456");
        out << bigint;

        REQUIRE(out.str() == "123456");
    }

    SUBCASE("Default constructor with no entry")
    {
        REQUIRE_THROWS_AS(BigInt bigint("ABCD"), std::runtime_error);
    }
}
