#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

TEST_CASE("vector's default constructor") 
{
    vector<int> v;

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("vector's move constructor") 
{
    vector<int> v1 = {1, 2, 3, 4, 5};

    REQUIRE(v1.size() == 5);
    
    vector<int> v2 = move(v1);
    REQUIRE(v2.size() == 5);
    REQUIRE(v1.size() == 0);
    REQUIRE(v1.empty());
}   

TEST_CASE("vector's constructor with count copies") 
{
    vector<int> v(5);

    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 0);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    vector<string> v2(3);

    REQUIRE(v2[0] == "");
    REQUIRE(v2[1] == "");
    REQUIRE(v2[2] == "");

    vector<int> v3(3, 42);

    REQUIRE(v3[0] == 42);
    REQUIRE(v3[1] == 42);
    REQUIRE(v3[2] == 42); 
}

TEST_CASE("vector's copy constructor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = v;
    v[1] = 1000;

    REQUIRE(v2[0] != 1000);
    REQUIRE(v2[1] == 2);
} 

TEST_CASE("vector's assignment constructor")
{
    vector<int> v = {1, 2, 3};
    vector<int> v2 = v;

    v[0] = 10;
    v[1] = 20;

    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("vector's subscript operator")
{
    vector<int> v(5);

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
}

TEST_CASE("vector's method at(index) and it's exception") 
{
    vector<int> v(5);

    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    try
    {
        v.at(3) = 4;    
    }
    catch(out_of_range& e)
    {
        cout << "out of bounds" << '\n';
    }
    
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);

    try
    {
        v.at(5) = 4;    
    }
    catch(out_of_range& e)
    {
        cout << "out of bounds" << '\n';
    }
} 

TEST_CASE("vector's push_back method") 
{
    vector<int> v;

    v.push_back(20);
    v.push_back(30);

    REQUIRE(v.size() == 2);
    REQUIRE(v.capacity() == 2);    
    REQUIRE(v[0] == 20);
    REQUIRE(v[1] == 30);
}

TEST_CASE("the work of for (auto element : container) statement with std::vector") 
{
    vector<int> v = {1, 2, 3, 4, 5};

    for(auto &e: v) {
        e++;
    }

    REQUIRE(v[0] == 2);    
    REQUIRE(v[1] == 3);
    REQUIRE(v[2] == 4);
    REQUIRE(v[3] == 5);
    REQUIRE(v[4] == 6);
}

TEST_CASE("the work of std::reverse algorithm with std::vector") 
{
    vector<int> v = {1, 2, 3, 4, 5};

    reverse(v.begin(), v.end());

    REQUIRE(v[0] == 5);    
    REQUIRE(v[1] == 4);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 2);
    REQUIRE(v[4] == 1);

    reverse(v.begin(), v.end());

    REQUIRE(v[0] == 1);    
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
    REQUIRE(v[4] == 5);
}

TEST_CASE("the work of std::sort algorithm with std::vector")
{
    vector<int> v = {1, 2, 3, 4, 5};

    reverse(v.begin(), v.end());

    REQUIRE(v[0] == 5);    
    REQUIRE(v[1] == 4);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 2);
    REQUIRE(v[4] == 1);

    sort(v.begin(), v.end());

    REQUIRE(v[0] == 1);    
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
    REQUIRE(v[4] == 5);           
} 

TEST_CASE("the work of std::binary_search algorithm with std::vector") 
{
    vector<int> v = {2, 1, 4, 5, 3};

    sort(v.begin(), v.end());
    
    REQUIRE(binary_search(v.begin(), v.end(), 5));

    vector<int> v2 = {2, 1, 4, 5, 3, 6, 8, 7, 10, 9};

    sort(v2.begin(), v2.end());

    REQUIRE(binary_search(v2.begin(), v2.end(), 1));
}

TEST_CASE("the work of std::min_element algorithm with std::vector") 
{
    vector<int> v = {2, 1, 4, 5, 3};

    vector<int>::iterator it = min_element(v.begin(), v.end());

    REQUIRE(*it == 1);

    vector<int> v2 = { 0, 1000, 4896, 321654, 5};

    vector<int>::iterator it2 = min_element(v2.begin(), v2.end());

    REQUIRE(*it2 == 0);

    vector<int> v3 = { 1000, 4896, 3 , 321654, 5};

    vector<int>::iterator it3 = min_element(v3.begin(), v3.end());

    REQUIRE(*it3 == 3);
}
