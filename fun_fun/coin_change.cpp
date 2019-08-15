/***
    Link: https://www.hackerrank.com/challenges/coin-change
***/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solve(int *, int , int );

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

  // read input from file
  // freopen("test.txt", "r", stdin);
  ios::sync_with_stdio(0);

  int N, M;

  cin >> N >> M;

  int C[M];
  for(int i = 0; i < M; i++){
    cin >> C[i];
  }

  cout << solve(C, M, N )<< endl;
  return 0;
}

long long solve(int *C, int M, int N){
  long long result = 0;
  long long arr[N+1][M];
  
  // solve when i = 1
  int signal = 0; 
  for(int k = 0; k < M; k++){
    if(C[k] == 1){
      signal = 1;
    }
    
    if(signal){
      arr[1][k] = 1;
    }
    else{
      arr[1][k] = 0;
    }
    
  }

  // solve when M = 1
  for(int k = 1; k < N+1; k++){
    if(k % C[0] == 0){
      arr[k][0] = 1;
    }
    else{
      arr[k][0] = 0;
    }
  }
  
  for(int i = 2; i <= N; i++){
    for(int j = 1; j < M; j++){
      if(i <= C[j]){
	if(i == C[j])
	  arr[i][j] = 1 + arr[i][j-1];
	else
	  arr[i][j] = arr[i][j-1];
      }
      else
	arr[i][j] = arr[i-C[j]][j] + arr[i][j-1];
    }
  }

  result = arr[N][M-1];
  return result; 
}
