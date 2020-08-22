#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) { 
  return (a[0]!=b[0]) ? (a[0]<b[0]) : (a[1]<b[1]); 
}

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), compare);
      
      int n=intervals.size(), res=0;
      vector<int>& curr = intervals[n-1];
      for (int i=n-2; i>=0; --i) {
        if (curr[0]<intervals[i][1])
          ++res;
        else
          curr = intervals[i];
      }
      return res;
    }
};

int main() {
  vector<vector<int>> itv = {{1,2}, {2,3}, {3,4}, {1,3}};
  Solution sol;
  cout << sol.eraseOverlapIntervals(itv) << endl;
  return 0;
}