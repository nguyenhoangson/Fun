/*** 
     Link: https://www.hackerrank.com/challenges/abbr
***/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;

int transform_str(string, string);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

  int q;
  string a, b;
  int result;
  
  // read input from file
  freopen("test.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> a >> b;
    result = transform_str(a, b);
    
    if(result == 0) cout << "NO" << endl;

    else cout << "YES" << endl;
    
  }

}

int transform_str(string source, string target){

  int source_size = source.size();
  int target_size = target.size();
  int result[source_size][target_size];
  int is_all_lower_case_so_far = 0;
  
  // initialize row 0 of the result array
  for(int k = 0; k < target_size; k++){
    if(k == 0){
      if(toupper(source[0]) == target[0]) result[0][0] = 1;
      else result[0][0] = 0;
    }
    else{
      result[0][k] = 0;
    }
  }

  // initialize column 0 of the result array
  is_all_lower_case_so_far = ~ isupper(source[0]);
  for(int t = 1; t < source_size; t++){
    if(isupper(source[t])){
      if(source[t] == target[0]) result[t][0] = is_all_lower_case_so_far;
      else result[t][0] = 0;
    }
    else{
      if(toupper(source[t]) == target[0]) result[t][0] = is_all_lower_case_so_far;
      else{
	result[t][0] = result[t-1][0];
      }
    }
  }
    
  for(int i = 1; i < source_size; i++){
    for(int j = 1; j < target_size; j++){
      if(isupper(source[i])){

	if(source[i] == target[j]) result[i][j] = result[i-1][j-1];
  	else result[i][j] = 0;
	
      }
      else{
	
  	if(toupper(source[i]) == target[j])
	  result[i][j] = (result[i-1][j] || result[i-1][j-1]);
	else result[i][j] = result[i-1][j];
	
      }
    }
  }
   
  return result[source_size-1][target_size-1];
}
