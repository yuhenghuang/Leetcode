#include <local_leetcode.hpp>

class Solution {
  public:
    int totalSteps(vector<int>& nums) {
      int n = nums.size();
      
      // num, steps
      stack<pair<int, int>> s;

      s.emplace(INT_MAX, 0);

      int res = 0;
      for (int i = n - 1; i >= 0; --i) {
        int temp = 0;

        while (nums[i] > s.top().first) {
          temp = max(temp + 1, s.top().second);
          s.pop();
        }

        if (temp > res)
          res = temp;

        s.emplace(nums[i], temp);
      }

      return res;
    }

    int totalStepsWrong(vector<int>& nums) {
      // wrong answer

      int n = nums.size();

      int res = 0;
      int j = 0;
      for (int i = 1; i < n; ++i)
        if (nums[i] >= nums[j]) {
          res = max(res, i - j - 1);
          j = i;
        }

      res = max(res, n - j - 1);

      return res;
    }
};


int main() {
  EXECS(Solution::totalSteps);
  return 0;
}