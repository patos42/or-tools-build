#include <gtest/gtest.h>
#include "ortools/sat/cp_model.h"

TEST(simpleexample, add)
{
    operations_research::sat::CpModelBuilder cp_model;
    GTEST_ASSERT_EQ(10+22, 32);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}