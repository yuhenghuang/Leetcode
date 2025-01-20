#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      const int n = nums.size();

      int total = reduce(nums.begin(), nums.end());

      vector<int> res(n);
      for (int i = 0, left = 0; i < n; ++i) {
        int num = nums[i];

        // res[i] = num * i - left + (total - left) - num * (n - i);
        res[i] = total - 2 * left - num * (n - 2 * i);

        left += num;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::getSumAbsoluteDifferences);
  return 0;
}