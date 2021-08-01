#include "utils3.hpp"

class Solution {
  public:
    int trap(vector<int>& height) {
      int n = height.size();

      if (n < 3)
        return 0;

      vector<int> dp(n);
      int h = height[0];
      for (int i = 1; i < n - 1; ++i) {
        dp[i] = h;

        if (h < height[i])  
          h = height[i];
      }

      int res = 0;

      h = height[n-1];
      for (int i = n - 2; i > 0; --i) {
        res += max(min(h, dp[i]) - height[i], 0);

        if (h < height[i])
          h = height[i];
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::trap);
  return 0;
}