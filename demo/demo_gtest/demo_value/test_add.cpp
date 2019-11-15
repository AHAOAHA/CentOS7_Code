#include <gtest/gtest.h>

extern int add(int, int);

TEST(testcase, demo1) {
    // 比对add(3, 2)的结果是否为5
    EXPECT_EQ(add(3, 2), 5);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}