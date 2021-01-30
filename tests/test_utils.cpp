#include <gtest/gtest.h>

#include "libs/utils.h"

TEST(TestUtils, SumTest) {
    EXPECT_EQ(2, Sum(1,1));
}