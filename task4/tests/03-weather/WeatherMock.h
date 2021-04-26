#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
public:
    MOCK_METHOD(float, GetTemperature, (const std::string&), ());
    MOCK_METHOD(float, GetTomorrowTemperature, (const std::string&), ());
};



