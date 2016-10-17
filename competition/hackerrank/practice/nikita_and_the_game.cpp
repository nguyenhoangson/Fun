/*** 
     Link: https://www.hackerrank.com/challenges/array-splitting
***/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_max_score(int *, int, int);
int find_t(int *, int, int);
int max(int , int);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  int T, N;
  int A[100000];
  
  freopen("test1.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> N;
    for(int j = 0; j < N; j++){
      cin >> A[j];
    }
    cout << find_max_score(A, 0, N-1) << "\n";
  }
  
  return 0;
}

int find_max_score(int *Arr, int p, int q){
  int final_result = 0;
  int t;
  
  if( p < q){
    t = find_t(Arr, p, q);
    if(t == -1)
      final_result = 0;
    else{
      final_result = 1 + max(find_max_score(Arr, p, t),
			     find_max_score(Arr, t+1, q));
    }
   
  }
  
  return final_result; 
}

int find_t(int *Arr, int i, int j){
  int result = -1;
  long long tmp = Arr[i];
  long long sum = 0;
  long long target;
  
  for(int t = i; t <= j; t++){
    sum += Arr[t];
  }

  if(sum % 2 == 1) return -1;

  target = sum/2;
  
  for(int k = i + 1; k <= j; k++){
    if(tmp == (target)){
      result = k-1;
      break;
    }
    
    tmp += Arr[k];
  }
  
  return result;
}

int max(int a, int b){
  if(a < b)
    return b;
  return a;
}
