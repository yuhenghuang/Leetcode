#include <local_leetcode.hpp>

class Solution {
  public:
    int maxSumMinProduct(vector<int>& nums) {
      typedef pair<int, int> pii;
      static constexpr int64_t mod = 1e9 + 7;

      int n = nums.size();
      vector<int64_t> prefix(n + 1);

      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + nums[i];

      // the maximum minproduct over subarray [num_j..., num_i) where num_i is the minimum value
      // num_i is excluded to avoid duplicate when computing [num_i, ..., num_k)
      vector<int64_t> dp(n);
      
      // num, index
      stack<pii> s;

      s.emplace(INT_MIN, 0);
      for (int i = 0; i < n; ++i) {
        while (s.top().first >= nums[i])
          s.pop();

        dp[i] = nums[i] * (prefix[i] - prefix[s.top().second]);

        s.emplace(nums[i], i + 1);
      }

      // clear monotonic stacck
      while (s.size() > 1)
        s.pop();

      int64_t res = 0;
      for (int i = n - 1; i >= 0; --i) {
        while (s.top().first >= nums[i])
          s.pop();
        
        res = max(
          res,
          dp[i] + nums[i] * (prefix[s.top().second] - prefix[i])
        );

        s.emplace(nums[i], i);
      }

      return res % mod;
    }
};


int main() {
  EXECS(Solution::maxSumMinProduct);
  return 0;
}