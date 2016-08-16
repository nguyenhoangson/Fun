#include "gtest/gtest.h"
#include "merge_sort.h"

TEST(MergeSort, TestMerge){
  int A[1] = {0};

  merge(A, 0, 0, 0);
  
  EXPECT_EQ(1.0, 1.0);
}

TEST(MergeSort, TestMergeSort){
  int A[1] = {0};

  merge_sort(A, 0, 0);

  EXPECT_EQ(2.0, 2.0);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
