#include <numeric>
#include "utils3.hpp"

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      int n = nums.size();

      // parent is itself
      vector<int> parent(n);
      iota(parent.begin(), parent.end(), 0);

      // size of divisible set whose largest element's index is at i
      vector<int> dp(n, 1);

      for (int i = 1; i < n; ++i)
        for (int j = i - 1; j >= 0; --j)
          if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            parent[i] = j;
          }

      // p can also be found in the previous outer loop
      int p = max_element(dp.begin(), dp.end()) - dp.begin();

      vector<int> res {nums[p]};
      while (parent[p] != p) {
        p = parent[p];
        res.push_back(nums[p]);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::largestDivisibleSubset);
  return 0;
}