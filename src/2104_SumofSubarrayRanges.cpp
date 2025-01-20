#include <local_leetcode.hpp>

class Solution {
  public:
    long long subArrayRanges(vector<int>& nums) {
      int n = nums.size();

      typedef pair<long, int> pii_t;

      // (num, index)
      stack<pii_t> min_stack;
      stack<pii_t> max_stack;

      min_stack.emplace(INT_MIN, -1);
      max_stack.emplace(INT_MAX, -1);

      // sum of min(nums[0], ... nums[j]) over j = 0, ..., i
      long long min_sum = 0;
      long long max_sum = 0;

      long long res = 0;
      for (int i = 0; i < n; ++i) {
        while (nums[i] >= max_stack.top().first) {
          auto [num, j] = max_stack.top();
          max_stack.pop();

          max_sum -= (j - max_stack.top().second) * num;
        }

        max_sum += (i - max_stack.top().second) * (long)nums[i];
        max_stack.emplace(nums[i], i);

        while (nums[i] <= min_stack.top().first) {
          auto [num, j] = min_stack.top();
          min_stack.pop();

          min_sum -= (j - min_stack.top().second) * num;
        }

        min_sum += (i - min_stack.top().second) * (long)nums[i];
        min_stack.emplace(nums[i], i);

        res += max_sum - min_sum;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::subArrayRanges);
  return 0;
}