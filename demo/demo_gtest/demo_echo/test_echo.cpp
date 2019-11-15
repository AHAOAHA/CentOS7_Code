#include <gtest/gtest.h>

extern void echo();

TEST(testcase, demo2) {
    echo();
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
