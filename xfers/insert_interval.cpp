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

  for(int i = 0; i < result.size(); i++ ){
    cout << "[" << result.at(i).start << ", " << result.at(i).end << "]" << endl;
    
  }
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){

  int counter = 0;
  int size = intervals.size();
  Interval mergedInterval = newInterval; 
  vector<Interval> result;

  
  while(counter < size){

    if(intervals.at(counter).start <= mergedInterval.end){

      if(intervals.at(counter).end < mergedInterval.start)
	result.push_back(intervals.at(counter));

      // Construct the new merged interval
      else{
	if(intervals.at(counter).start < mergedInterval.start)
	  mergedInterval.start = intervals.at(counter).start;
	if(intervals.at(counter).end > mergedInterval.end)
	  mergedInterval.end = intervals.at(counter).end;
      }

    }
    else break;
    
    counter++;
  }

  result.push_back(mergedInterval);

  for(int i = counter; i < size; i++){
    result.push_back(intervals.at(i));
  }
  
  return result;
}
