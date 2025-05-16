#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "ManoVektorius.hpp"

TEST_CASE("Sanity check") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Default construction", "[ManoVektorius]") {
    ManoVektorius<int> v;
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
}

TEST_CASE("push_back and element access", "[ManoVektorius]") {
    ManoVektorius<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
    REQUIRE(v.front() == 10);
    REQUIRE(v.back() == 30);
}

TEST_CASE("at() bounds checking", "[ManoVektorius]") {
    ManoVektorius<int> v;
    v.push_back(5);
    REQUIRE(v.at(0) == 5);
    REQUIRE_THROWS_AS(v.at(1), std::out_of_range);
}

TEST_CASE("pop_back removes last element", "[ManoVektorius]") {
    ManoVektorius<int> v;
    v.push_back(42);
    v.pop_back();
    REQUIRE(v.size() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("insert and erase work correctly", "[ManoVektorius]") {
    ManoVektorius<int> v;
    v.push_back(1);
    v.push_back(3);
    v.insert(1, 2);  // now: 1, 2, 3
    REQUIRE(v.size() == 3);
    REQUIRE(v[1] == 2);

    v.erase(v.begin());  // remove 1, now: 2, 3
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 2);
}

TEST_CASE("resize increases and decreases size", "[ManoVektorius]") {
    ManoVektorius<int> v;
    v.resize(5, 99);
    REQUIRE(v.size() == 5);
    REQUIRE(v[4] == 99);

    v.resize(2);
    REQUIRE(v.size() == 2);
}

TEST_CASE("move constructor and assignment", "[ManoVektorius]") {
    ManoVektorius<int> v1;
    v1.push_back(7);

    ManoVektorius<int> v2(std::move(v1));
    REQUIRE(v2.size() == 1);
    REQUIRE(v2[0] == 7);

    ManoVektorius<int> v3;
    v3 = std::move(v2);
    REQUIRE(v3.size() == 1);
    REQUIRE(v3[0] == 7);
}

TEST_CASE("iterators work", "[ManoVektorius]") {
    ManoVektorius<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int sum = 0;
    for (auto x : v) sum += x;
    REQUIRE(sum == 6);
}
