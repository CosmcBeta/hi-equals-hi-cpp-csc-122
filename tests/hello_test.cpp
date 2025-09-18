#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "it returns Hello World" ) {
    REQUIRE(strcmp_case_insensitive("Hello", "hello") == 0);
    REQUIRE(strcmp_case_insensitive("WORLD", "world") == 0);
    REQUIRE(strcmp_case_insensitive("CaseInSensitive", "caseinsensitive") == 0);
    REQUIRE(strcmp_case_insensitive("apple", "banana") < 0);
    REQUIRE(strcmp_case_insensitive("abc", "abd") < 0);
    REQUIRE(strcmp_case_insensitive("cat", "caterpillar") < 0);
    REQUIRE(strcmp_case_insensitive("a", "B") > 0);
    REQUIRE(strcmp_case_insensitive("zebra", "apple") > 0);
    REQUIRE(strcmp_case_insensitive("dog", "cat") > 0);
    REQUIRE(strcmp_case_insensitive("caterpillar", "cat") > 0);
    REQUIRE(strcmp_case_insensitive("B", "a") < 0);
    REQUIRE(strcmp_case_insensitive("123", "124") < 0);
    REQUIRE(strcmp_case_insensitive("99", "100") > 0);
    REQUIRE(strcmp_case_insensitive("!abc", "abc") < 0);
    REQUIRE(strcmp_case_insensitive("", "") == 0);
    REQUIRE(strcmp_case_insensitive("", "nonempty") < 0);
    REQUIRE(strcmp_case_insensitive("nonempty", "") > 0);
    REQUIRE(strcmp_case_insensitive("AbC", "aBc") == 0);
    REQUIRE(strcmp_case_insensitive("Catch2", "catch3") < 0);
    REQUIRE(strcmp_case_insensitive("catch3", "catch2") > 0);

    // skipping spaces
    REQUIRE(strcmp_case_insensitive("a b c", "abc") != 0);
    REQUIRE(strcmp_case_insensitive("Hello World", "HelloWorld") != 0);
    REQUIRE(strcmp_case_insensitive(" spaced", "spaced") != 0);
    REQUIRE(strcmp_case_insensitive("a b c", "abc", true) == 0);
    REQUIRE(strcmp_case_insensitive("Hello World", "helloworld", true) == 0);
    REQUIRE(strcmp_case_insensitive(" spaced", "spaced", true) == 0);
    REQUIRE(strcmp_case_insensitive("space d", "sp aced", true) == 0);
    REQUIRE(strcmp_case_insensitive(" multiple   spaces", "multiplespaces", true) == 0);
    REQUIRE(strcmp_case_insensitive("a c", "ab", true) > 0);
    REQUIRE(strcmp_case_insensitive("ab", "a c", true) < 0);
    REQUIRE(strcmp_case_insensitive("C a T", "cat", true) == 0);
    REQUIRE(strcmp_case_insensitive("Dog House", "doghouse", true) == 0);
    REQUIRE(strcmp_case_insensitive("Dog House", "doghousf", true) < 0);
    REQUIRE(strcmp_case_insensitive("   ", "", true) == 0);
    REQUIRE(strcmp_case_insensitive("", "   ", true) == 0);
    REQUIRE(strcmp_case_insensitive("a", " ", true) > 0);
    REQUIRE(strcmp_case_insensitive(" ", "a", true) < 0);

    // including character limit
    REQUIRE(strcmp_case_insensitive("HelloWorld", "helloworld", false, -1) == 0);
    REQUIRE(strcmp_case_insensitive("HelloWorld", "HELium", false, 3) == 0);
    REQUIRE(strcmp_case_insensitive("HelloWorld", "HELium", false, 4) > 0);
    REQUIRE(strcmp_case_insensitive("abc", "xyz", false, 0) == 0);
    REQUIRE(strcmp_case_insensitive("cat", "dog", false, -5) < 0);
    REQUIRE(strcmp_case_insensitive("cat", "dog", false, 2) < 0);
    REQUIRE(strcmp_case_insensitive("a b c d", "abcdz", true, 5) < 0);
    REQUIRE(strcmp_case_insensitive("H e l lo", "HELx", true, 3) == 0);

    
}