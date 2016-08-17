#include "gtest/gtest.h"
#include "quick_sort.h"

// custom test
::testing::AssertionResult ArrayMatch(int *, int *, int);

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
  int A[7] = {3, 7, 8, 5, 4, 9, 6};
  int B[9] = {1, 8, 9, 6, 5, 4, 2, 3, 7};
  int EXPECTED_A[7] = {3, 4, 5, 6, 7, 8, 9};
  int EXPECTED_B[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  quick_sort(A, 0, 6);
  quick_sort(B, 0, 8);
  
  EXPECT_TRUE(ArrayMatch(EXPECTED_A, A, 7));
  EXPECT_TRUE(ArrayMatch(EXPECTED_B, B, 9));
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// custom test
::testing::AssertionResult ArrayMatch(int *expected,
				      int *actual, int size){

  for(int i = 0; i < size; i++){
    if(*(expected+i) != *(actual+i)){
      return ::testing::AssertionFailure() << i << "th element: (" << *(expected+i)
					   << " vs " << *(actual+i) << ")"  << " does not match";
    }
  }
  
  return ::testing::AssertionSuccess();
}
