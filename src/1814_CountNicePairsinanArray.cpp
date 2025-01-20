#include <local_leetcode.hpp>

class Solution {
  private:
    int rev_diff(int num) {
      static constexpr int decimal[10] {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

      int digits[10];

      int i = 0;
      while (num > 0) {
        digits[i++] = num % 10;
        num /= 10;
      }

      int res = 0;
      for (int j = 0; j < i; ++j)
        res += (digits[i - j - 1] - digits[j]) * decimal[j] ;

      return res;
    }

  public:
    int countNicePairs(vector<int>& nums) {
      constexpr int mod = 1e9 + 7;

      unordered_map<int, int> m; // difference between num and rev(num), frequency;

      for (int i = 0; i < (int) nums.size(); ++i)
        ++m[rev_diff(nums[i])];

      int res = 0;
      for (auto [d, f] : m) {
        res += (int) ((static_cast<int64_t>(f) * (f - 1) >> 1) % mod);

        if (res >= mod)
          res -= mod;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countNicePairs);
  return 0;
}