#include <numeric>
#include "utils3.hpp"

class Solution {
  private:
    int dfs(int i, const vector<int>& nums, vector<int>& memo) {
      if (memo[i] > 0)
        return memo[i];
      else if (memo[i] < 0)
        return 0;

      memo[i] = -1;

      return memo[i] = 1 + dfs(nums[i], nums, memo);
    }

  public:
    int arrayNesting(vector<int>& nums) {
      int n = nums.size();

      int res = 0;

      vector<int> memo(n);
      for (int i = 0; i < n; ++i)
        if (memo[i] == 0)
          res = max(res, dfs(i, nums, memo));

      return res;
    }
};


int main() {
  UFUNCS(Solution::arrayNesting);
  return 0;
}