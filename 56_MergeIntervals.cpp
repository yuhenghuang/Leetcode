#include "utils.hpp"
#include <algorithm>

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.size()<2)
        return intervals;

      sort(intervals.begin(), intervals.end(),
           [](const vector<int>& a, const vector<int>& b) -> bool {
             return a[0]==b[0] ? a[1] < b[1] : a[0] < b[0];
           });

      int st = intervals[0][0], ed = intervals[0][1];
      vector<vector<int>> res;
      for (const vector<int>& itv : intervals) {
        if (itv[0] > ed) {
          res.push_back({st, ed});
          st = itv[0], ed = itv[1];
        }
        else {
          ed = max(ed, itv[1]);
        }
      }
      res.push_back({st, ed});

      return res;
    }
};


int main() {
  UFUNC(Solution::merge);
  return 0;
}