#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>

class TreeTestCase : public ::testing::Test {
    boost::filesystem::path testDirLocation;
public:
    boost::filesystem::path& TestDirLocation();
    void SetUp() override;
    void TearDown() override;
};
