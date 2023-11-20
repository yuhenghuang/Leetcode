#include <local_leetcode.hpp>

class Solution {
  private:
    int ceil_div(int a, int b) {
      return a / b + (a % b ? 1 : 0);
    }

  public:
    long long minimumReplacement(vector<int>& nums) {
      int64_t res = 0;

      int curr = INT_MAX;
      for (int i = (int) nums.size() - 1; i >= 0; --i) {
        int num = nums[i];

        if (num > curr) {
          int split = ceil_div(num, curr);

          res += split - 1;
          curr = num / split;
        }
        else
          curr = num;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumReplacement);
  return 0;
}