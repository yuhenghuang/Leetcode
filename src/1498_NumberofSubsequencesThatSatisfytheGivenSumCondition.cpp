#include <local_leetcode.hpp>

class Solution {
  private:
    static constexpr int mod = 1e9 + 7;

    static int i;

    // cache 2 ^ p % mod
    static int exp2[100001];

    int exp2_mod(int p) {
      // lazy evaluation
      if (p >= i) {
        for (; i < p; ++i)
          exp2[i+1] = (exp2[i] << 1) % mod;
      }

      return exp2[p] - 1;
    }

  public:
    int numSubseq(vector<int>& nums, int target) {
      const int n = nums.size();

      sort(nums.begin(), nums.end());

      int res = 0;

      for (int i = 0, j = n; i < n && nums[i] < target && j >= 0; ) {
        int num = nums[i];

        int k = i + 1; // nums[i:k] all == num
        for (; k < n && nums[k] == num; ++k);

        if (num * 2 <= target)
          res += static_cast<int>((
            exp2_mod(i) * // at lease zero elements from nums[:i]
            static_cast<int64_t>(exp2_mod(k - i) - 1) // at lease one elements from nums[i:k]
          ) % mod);
        else {
          j = min(i, j);
          for (; j >= 0 && nums[j] > target - num; --j);

          // found proper min value such that num + min <= target
          if (j >= 0)
            res += static_cast<int>(
              ((static_cast<int64_t>(exp2_mod(j + 1) - 1) * // at least one element from nums[:j+1]
              exp2_mod(i - j - 1) % mod) * // at least zero element from nums[j+1:i]
              (exp2_mod(k - i) - 1)) // at least one element from nums[i:k]
            % mod);
        }

        if (res > mod)
          res -= mod;

        i = k;
      }

      return res;
    }
};


int Solution::i = 0;
int Solution::exp2[] = {1};



int main() {
  EXECS(Solution::numSubseq);
  return 0;
}