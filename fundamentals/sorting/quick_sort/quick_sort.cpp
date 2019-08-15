/*** 
     Quick sort implementation 
***/
#include "quick_sort.h"

/* This will return an index p such that
   A[k] <= A[p]; for all k;  left <= k < p
   A[k] >= A[p]; for all k;  p < k <= right
*/
int partition(int *A, int left, int right){
  /*TODO: fill in code here*/
  
  /* The main idea is that 
     we set the last (A[right]) element as pivot 
     (last or first does not matter), we then maintain 
     the following loop invariant: 
     1. A[k] <= pivot; for all k;  left <= k <= i
     2. A[k] > pivot; for all k;  i < k <= j
   */
  int pivot = *(A+right);
  int i = left - 1;
  int temp = 0;
  
  for(int j = left; j < right; j++){
    if(A[j] <= pivot){
      // swap A[i+1] with A[j]
      temp = *(A+i+1);
      *(A+i+1) = *(A+j);
      *(A+j) = temp;
      
      i++; 
    }
  }

  // swap A[i+1] with A[right]
  temp = *(A+i+1);
  *(A+i+1) = *(A+right);
  *(A+right) = temp;
  
  return i+1;
}

void quick_sort(int *A, int left, int right){
  /* TODO: fill in code here */

  int q = 0;
  
  if(left <= right){
    q = partition(A, left, right);
    quick_sort(A, left, q-1);
    quick_sort(A, q+1, right);
  }
  
  return;
}
