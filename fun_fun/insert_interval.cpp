/*** 
     https://leetcode.com/problems/insert-interval/#/description
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

vector<Interval> insert(vector<Interval>&, Interval);

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
  
  cin >> s;
  cin >> e;
  Interval interval(s, e);
  
  vector<Interval> result = insert(intervals, interval);

  /*** Print out the result ***/
  for(int i = 0; i < result.size(); i++ ){
    cout << "[" << result.at(i).start << ", " << result.at(i).end << "]" << endl;
    
  }
  
  /*** TODO: Write unit tests  ***/
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){

  int counter = 0;
  int size = intervals.size();
  Interval mergedInterval = newInterval; 
  vector<Interval> result;


  /* Adding left of merged interval */
  while((counter < size) &&
	(intervals.at(counter).end < mergedInterval.start)){
    
    result.push_back(intervals.at(counter));
    counter++;
  }

  /* Merge intervals */
  while((counter < size) &&
	(intervals.at(counter).start <= mergedInterval.end)){
       
    mergedInterval.start = min(intervals.at(counter).start, mergedInterval.start);
    mergedInterval.end = max(intervals.at(counter).end, mergedInterval.end);  
    counter++;
  }
  result.push_back(mergedInterval);

  /* Add right of merged interval */
  while(counter < size){
    result.push_back(intervals.at(counter));
    counter++;
  }
  
  return result;
}
