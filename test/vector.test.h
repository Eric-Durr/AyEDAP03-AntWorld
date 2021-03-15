#include "../include/Catch2/catch.h"
#include "../include/vector.h"

SCENARIO("Any kind of custom vector can be created")
{
  GIVEN("A vector of integers with positive boundries")
  {
    CustomVector<int> positive_v(0, 20);
    REQUIRE(positive_v.size() == 20);
    REQUIRE(positive_v.low_boundry() == 0);
    REQUIRE(positive_v.top_boundry() == 20);
    WHEN("Accessed to legal positions")
    {
      THEN("Value returned is the default (0)")
      {
        int value1 = positive_v.at(10);
        int value2 = positive_v[5];
        CHECK(value1 == 0);
        CHECK(value2 == 0);
      }
      AND_THEN("Data can be modified")
      {
        positive_v.at(10) = 5;
        positive_v[5] = 1;
        int value1 = positive_v.at(10);
        int value2 = positive_v[5];
        CHECK(value1 == 5);
        CHECK(value2 == 1);
      }
      AND_THEN("Vector can be outputed")
      {
        CHECK(positive_v.to_string() ==
              "[ (0|0) (0|1) (0|2) (0|3) (0|4) (0|5) (0|6)"
              " (0|7) (0|8) (0|9) (0|10) (0|11) (0|12) (0|13)"
              " (0|14) (0|15) (0|16) (0|17) (0|18) (0|19) ]");
      }
    }
  }
  GIVEN("A vector of integers with positive and negative boundries")
  {
    CustomVector<int> positive_v(-10, 20);
    REQUIRE(positive_v.size() == 30);
    REQUIRE(positive_v.low_boundry() == -10);
    REQUIRE(positive_v.top_boundry() == 20);
    WHEN("Accessed to legal positions")
    {
      THEN("Value returned is the default (0)")
      {
        int value1 = positive_v.at(-5);
        int value2 = positive_v[4];
        CHECK(value1 == 0);
        CHECK(value2 == 0);
      }
      AND_THEN("Data can be modified")
      {
        positive_v.at(-5) = 5;
        positive_v[5] = 1;
        int value1 = positive_v.at(-5);
        int value2 = positive_v[5];
        CHECK(value1 == 5);
        CHECK(value2 == 1);
      }
      AND_THEN("Vector can be outputed")
      {
        CHECK(positive_v.to_string() ==
              "[ (0|-10) (0|-9) (0|-8) (0|-7) (0|-6) (0|-5) (0|-4)"
              " (0|-3) (0|-2) (0|-1) (0|0) (0|1) (0|2) (0|3) (0|4)"
              " (0|5) (0|6) (0|7) (0|8) (0|9) (0|10) (0|11) (0|12)"
              " (0|13) (0|14) (0|15) (0|16) (0|17) (0|18) (0|19) ]");
      }
    }
  }
}