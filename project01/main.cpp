#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BigInt.hpp"
#include <sstream>
#include <stdexcept>
#include <limits>

using namespace std;

TEST_CASE("Default constructor")
{
    BigInt a;
    ostringstream sout;
    sout << a;
    REQUIRE(sout.str() == "0");
}

TEST_CASE("Constructor with string")
{
    ostringstream sout;
    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
    SUBCASE("Case 1")
    {
        BigInt x("177");
        sout << x;

        REQUIRE(sout.str() == "177");
    }

    SUBCASE("Case 2")
    {
        BigInt x("-123345345345345345345435");
        sout << x;

        REQUIRE(sout.str() == "-123345345345345345345435");
    }

    SUBCASE("Case 2")
    {
        BigInt x("-123345345345345345345435");
        sout << x;

        REQUIRE(sout.str() == "-123345345345345345345435");
    }
    SUBCASE("Case 3")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }

    SUBCASE("-")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
    SUBCASE("+")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
    SUBCASE("12344d132")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
}

TEST_CASE("BigInt with long long")
{
    ostringstream sout;
    SUBCASE("-9223372036854775808")
    {
        BigInt x(numeric_limits<long long>::min());
        sout << x;
        REQUIRE(sout.str() == "-9223372036854775808");
    }
}

TEST_CASE("operator+")
{
    ostringstream sout;
    SUBCASE("123 + 19")
    {
        BigInt x(123);
        BigInt y(19);

        sout << x + y;

        REQUIRE(sout.str() == "142");
    }

    SUBCASE("99999999 + 1")
    {
        BigInt x(1);
        BigInt y(99999999);

        sout << x + y;

        REQUIRE(sout.str() == "100000000");
    }
    SUBCASE("3 + -3")
    {
        BigInt x = 3;
        BigInt y = -3;
        sout << x + y;
        REQUIRE(sout.str() == "0");
    }

    SUBCASE("5 + -7")
    {
        BigInt x = 5;
        BigInt y = -7;
        sout << x + y;
        REQUIRE(sout.str() == "-2");
    }

    SUBCASE("-3 + -3")
    {
        BigInt x = -3;
        BigInt y = -3;
        sout << x + y;
        REQUIRE(sout.str() == "-6");
    }
    SUBCASE("-3 + 1")
    {
        BigInt x = -3;
        BigInt y = 1;
        sout << x + y;
        REQUIRE(sout.str() == "-2");
    }
    SUBCASE("-5 + 3")
    {
        BigInt x = -5;
        BigInt y = 3;
        sout << x + y;
        REQUIRE(sout.str() == "-2");
    }
}
TEST_CASE("operator-")
{
    ostringstream sout;
    SUBCASE("123 - 19")
    {
        BigInt x(123);
        BigInt y(19);

        sout << x - y;

        REQUIRE(sout.str() == "104");
    }
    SUBCASE("5 - 7")
    {
        BigInt x(5);
        BigInt y(-7);

        sout << x + y;

        REQUIRE(sout.str() == "-2");
    }

    SUBCASE("-30 - 19")
    {
        BigInt x(-30);
        BigInt y(19);

        sout << x - y;

        REQUIRE(sout.str() == "-49");
    }
    SUBCASE("-20 - -5")
    {
        BigInt x(-20);
        BigInt y(-5);

        sout << x - y;

        REQUIRE(sout.str() == "-15");
    }
    SUBCASE("5 - 17")
    {
        BigInt x = 5;
        BigInt y = 17;
        sout << x - y;
        REQUIRE(sout.str() == "-12");
    }
    SUBCASE("40 - -5")
    {
        BigInt x(40);
        BigInt y(-5);

        sout << x - y;

        REQUIRE(sout.str() == "45");
    }
}

