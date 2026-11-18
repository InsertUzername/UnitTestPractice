/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

TEST(PasswordTest, single_letter_password)
{
    Password p;
    ASSERT_EQ(1, p.count_leading_characters("Zaaaaaaaaaaz"));
}

TEST(PasswordTest, multiple_letter_password)
{
    Password p;
    ASSERT_EQ(10, p.count_leading_characters("ZZZZZZZZZZz"));
}

TEST(PasswordTest, no_leading_password)
{
    Password p;
    ASSERT_EQ(0, p.count_leading_characters(""));
}

TEST(PasswordTest, leading_all_same)
{
    Password p;
    ASSERT_EQ(4, p.count_leading_characters("aaaa"));
}

TEST(PasswordTest, leading_later_runs_ignored)
{
    Password p;
    ASSERT_EQ(2, p.count_leading_characters("aabaaaa"));
}

TEST(PasswordTest, leading_case_sensitive)
{
    Password p;
    ASSERT_EQ(2, p.count_leading_characters("zzZZZ"));
}

TEST(PasswordTest, mixed_case_password)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("Zaaaaaaaaaaz"));
}

TEST(PasswordTest, mixed_lower_first)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("aZ"));
}

TEST(PasswordTest, mixed_upper_only_at_end)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("abcdefgH"));
}

TEST(PasswordTest, mixed_lower_only_at_end)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("ABCDEFGh"));
}

TEST(PasswordTest, mixed_with_digits_and_symbols)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("1a!B2"));
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

TEST(PasswordTest, mixed_upper_with_non_letters)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("A1!"));
}

TEST(PasswordTest, mixed_lower_with_non_letters)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("a1!"));
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