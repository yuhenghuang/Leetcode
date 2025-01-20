#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperations(vector<int>& nums, int x) {
      int n = nums.size();

      int j = n - 1;
      int sum = 0;
      while (j >= 0 && sum < x)
        sum += nums[j--];

      ++j;

      int res = sum == x ? n - j : INT_MAX;

      int i = 0;
      while (j < n) {
        sum -= nums[j++];

        while (i < j && sum < x)
          sum += nums[i++];

        if (sum == x)
          res = min(res, i + n - j);
      }

      return res == INT_MAX ? -1 : res;
    }

    int minOperationsOld(vector<int>& nums, int x) {
      int n = nums.size();

      int i = 0;
      int sum = 0;
      while (i<n && sum<x) 
        sum += nums[i++];

      int res = INT_MAX;
      int j = n-1;
      for (--i; i>=-1; --i) {
        while (j>i && sum<x)
          sum += nums[j--];

        if (sum==x)
          res = min(res, i+n-j);

        if (i>=0)
          sum -= nums[i];
      }

      return res==INT_MAX ? -1 : res;
    }
};


int main() {
  EXECS(Solution::minOperationsOld);
  EXECS(Solution::minOperations);
  return 0;
}