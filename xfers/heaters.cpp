/*** 
     https://leetcode.com/problems/heaters/#/description
***/

#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<cstdio>

using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters);

int main(){

  // read input from file
  freopen("test.txt", "r", stdin);
  ios::sync_with_stdio(0);

  int n, m;
  int a;
  vector<int> houses, heaters;
  
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    houses.push_back(a);
  }
  
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> a;
    heaters.push_back(a);
  }

  cout << findRadius(houses, heaters) << endl;
}

int findRadius(vector<int>& houses, vector<int>& heaters){
  int result = 0;
  int counter = 0;
  int num_houses = houses.size();
  int num_heaters = heaters.size();
  int nearest_heater;
  
  // Sort houses and heaters
  sort(houses.begin(), houses.end());
  sort(heaters.begin(), heaters.end());
  
  for(int i = 0; i < num_houses; i++){

    // Find the nearest heater for each house
    while(counter < num_heaters &&
	  heaters.at(counter) < houses.at(i)){
      counter++;
    }
    
    if(counter > 0 && counter < num_heaters)
      nearest_heater = min(abs(houses.at(i) - heaters.at(counter-1)), abs(houses.at(i) - heaters.at(counter))); 

    else if(counter == 0)
      nearest_heater = abs(houses.at(i) - heaters.at(counter));

    else if(counter == num_heaters)
      nearest_heater = abs(houses.at(i) - heaters.at(counter-1));
    
    result = max(nearest_heater, result);
    
  }
  return result;
}
