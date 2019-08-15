/***
Link: https://www.hackerrank.com/challenges/red-john-is-back
***/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int solve(int);
int num_primes(int);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  freopen("test1.txt", "r", stdin);
  ios::sync_with_stdio(0);
  int T, N;
  cin >> T;
  for(int i = 0; i < T; i++){
    cin >> N;
    cout << solve(N) << endl;
  }

  return 0;
}

int solve(int N){
  int result;
  int DP[N+1];
  
  // find the number of configurations
  for(int i = 0; i < N+1; i++){
    if(i < 4){
      DP[i] = 1; 
    }
    else{
      DP[i] = DP[i-4] + DP[i-1]; 
    }
  }

  
  result = num_primes(DP[N]);
  return result;
}

int num_primes(int M){
  int result = 0;
  vector<int> primes;
  int len_vec = 0;
  int is_prime = 1;
  int temp = 0;
  
  if(M == 1) return 0;
  if(M >= 2) primes.push_back(2);
  len_vec = 1;
  
  for(int i = 3; i <= M; i++){
    is_prime = 1;
    temp = floor(sqrt(i));
    for(int j = 0; j < len_vec; j++){
      if(primes[j] <= temp){
	if(i % primes[j] == 0){
	  is_prime = 0;
	  break;
	}
      }
      else break;
    }
    
    if(is_prime){
      primes.push_back(i);
      len_vec++;
    }
     
  }
  
  result = len_vec;
  return result;
}