TEST_CASE("BigInt: Equal")
{
    ostringstream sout;
    SUBCASE("122 == 122")
    {
        BigInt x("122");
        BigInt y("122");

        REQUIRE(x == y);
    }
    SUBCASE("-40 == -40")
    {
        BigInt x("-40");
        BigInt y("-40");

        REQUIRE(x == y);
    }

    SUBCASE("-20 == 20")
    {
        BigInt x("-20");
        BigInt y("20");

        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
}

TEST_CASE("BigInt: Not Equal")
{
    ostringstream sout;
    SUBCASE("102 != 122")
    {
        BigInt x("122");
        BigInt y("102");

        REQUIRE(x != y);
    }

    SUBCASE("2222 != 222")
    {
        BigInt x("2222");
        BigInt y("222");

        // REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
        REQUIRE(x != y);
    }
}

TEST_CASE("BigInt: Less or Equal")
{
    ostringstream sout;

    SUBCASE("120 <= 120")
    {
        BigInt x("120");
        BigInt y("120");

        REQUIRE(x <= y);
    }
    SUBCASE("120 <= 200")
    {
        BigInt x("120");
        BigInt y("200");

        REQUIRE(x <= y);
    }
}

TEST_CASE("BigInt: Greater or Equal")
{
    ostringstream sout;

    SUBCASE("-30 >= -30")
    {
        BigInt x("-30");
        BigInt y("-30");

        REQUIRE(x >= y);
    }
    SUBCASE("300 <= 50")
    {
        BigInt x("300");
        BigInt y("50");

        REQUIRE(x >= y);
    }
}

TEST_CASE("BigInt: Greater")
{
    ostringstream sout;
    SUBCASE("122 > 132")
    {
        BigInt x("122");
        BigInt y("132");

        REQUIRE(x < y);
    }
}

TEST_CASE("BigInt: Less")
{
    ostringstream sout;
    SUBCASE("122 < 400")
    {
        BigInt x("122");
        BigInt y("400");

        REQUIRE(x < y);
    }
}

TEST_CASE("operator>>")
{
    SUBCASE("130")
    {
        istringstream sinp("130");
        BigInt x;
        sinp >> x;
        REQUIRE(x == 130);

        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE(state);
    }
    SUBCASE("-130")
    {
        istringstream sinp("-130");
        BigInt x;
        sinp >> x;
        REQUIRE(x == -130);

        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE(state);
    }
    SUBCASE("   -130")
    {
        istringstream sinp("   -130");
        BigInt x;
        sinp >> x;
        REQUIRE(x == -130);

        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE(state);
    }
    SUBCASE("-")
    {
        istringstream sinp("-");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE_FALSE(state);
    }

    SUBCASE("- 125")
    {
        istringstream sinp("- 125");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE_FALSE(state);
    }

    SUBCASE("  x")
    {
        istringstream sinp("   x");
        BigInt x;
        sinp >> x;

        bool state = static_cast<bool>(sinp);
        REQUIRE_FALSE(state);
        sinp.clear();
        char ch;
        sinp >> ch;
        REQUIRE(ch == 'x');
    }
    SUBCASE("-")
    {
        istringstream sinp("-");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp);
        REQUIRE_FALSE(state);
    }
    SUBCASE("   ")
    {
        istringstream sinp("   ");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE_FALSE(state);
    }

    SUBCASE("130+123")
    {
        istringstream sinp("130+123");
        BigInt x;
        sinp >> x;
        REQUIRE(x == 130);
        string rest;
        getline(sinp, rest);
        bool state = static_cast<bool>(sinp); // (bool) sinp
        REQUIRE(state);
        REQUIRE(rest == "+123");
    }
    SUBCASE("1 + 2 + 3 + 4 + 5")
    {
        istringstream sinp("1 2 3 4 5");
        BigInt s = 0;
        for (BigInt x; sinp >> x;)
        {
            s.operator+=(x);
        }
        REQUIRE(s == 15);
        REQUIRE(sinp.eof());
    }
}

TEST_CASE("operator /")
{
    SUBCASE("1/2")
    {
        BigInt first(1);
        BigInt second(2);
        BigInt res = first / second;

        REQUIRE(res == 0);
    }

    SUBCASE("2/2")
    {
        BigInt first(2);
        BigInt second(2);
        BigInt res = first / second;

        REQUIRE(res == 1);
    }

    SUBCASE("45/2")
    {
        BigInt first(45);
        BigInt second(2);
        BigInt res = first / second;

        REQUIRE(res == 22);
    }

    SUBCASE("100/30")
    {
        BigInt first(100);
        BigInt second(30);
        BigInt res = first / second;

        REQUIRE(res == 3);
    }

    SUBCASE("100/2")
    {
        BigInt first(100);
        BigInt second(2);
        BigInt res = first / second;

        REQUIRE(res == 50);
    }
}