#include "utils3.hpp"

class Solution {
  public:
    int waysToSplit(vector<int>& nums) {
      int n = nums.size();

      vector<int> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + nums[i];

      constexpr int mod = 1e9 + 7;
      int res = 0;
      for (int i = 1; i < n - 1; ++i) {
        int j = prefix[i] * 2;
        int k = (prefix[i] + prefix.back())  / 2;
        if (j <= k) {
          res += max(
            // **non-empty** subarrays!
            // be careful of the range of binary search
            upper_bound(prefix.begin() + i + 1, prefix.end() - 1, k) - lower_bound(prefix.begin() + i + 1, prefix.end() - 1, j), 
            0L
          );

          if (res > mod)
            res -= mod;
        }
        else
          break;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::waysToSplit);
  return 0;
}