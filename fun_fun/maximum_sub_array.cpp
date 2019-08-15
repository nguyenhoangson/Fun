/***  
      Link: https://www.hackerrank.com/challenges/maxsubarray
***/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_contiguous_max(int *, int);
int find_non_contiguous_max(int *, int);

int main() {

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T, N;
  int A[100000]; 
  
  // read input from file for testing purpose
  freopen("test1.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> N;
    for(int j = 0; j < N; j++){
      cin >> A[j]; 
    }
    cout << find_contiguous_max(A, N) << " " << find_non_contiguous_max(A, N);
    cout << "\n";
  }
  
  return 0;
}


int find_contiguous_max(int *A, int N){
  int final_result; 
  int current_result = A[0];
  int max_end_here = A[0];

  // code
  for(int i = 1; i < N; i++){
    
    if(max_end_here <= 0){
      max_end_here = A[i]; 
    }
    else{
      max_end_here += A[i];
    }

    if(max_end_here  > current_result){
      current_result = max_end_here; 
    }
    
  }

  final_result = current_result; 
  return final_result;
}


int find_non_contiguous_max(int *A, int N){
  int final_result;
  int max = A[0];
  int current_result = A[0];
  
  /* Code */

  // find max of array 
  for(int i = 1; i < N; i++){
    if(A[i] > max)
      max = A[i];
  }

  for(int j = 1; j < N; j++){
    if(A[j] > 0)
      current_result += A[j];
  }

  if(current_result == A[0]){
    if(current_result < 0)
      current_result = max;
  }
  else{
    if(A[0] <= 0)
      current_result -= A[0];
  }

  final_result = current_result;
  
  return final_result;
}
