/*** 
    https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/#/description
***/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<unordered_map>
#include<map>
#include<list>
#include<forward_list>
#include<queue>
#include<algorithm>

using namespace std;

bool isValidSerialization(string);

int main(){

  /* For testing purpose. Comment this out when submit  */
  freopen("test.txt", "r", stdin);
  ios::sync_with_stdio(0);

  string preorder;

  cin >> preorder; 
  cout << isValidSerialization(preorder) << endl;
  return 0;
}

bool isValidSerialization(string preorder){

  // remove blank characters
  preorder.erase(remove(preorder.begin(),
			preorder.end(), ' '), preorder.end());
  
  // algo
  int current_pos = preorder.size() - 1;
  int num_erase = 0; 
  
  while(current_pos >= 0 ){
    if(preorder.at(current_pos) != '#' &&
       preorder.at(current_pos) != ',' &&
       preorder.size() - current_pos >= 5){

      num_erase = 4;      
      while (current_pos > 0){
	if(preorder.at(current_pos-1) == ',')
	  break;
	current_pos--;
	num_erase++;
      }
      
      preorder.erase(current_pos, num_erase) ;
    }
    current_pos--; 
  }

  if(preorder.compare("#") == 0) return true;  
  return false;
}
