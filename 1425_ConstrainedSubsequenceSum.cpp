#include <local_leetcode.hpp>

class Solution {
  public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      deque<pair<int, int>> dq; // index, sum
      dq.emplace_front(-1, 0);

      int res = INT_MIN;
      for (int i = 0; i < (int) nums.size(); ++i) {
        if (dq.front().first < i - k)
          dq.pop_front();

        // subsequence must be non-empty
        int sum = nums[i] + max(dq.front().second, 0);

        if (sum > res)
          res = sum;

        while (!dq.empty() && dq.back().second <= sum)
          dq.pop_back();

        dq.emplace_back(i, sum);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::constrainedSubsetSum);
  return 0;
}