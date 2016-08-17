#include "gtest/gtest.h"
#include "quick_sort.h"

TEST(QuickSort, TestPartition){
  int A[7] = {3, 7, 8, 5, 4, 9, 6};
  int B[7] = {3, 7, 8, 5, 4, 9, 6};
  int C[9] = {1, 8, 9, 6, 5, 4, 2, 3, 7};
  int D[9] = {1, 8, 9, 6, 5, 4, 2, 3, 7};
  
  EXPECT_EQ(3, partition(A, 0, 6));
  EXPECT_EQ(5, partition(B, 2, 5));
  EXPECT_EQ(6, partition(C, 0, 8));
  EXPECT_EQ(4, partition(D, 3, 7));
  EXPECT_EQ(6, partition(D, 6, 6));
}

TEST(QuickSort, TestQuickSort){
  EXPECT_EQ(1.0, 1.0);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
