#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::Return;
using ::testing::_;

TEST_F(WeatherTestCase, diff_cities_test) {
    WeatherMock w;
    w.SetApiKey("ApiKey");
    EXPECT_CALL(w, GetTemperature("A")).Times(1).WillOnce(Return(10));
    EXPECT_CALL(w, GetTemperature("B")).Times(1).WillOnce(Return(10));
    EXPECT_EQ(w.FindDiffBetweenTwoCities("A", "B"), 0);
}

bool exists(std::string pattern, std::string source) {
    return source.find(pattern) != source.npos;
}

TEST_F(WeatherTestCase, tomorrow_diff_test) {
    WeatherMock w;
    EXPECT_CALL(w, GetTemperature("A"))
    .Times(7)
    .WillRepeatedly(Return(10));
    EXPECT_CALL(w, GetTomorrowTemperature("A"))
    .Times(7)
    .WillOnce(Return(15))
    .WillOnce(Return(11))
    .WillOnce(Return(10.1))
    .WillOnce(Return(10))
    .WillOnce(Return(9.9))
    .WillOnce(Return(9))
    .WillOnce(Return(5));
    EXPECT_TRUE(exists("be much warmer", w.GetTomorrowDiff("A")));
    EXPECT_TRUE(exists("be warmer", w.GetTomorrowDiff("A")));
    EXPECT_TRUE(exists("be the same", w.GetTomorrowDiff("A")));
    EXPECT_TRUE(exists("be the same", w.GetTomorrowDiff("A")));
    EXPECT_TRUE(exists("be the same", w.GetTomorrowDiff("A")));
    EXPECT_TRUE(exists("be colder", w.GetTomorrowDiff("A")));
    EXPECT_TRUE(exists("be much colder", w.GetTomorrowDiff("A")));
}

TEST_F(WeatherTestCase, difference_string) {
    WeatherMock w;
    EXPECT_CALL(w, GetTemperature("A"))
    .Times(2)
    .WillOnce(Return(10))
    .WillOnce(Return(10));
    EXPECT_CALL(w, GetTemperature("B"))
    .Times(2)
    .WillOnce(Return(11))
    .WillOnce(Return(9));
    EXPECT_EQ(w.GetDifferenceString("A", "B"), "Weather in A is colder than in B by 1 degrees");
    EXPECT_EQ(w.GetDifferenceString("A", "B"), "Weather in A is warmer than in B by 1 degrees");
}

TEST_F(WeatherTestCase, exceptions) {
    WeatherMock w;
    w.SetApiKey("ApiKey");
    EXPECT_ANY_THROW(w.GetResponseForCity("London", cpr::Url{"http://api.openweathermap.org/data/2.5/forecast"}));
}

TEST_F(WeatherTestCase, response_for_city) {
    Weather w;
    w.SetApiKey("SuperMegaApiKey57");
    EXPECT_ANY_THROW(w.GetTomorrowTemperature("London"));
    EXPECT_ANY_THROW(w.GetTemperature("London"));
}
