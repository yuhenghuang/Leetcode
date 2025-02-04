#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Comparator>
    int longestSubsequence(vector<int> nums, Comparator comp) {
      auto i = nums.begin();
      auto j = i + 1;

      for (int k = 1; k < (int) nums.size(); ++k) {
        auto iter = lower_bound(i, j, nums[k], comp);

        if (iter == j)
          ++j;
        else
          *iter = nums[k];
      }

      return j - i;
    }

    template <class Comparator>
    int longestSubarray(const vector<int>& nums, Comparator comp) {
      int res = 1;

      int cnt = 1;
      for (int i = 1; i < (int) nums.size(); ++i)
        if (comp(nums[i-1], nums[i])) {
          if (++cnt > res)
            res = cnt;
        }
        else
          cnt = 1;

      return res;
    }

  public:
    int longestMonotonicSubarray(vector<int>& nums) {
      return max(
        longestSubarray(nums, less<int>()),
        longestSubarray(nums, greater<int>())
      );
    }
};


int main() {
  EXECS(Solution::longestMonotonicSubarray);
  return 0;
}