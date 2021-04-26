#include "C/main.h"
#include "A/index.h"
#include <gtest/gtest.h>
#include <vector>
#include <random>

std::vector<std::string> randomNames() {
    std::vector<std::string> ans(10);
    std::random_device rand;
    for (auto& s : ans) {
        int len = rand() % 1000;
        for (int i = 0; i < len; ++i) {
            s.push_back('a' + rand() % 15);
        }
    }
    return ans;
}

TEST(greeting, benchmarks) {
    std::vector<std::string> names = randomNames();
    for (int i = 0; i < 1000; ++i) {
        Greeter g;
        int idx = i % names.size();
        ASSERT_TRUE(g.greet(names[idx]) == "Hello, " + names[idx] + "!");
    }
}

TEST(index_file, manual) {
    ASSERT_TRUE(checkIfCorrect());
}
