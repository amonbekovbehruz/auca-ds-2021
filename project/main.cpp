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

    SUBCASE("Constructor with string entry")
    {
        BigInt bigint("123456");
        out << bigint;

        REQUIRE(out.str() == "123456");
    }

    SUBCASE("Constructor with wrong input")
    {
        REQUIRE_THROWS_AS(BigInt bigint("ABCD"), std::runtime_error);
    }

    SUBCASE("Constructor with entry as int")
    {
        BigInt bigint(12345678910);
        out << bigint;

        REQUIRE(out.str() == "12345678910");
    }
}

TEST_CASE("Operator +")
{
    std::ostringstream sout;

    SUBCASE("123456789 + 321654987")
    {
        BigInt first("123456789");
        BigInt second("321654987");
        sout << first + second;

        REQUIRE(sout.str() == "445,111,776");
    }
}