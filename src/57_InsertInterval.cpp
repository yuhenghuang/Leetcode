#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int i = 0, n = intervals.size();

      vector<vector<int>> res;
      while (i<n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        ++i;
      }
      res.push_back(newInterval);

      for (; i<n; ++i) {
        if (res.back()[1] < intervals[i][0])
          res.push_back(intervals[i]);
        else {
          res.back()[0] = min(res.back()[0], intervals[i][0]);
          res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
      }

      return res;
    }
};