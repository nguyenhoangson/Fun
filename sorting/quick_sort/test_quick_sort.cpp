#include "gtest/gtest.h"
#include "quick_sort.h"

TEST(QuickSort, TestPartition){
  int A[1] = {1};
  
  EXPECT_EQ(1, partition(A, 0, 0));
}

TEST(QuickSort, TestQuickSort){
  EXPECT_EQ(1.0, 1.0);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
