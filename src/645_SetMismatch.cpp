#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      
      for (int i=0; i<n; ++i) {
        int j = nums[i] - 1;
        int k = nums[j] - 1;
        while (i != j && j != k) {
          swap(nums[i], nums[j]);
          j = nums[i] - 1;
          k = nums[j] - 1;
        }
      }
      
      for (int i=0; i<n; ++i)
        if (nums[i] != i+1)
          return {nums[i], i+1};
      
      return {-1, -1};
    }


    vector<int> findErrorNumsBit(vector<int>& nums) {
      int n = nums.size();

      int b = 0;
      for (int i = 1; i <= n; ++i)
        b ^= i ^ nums[i - 1];

      // x: repeatition, y: loss, or reverse
      // b = x ^ y

      // rightmost bit of either x or y
      int j = 1 << __builtin_ctz(b); // b & ~(b - 1)

      int x = 0;
      for (int i = 1; i <= n; ++i) {
        if (i & j)
          x ^= i;

        if (nums[i-1] & j)
          x ^= nums[i-1];
      }

      // if x is repeatition
      for (int i = 0; i < n; ++i)
        if (nums[i] == x)
          return {x, b ^ x};

      return {b ^ x, x};
    }
};


int main() {
  EXECS(Solution::findErrorNums);
  EXECS(Solution::findErrorNumsBit);
  return 0;
}
