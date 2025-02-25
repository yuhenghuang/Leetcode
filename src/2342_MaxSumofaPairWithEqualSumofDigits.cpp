#include <local_leetcode.hpp>

class Solution {
  public:
    int maximumSum(vector<int>& nums) {
      int res = -1;

      unordered_map<int, pair<int, int>> m;
      for (int num : nums) {
        int digits_sum = 0;
        for (int temp = num; temp > 0; temp /= 10)
          digits_sum += temp % 10;

        auto& [a, b] = m[digits_sum];

        if (num >= a) {
          b = a;
          a = num;
        }
        else if (num > b)
          b = num;

        if (a > 0 and b > 0 and a + b > res)
          res = a + b;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumSum);
  return 0;
}