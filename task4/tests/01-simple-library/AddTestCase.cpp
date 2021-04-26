#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, some_test) {
    for (int i = -10; i <= 10; ++i) {
        for (int j = -10; j <= 10; ++j) {
            EXPECT_EQ(Add(i, j), i + j);
        }
    }
    EXPECT_EQ(Add(std::numeric_limits<int>::max(), std::numeric_limits<int>::min()), -1);
}
