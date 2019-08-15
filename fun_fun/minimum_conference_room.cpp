/*** 
     Given an array of meeting time intervals consisting of start and end times 
     [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
     required.

     For example,
     Given [[0, 30],[5, 10],[15, 20]],
     return 2.
***/

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

bool operator < (Interval a, Interval b){
  return a.start < b.start;
}

int get_minimum_conference_room(vector<Interval>);

int main(){

  // read input from file
  freopen("test.txt", "r", stdin);
  ios::sync_with_stdio(0);

}

int get_minimum_conference_room(vector<Interval> intervals){
  int size = intervals.size();
  int result = 0;
  int current_active_rooms = 0;
  int counter = 0;
  vector<int> starts;
  vector<int> ends;

  // Get starts and ends interval 
  for(auto& e: intervals){
    starts.push_back(e.start);
    ends.push_back(e.end);
  }
  
  if(size == 0) return result;
  
  // Sort intervals based on lower end
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  
  
  for(int i = 0; i < size; i++){

    current_active_rooms++;

    while(counter < size &&
	  ends.at(counter) <= starts.at(i)){
      counter++;
      current_active_rooms--;
    }

    result = max(result, current_active_rooms);
  }

  return result; 
}
