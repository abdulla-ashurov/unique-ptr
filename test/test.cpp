#include "catch_amalgamated.hpp"
#include "../include/shared_ptr.hpp"
// #include "../include/weak_ptr.hpp"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////// shared_ptr tests /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_CASE("Test shared_ptr default constructor")
{
    SECTION("Test shared_ptr<int> default constructor")
    {
        shared_ptr<int> ptr;
        REQUIRE(ptr.get() == nullptr);
    }

    SECTION("Test shared_ptr<std::string> default constructor")
    {
        shared_ptr<std::string> ptr;
        REQUIRE(ptr.get() == nullptr);
    }

    // Add test for testing own class.
}

TEST_CASE("Test shared_ptr(const T object) constructor")
{
    SECTION("Test shared_ptr<int>(const T object) constructor")
    {
        int expected_value = 5;
        shared_ptr<int> ptr(expected_value);
        REQUIRE(*ptr == expected_value);
    }

    SECTION("Test shared_ptr<std::string>(const T object) constructor")
    {
        std::string expected_value("hello world");
        shared_ptr<std::string> ptr(expected_value);
        REQUIRE(*ptr == expected_value);
    }

    // Add test for testing own class.
}

TEST_CASE("Test shared_ptr copy constructor")
{
    SECTION("Test shared_ptr<int> copy constructor")
    {
        int expected_value = 5;
        shared_ptr<int> first_ptr(expected_value);

        shared_ptr<int> second_ptr(first_ptr);
        REQUIRE(*second_ptr == expected_value);
    }

    SECTION("Test shared_ptr<std::string> copy constructor")
    {
        std::string expected_value("hello world");
        shared_ptr<std::string> first_ptr(expected_value);

        shared_ptr<std::string> second_ptr(first_ptr);
        REQUIRE(*second_ptr == expected_value);
    }

    // Add test for testing own class.
}

TEST_CASE("Test shared_ptr operator=")
{
    SECTION("Test shared_ptr<int> operator=")
    {
        int expected_value = 5;
        shared_ptr<int> first_ptr(expected_value);
        shared_ptr<int> second_ptr;

        second_ptr = first_ptr;
        REQUIRE(*second_ptr == expected_value);
    }

    SECTION("Test shared_ptr<std::string> operator=")
    {
        std::string expected_value("hello world");
        shared_ptr<std::string> first_ptr(expected_value);
        shared_ptr<std::string> second_ptr;

        second_ptr = first_ptr;
        REQUIRE(*second_ptr == expected_value);
    }

    // Add test for testing own class.
}

TEST_CASE("Test shared_ptr with shared ownership")
{
    SECTION("Test shared_ptr<int> with shared ownership")
    {
        shared_ptr<int> *base_ptr = new shared_ptr<int>(5);
        REQUIRE(base_ptr->use_count() == 1);
        {
            shared_ptr<int> second_ptr(*base_ptr);
            REQUIRE(base_ptr->use_count() == 2);
            {
                shared_ptr<int> third_ptr(second_ptr);
                REQUIRE(base_ptr->use_count() == 3);
            }
            REQUIRE(base_ptr->use_count() == 2);
        }
        REQUIRE(base_ptr->use_count() == 1);

        delete base_ptr;
    }

    SECTION("Test shared_ptr<std::string> with shared ownership")
    {
        shared_ptr<std::string> *base_ptr = new shared_ptr<std::string>(std::string("hello world"));
        REQUIRE(base_ptr->use_count() == 1);
        {
            shared_ptr<std::string> second_ptr(*base_ptr);
            REQUIRE(base_ptr->use_count() == 2);
            {
                shared_ptr<std::string> third_ptr(second_ptr);
                REQUIRE(base_ptr->use_count() == 3);
            }
            REQUIRE(base_ptr->use_count() == 2);
        }
        REQUIRE(base_ptr->use_count() == 1);

        delete base_ptr;
    }

    // Add test for testing own class.
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////// weak_ptr tests /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// TEST_CASE("Test weak_ptr default constructor") {
//     SECTION("Test weak_ptr<int> default constructor") {
//         weak_ptr<int> ptr;
//         REQUIRE(ptr.expired() == true);
//         REQUIRE(ptr.use_count() == 0);
//     }

//     SECTION("Test weak_ptr<std::string> default constructor") {
//         weak_ptr<std::string> ptr;
//         REQUIRE(ptr.expired() == true);
//         REQUIRE(ptr.use_count() == 0);
//     }
// }

// TEST_CASE("Test weak_ptr(const shared_ptr<T> object) constructor") {
//     SECTION("Test weak_ptr<int> constructor shared_ptr<T> parameter") {
//         shared_ptr<int> sh_ptr;
//         weak_ptr<int> w_ptr(sh_ptr);
//         REQUIRE(w_ptr.expired() == false);
//         REQUIRE(w_ptr.use_count() == 1);
//     }

//     SECTION("Test weak_ptr<std::string> constructor shared_ptr<T> parameter") {
//         shared_ptr<std::string> sh_ptr;
//         weak_ptr<std::string> w_ptr(sh_ptr);
//         REQUIRE(w_ptr.expired() == false);
//         REQUIRE(w_ptr.use_count() == 1);
//     }
// }

// TEST_CASE("Test weak_ptr copy constructor") {
//     SECTION("Test weak_ptr<int> copy constructor") {
//         shared_ptr<int> sh_ptr(5);
//         weak_ptr<int> first_ptr(sh_ptr);
//         weak_ptr<int> second_ptr(first_ptr);

//         REQUIRE(second_ptr.expired() == false);
//         REQUIRE(second_ptr.use_count() == 1);
//     }

//     SECTION("Test weak_ptr<std::string> copy constructor") {
//         shared_ptr<std::string> sh_ptr(std::string("Hello world"));
//         weak_ptr<std::string> first_ptr(sh_ptr);
//         weak_ptr<std::string> second_ptr(first_ptr);

//         REQUIRE(second_ptr.expired() == false);
//         REQUIRE(second_ptr.use_count() == 1);
//     }
// }

// TEST_CASE("Test weak_ptr lock method") {
//     SECTION("Test weak_ptr<int> lock method") {
//         shared_ptr<int> sh_ptr(5);
//         weak_ptr<int> w_ptr(sh_ptr);

//         shared_ptr<int> sh_ptr2 = w_ptr.lock();
//         REQUIRE(*sh_ptr2 == 5);
//         REQUIRE(sh_ptr2.use_count() == 2);
//     }

//     SECTION("Test weak_ptr<std::string> lock method") {
//         shared_ptr<std::string> sh_ptr(std::string("hello"));
//         weak_ptr<std::string> w_ptr(sh_ptr);

//         shared_ptr<std::string> sh_ptr2 = w_ptr.lock();
//         REQUIRE(*sh_ptr2 == "hello");
//         REQUIRE(sh_ptr2.use_count() == 2);
//     }
// }