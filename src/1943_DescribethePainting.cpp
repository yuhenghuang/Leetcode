#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
      map<int, long long> treeMap;

      for (auto& seg : segments) {
        treeMap[seg[0]] += seg[2];
        treeMap[seg[1]] -= seg[2];
      }

      long long color = 0;
      vector<vector<long long>> res;

      for (auto& [index, diff] : treeMap) {
        // no need to update at the end of an empty interval
        if (color > 0) 
          res.back()[1] = index;

        color += diff;

        // skip empty interval
        if (color > 0)
          res.push_back({index, 0, color});
      }

      return res;
    }
};


int main() {
  EXECS(Solution::splitPainting);
  return 0;
}