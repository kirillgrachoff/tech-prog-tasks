#include "main.h"
#include <gtest/gtest.h>
#include "C/functional_tests.cpp"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
