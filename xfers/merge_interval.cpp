/*** 
   https://leetcode.com/problems/merge-intervals/#/description  
***/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<cstdio>

using namespace std;

struct Interval{
  int start;
  int end;
  Interval(): start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals);

bool operator < (Interval a, Interval b){
  return a.start < b.start;
}

int main(){

  // read input from file
  freopen("test.txt", "r", stdin);
  ios::sync_with_stdio(0);
  
  int n;
  int s, e; 
  vector<Interval> intervals;
  cin >> n; 
  for(int i = 0; i < n; i++){
    cin >> s;
    cin >> e;
    Interval t(s, e);
    intervals.push_back(t);
  }

  vector<Interval> result = merge(intervals);

  for(int i = 0; i < result.size(); i++){
    cout << "[" << result.at(i).start << "," << result.at(i).end << "]";
    cout << endl;
  }
}

vector<Interval> merge(vector<Interval>& intervals){

  int size = intervals.size();
  int counter = 0;
  vector<Interval> result;
  Interval temp;
  
  // Sort the intervals based on lower end
  sort(intervals.begin(), intervals.end());
  
  // Merge
  while(counter < size){

    temp = intervals.at(counter);
    counter++;
    
    while(counter < size &&
	  temp.end >= intervals.at(counter).start){
      
      temp.end = max(temp.end, intervals.at(counter).end);
      counter++;
    }
    result.push_back(temp);
  }
  
  return result;
}
