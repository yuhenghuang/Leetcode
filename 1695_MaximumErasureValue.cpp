#include "utils2.hpp"

class Solution {
  public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int n = nums.size();

      vector<int> prefixSum(n+1), prefixIndex(10001);

      int res = 0;

      int idx = 0;
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        int num = nums[i];

        idx = max(idx, prefixIndex[num]);
        sum += num;

        res = max(res, sum - prefixSum[idx]);

        prefixIndex[num] = i + 1;
        prefixSum[i + 1] = sum;
      }

      return res;
    }

    int maximumUniqueSubarrayMemory(vector<int>& nums) {
      int indices[10001];
      memset(indices, -1, sizeof(indices));

      int n = nums.size();

      int res = 0;

      int sum = 0;
      int j = 0;
      for (int i = 0; i < n; ++i) {
        int num = nums[i];

        sum += num;
        for (; j <= indices[num]; ++j)
          sum -= nums[j];

        if (sum > res)
          res = sum;

        indices[num] = i;
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::maximumUniqueSubarrayMemory);
  }
  {
    UFUNC(Solution::maximumUniqueSubarray);
  }

  return 0;
}