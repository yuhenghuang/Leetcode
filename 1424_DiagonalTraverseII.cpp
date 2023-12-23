#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      typedef pair<int64_t, int> ii_t;

      const int n = nums.size();

      vector<ii_t> vec;
      for (int i = 0; i < n; ++i) {
        const auto& row = nums[i];
        for (int j = 0; j < (int) row.size(); ++j)
          vec.emplace_back(static_cast<int64_t>(i + j + 1) * n - (i + 1) , row[j]);
      }

      sort(
        vec.begin(), vec.end(),
        [] (const ii_t& p, const ii_t& q) { return p.first < q.first; }
      );

      vector<int> res;
      transform(
        vec.begin(), vec.end(),
        back_inserter(res),
        [] (const ii_t& p) { return p.second; }
      );

      return res;
    }
};


int main() {
  EXECS(Solution::findDiagonalOrder);
  return 0;
}