#include "LeapTestCase.h"
#include <Functions.h>
#include <random>
#include <cmath>

/*
 *  The year is evenly divisible by 4;
 *  If the year can be evenly divided by 100, it is NOT a leap year, unless;
 *  The year is also evenly divisible by 400: Then it is a leap year.
 */

bool isLeapChecker(int n) {
    return (n % 400 == 0) || (n % 4 == 0 && n % 100);
}

TEST_F(LeapTestCase, leap_year_tests) {
    std::random_device rand;
    for (int i = 1; i <= 400; ++i) {
        EXPECT_EQ(IsLeap(i), isLeapChecker(i));
    }
    EXPECT_ANY_THROW(IsLeap(0));
    EXPECT_ANY_THROW(IsLeap(-5));
}

TEST_F(LeapTestCase, days_in_month) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int year = 1; year <= 400; ++year) {
        for (int month = 0; month < 12; ++month) {
            EXPECT_EQ(GetMonthDays(year, month + 1), days[month] + isLeapChecker(year) * (month == 1));
        }
    }
}

TEST_F(LeapTestCase, days_in_month_exceptions) {
    EXPECT_ANY_THROW(GetMonthDays(-1, 2));
    EXPECT_ANY_THROW(GetMonthDays(10, 13));
    EXPECT_ANY_THROW(GetMonthDays(10, -5));
}
