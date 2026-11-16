/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zaaaaaaaaaaz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multiple_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZZZZZZZz");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, no_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Zaaaaaaaaaaz");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixed_case_all_lowercase)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("abcdef"));
}

TEST(PasswordTest, mixed_case_all_uppercase)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("ABCDEF"));
}

TEST(PasswordTest, mixed_case_no_letters)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("12345!@#"));
}

TEST(PasswordTest, mixed_case_empty_string)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case(""));
}