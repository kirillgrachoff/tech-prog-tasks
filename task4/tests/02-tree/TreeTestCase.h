#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>

class TreeTestCase : public ::testing::Test {
public:
    static boost::filesystem::path& TestDirLocation();
    static void SetUpTestCase();
    static void TearDownTestCase();
};


