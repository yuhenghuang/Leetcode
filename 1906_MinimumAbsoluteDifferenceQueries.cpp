#include "utils3.hpp"

class Solution {
  public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
      vector<vector<int>> m(101);
      for (int i = 0; i < nums.size(); ++i)
        m[nums[i]].push_back(i);

      vector<int> res;
      res.reserve(queries.size());

      for (auto& q : queries) {
        int prev = -100;
        int diff = 101;
        for (int i = 1; i <= 100; ++i) {
          vector<int>& indicies = m[i];
          auto iter = lower_bound(indicies.begin(), indicies.end(), q[0]);
          if (iter != indicies.end() && *iter <= q[1]) {
            diff = min(diff, i - prev);
            prev = i;
          }
        }

        res.push_back(diff > 100 ? -1 : diff);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::minDifference);
  return 0;
}